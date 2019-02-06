#include "DataManager.h"
#include <iostream>
#include <firebase\app.h>



DataManager::DataManager(char* filename) {
	//Initializing firebase app
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON(filename, appOps);
	firebase::App *app = firebase::App::Create(appOptions);

	//Initializing firebase database and reference
	database = firebase::database::Database::GetInstance(app);
	dbref = database->GetReference();
}


void DataManager::loadFirebaseJSON(char * filename, firebase::AppOptions *appOptions) {
	appOptions->LoadFromJsonConfig(filename);
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref; 
}

//Called at the object's termination
DataManager::~DataManager() {
	delete database;
}
