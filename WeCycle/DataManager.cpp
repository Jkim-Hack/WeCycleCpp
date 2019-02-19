#include "DataManager.h"
#include <iostream>
#include <firebase\app.h>
#include <firebase\variant.h>

DataManager::DataManager(FirebaseManager fbManager) {
	//Initializing firebase database and reference
	database = firebase::database::Database::GetInstance(fbManager.getApp());
	dbref = database->GetReference();

	bool checkIfBuiltCorrectly;//TODO: Check if the data manager is successfully built
	std::cout << "Data manager successfully built" << std::endl;
}

//Called at the object's termination
DataManager::~DataManager() {
	delete database;
}

void DataManager::pushData(PushableObject objectToPass, std::string parent) {

	std::string key = dbref.Child(parent).PushChild().key_string();
	objectToPass.setKey(key);
	//Accounts: multiple for loops that access each data point.
	//TODO: Make variables cleaner with actual types - RAGHAV DO THIS
	for (auto &x : objectToPass.dataMap()) {
		if (x.second.vector().size() > 0) {
			for (auto &y : x.second.vector()) {
				for (auto &z : y.map()) {
					std::string key2 = z.first.string_value();
					dbref.Child(parent).Child(x.first).Child(key2).SetValue(z.second);
				}
			}
		}
		else {
			dbref.Child(parent).Child(x.first).SetValue(x.second);
		}
	}

	std::cout << "Push Successful" << std::endl; //TODO: LOOK AT FIREBASE DOCUMENTATION FOR CHECKING
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref;
}

