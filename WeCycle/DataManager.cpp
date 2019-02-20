#include "DataManager.h"
#include <iostream>
#include <firebase\app.h>
#include <firebase\variant.h>

//TODO: ADD AUTHENTICATION TO FIREBASE


DataManager::DataManager(FirebaseManager &fbManager) {
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
	for (auto &x : objectToPass.dataMap()) {
		std::string firstKey = x.first;
		if (x.second.vector().size() > 0) {
			for (auto &y : x.second.vector()) {
				for (auto &z : y.map()) {
					std::string keys = z.first.string_value();
					firebase::Variant values = z.second;
					dbref.Child(parent).Child(firstKey).Child(keys).SetValue(values);
				}
			}
		}
		else {
			firebase::Variant value = x.second;
			dbref.Child(parent).Child(firstKey).SetValue(value);
		}
	}

	std::cout << "Push Successful" << std::endl; //TODO: LOOK AT FIREBASE DOCUMENTATION FOR CHECKING
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref;
}

