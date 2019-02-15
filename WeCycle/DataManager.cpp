#include "DataManager.h"
#include <iostream>
#include <fstream> 
#include <firebase\app.h>
#include <firebase\variant.h>

DataManager::DataManager(const char* filename) {
	//Initializing firebase app
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON(filename, appOps);
	firebase::App *app = firebase::App::Create(appOptions);

	//Initializing firebase database and reference
	database = firebase::database::Database::GetInstance(app);
	dbref = database->GetReference();

	std::cout << "Data manager successfully built" << std::endl;
}

std::map<std::string, std::string> DataManager::parseJSONfromFile(const char* filename) {
	std::map<std::string, std::string> result;
	std::ifstream ifs(filename);
	nlohmann::json j;
	ifs >> j;
	try { 
		result["api_key"] = j["client"][0]["api_key"][0].value("current_key", "NULL"); 
		result["app_id"] = j["client"][0]["client_info"].value("mobilesdk_app_id", "NULL");
		result["database_url"] = j.at("project_info").value("firebase_url", "NULL");
		result["project_id"] = j.at("project_info").value("project_id", "NULL");
		result["storage_bucket"] = j.at("project_info").value("storage_bucket", "NULL");
	}
	catch (nlohmann::json::out_of_range &e) {
		std::cout << e.what();
	}
	catch (nlohmann::json::type_error &te) {
		std::cout << te.what();
	}
	return result;
}

void DataManager::loadFirebaseJSON(const char * filename, firebase::AppOptions *appOptions) {

	std::map<std::string, std::string> jsonMap = DataManager::parseJSONfromFile(filename);
	for (auto const& item : jsonMap) {
		std::string key = item.first;
		std::string value = item.second;
		
		if (key == "api_key") {
			appOptions->set_api_key(value.c_str());
		}
		else if (key == "app_id") {
			appOptions->set_app_id(value.c_str());
		}
		else if (key == "database_url") {
			appOptions->set_database_url(value.c_str());
		}
		else if (key == "project_id") {
			appOptions->set_project_id(value.c_str());
		}
		else if (key == "storage_bucket") {
			appOptions->set_storage_bucket(value.c_str());
		}
		else {
			return;
		}

	}
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref; 
}

void DataManager::writeOrUpdateData(PushableObject objectToPass) {

	//TODO: Firebase doesnt push maps need to fix

	std::string key = dbref.Child("Accounts").PushChild().key_string();
	objectToPass.setKey(key);
	std::map<std::string, std::map<std::string, std::string>> entryValues = objectToPass.toMap();
	
	std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> childUpdates;
	childUpdates["/Accounts/" + key] = entryValues;

	dbref.UpdateChildren(entryValues);
	std::cout << "Push Successful" << std::endl; //Allow this test by getting data
}

//Called at the object's termination
DataManager::~DataManager() {
	delete database;
}
