#include "DataManager.h"
#include <iostream>
#include <fstream> 
#include <firebase\app.h>

DataManager::DataManager(const char* filename) {
	//Initializing firebase app
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON(filename, appOps);
	std::cout << filename;
	firebase::App *app = firebase::App::Create(appOptions);

	//Initializing firebase database and reference
	database = firebase::database::Database::GetInstance(app);
	dbref = database->GetReference();

	std::cout << "Data manager successfully built";
}

std::map<const char*, const char*> DataManager::parseJSONfromFile(const char* filename) {
	std::map<const char*, const char*> result;
	std::ifstream ifs(filename);
	nlohmann::json j;
	ifs >> j;
	try { //TODO: FIX THIS PART
		result["api_key"] = j["client"][0]["api_key"][0].value("current_key", "NULL").c_str(); //c.str() prints out 'YYYYYYYYYYYYYYY' we dont want this.
		result["app_id"] = j["client"][0]["client_info"].value("mobilesdk_app_id", "NULL").c_str();
		result["database_url"] = j.at("project_info").value("firebase_url", "NULL").c_str();
		result["project_id"] = j.at("project_info").value("project_id", "NULL").c_str();
		result["storage_bucket"] = j.at("project_info").value("storage_bucket", "NULL").c_str();
	}
	catch (nlohmann::json::type_error &e) {
		std::cout << e.what();
	}
	return result;
}

void DataManager::loadFirebaseJSON(const char * filename, firebase::AppOptions *appOptions) {

	std::map<const char*, const char*> jsonMap = DataManager::parseJSONfromFile(filename);
	for (auto const& item : jsonMap) {
		const char *key = item.first;
		const char *value = item.second;
		
		if (key == "api_key") {
			appOptions->set_api_key(value);
		}
		else if (key == "app_id") {
			appOptions->set_app_id(value);
		}
		else if (key == "database_url") {
			std::cout << value;
			appOptions->set_database_url(value);
		}
		else if (key == "project_id") {
			appOptions->set_project_id(value);
		}
		else if (key == "storage_bucket") {
			appOptions->set_storage_bucket(value);
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
	std::string key = dbref.Child("accounts").PushChild().key();
	objectToPass.setKey(key);
	std::map<std::string, std::map<std::string, std::string>> entryValues = objectToPass.toMap();
	
	std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> childUpdates;
	childUpdates["/accounts/" + key] = entryValues;
	
	dbref.UpdateChildren(childUpdates);

}

//Called at the object's termination
DataManager::~DataManager() {
	delete database;
}
