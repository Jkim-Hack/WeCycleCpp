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

std::string **DataManager::retrieveData(std::string parent, std::string key) {
	//Needs to be 2d array so we can correctly keep the map and key values together
	std::string **resultArray = nullptr;

	firebase::Variant *resultValuePtr = nullptr;

	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).Child(key).GetValue();

		while (result.status() != firebase::kFutureStatusComplete) {} //Loop to wait until retrieval is complete
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;
			std::vector<firebase::database::DataSnapshot> childList = result.result()->children();
			resultArray = new std::string*[childList.size]; //Initialize height/how many children in the list

			int height = 0; //Counter for the height
			for (auto &map : childList) { //Iterate through the vector
				resultArray[height] = new std::string[2]; //Another array for keys and values
				for (auto &values : map.value().map()) { //Iterate through the map
					resultArray[height][0] = values.first.string_value; //Key
					resultArray[height][1] = values.second.string_value; //Value
				}
				height++;
			}
		} 
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}

	return resultArray;
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref;
}

