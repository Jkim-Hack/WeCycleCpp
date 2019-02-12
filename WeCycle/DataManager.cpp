#include "DataManager.h"
#include <iostream>
#include <fstream> 
#include <firebase\app.h>

using json = nlohmann::json;

DataManager::DataManager(const char* filename) {
	//Initializing firebase app
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON(filename, appOps);
	std::cout << appOptions.api_key();
	firebase::App *app = firebase::App::Create(appOptions);

	
	//Initializing firebase database and reference
	database = firebase::database::Database::GetInstance(app);
	dbref = database->GetReference();
}

std::string DataManager::parseJSONfromFile(const char* filename) { //TODO: GET THE JsonCpp package through CMake and use a JSON Parser

	std::ifstream ifs(filename);
	json j;
	ifs >> j;
	std::string returnVal = j.dump();

	return returnVal;
}

void DataManager::loadFirebaseJSON(const char * filename, firebase::AppOptions *appOptions) {
	appOptions->LoadFromJsonConfig(filename);
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
