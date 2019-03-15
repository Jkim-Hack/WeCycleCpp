#include "DataManager.h"
#include <iostream>
#include <firebase/app.h>
#include <firebase/variant.h>
#include <ctime>

//TODO: ADD AUTHENTICATION TO FIREBASE


DataManager::DataManager(FirebaseManager *fbManager) {
	//Initializing firebase database and reference
	database = firebase::database::Database::GetInstance(fbManager->getApp());
	dbref = database->GetReference();

	bool checkIfBuiltCorrectly;//TODO: Check if the data manager is successfully built
	std::cout << "Data manager successfully built" << std::endl;
}

//Called at the object's termination
DataManager::~DataManager() {
	//delete database;
}

void DataManager::pushData(PushableObject *objectToPass, std::string parent) {
	
	for (auto &x : objectToPass->dataMap()) {
		firebase::Variant firstKey = x.first;
		if (x.second.is_vector()) {
			std::string firstK = firstKey.mutable_string();
			firebase::Future<void> future = dbref.Child(parent).Child(firstK).SetValue(x.second);
			while (future.status() != firebase::kFutureStatusComplete){}
			if (future.error() == 0) {
				std::cout << "Push Successful" << std::endl;
			}
			else {
				std::cout << "Push Failed" << future.error_message() <<std::endl;
			}
		}
		else {
			firebase::Variant value = x.second;
			firebase::Future<void> future = dbref.Child(parent).Child(firstKey.mutable_string()).SetValue(value);
			while (future.status() != firebase::kFutureStatusComplete) {}
			if (future.error() == 0) {
				std::cout << "Push Successful" << std::endl;
			}
			else {
				std::cout << "Push Failed" << future.error_message() << std::endl;
			}
		}
	}

}

void DataManager::pushData(PushableObject *objectToPass, std::string parent, std::string child) {

	for (auto &x : objectToPass->dataMap()) {
		firebase::Variant firstKey = child;
		if (x.second.is_vector()) {
			std::string firstK = firstKey.mutable_string();
			firebase::Future<void> future = dbref.Child(parent).Child(firstK).SetValue(x.second);
			while (future.status() != firebase::kFutureStatusComplete) {}
			if (future.error() == 0) {
				std::cout << "Push Successful" << std::endl;
			}
			else {
				std::cout << "Push Failed" << future.error_message() << std::endl;
			}
		}
		else {
			firebase::Variant value = x.second;
			firebase::Future<void> future = dbref.Child(parent).Child(firstKey.mutable_string()).SetValue(value);
			while (future.status() != firebase::kFutureStatusComplete) {}
			if (future.error() == 0) {
				std::cout << "Push Successful" << std::endl;
			}
			else {
				std::cout << "Push Failed" << future.error_message() << std::endl;
			}
		}
	}

}

void DataManager::updateData(firebase::Variant objectToPass, std::string parent, std::string child) {//Object isnt of type map

}
void DataManager::updateData(firebase::Variant objectToPass, std::string parent) { //Object isnt of type map

}
void DataManager::updateData(firebase::Variant objectToPass) { //Object is of type map
	firebase::Future<void> future = dbref.UpdateChildren(objectToPass);
	while (future.status() != firebase::kFutureStatusComplete) {}
	if (future.error() == 0) {
		printf("Updated!");
	}
	else {
		printf("Failed to update: ");
		printf(future.error_message());
	}
}

const char **DataManager::retrieveData(std::string parent, std::string key) {

	const char **resultArray = nullptr;

	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).Child(key).GetValue();

		while (result.status() != firebase::kFutureStatusComplete) {} //Loop to wait until retrieval is complete
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;

			std::vector<firebase::database::DataSnapshot> childList = result.result()->children();

			unsigned int heightMax = childList.size();
			resultArray = new const char*[heightMax];

			int counter = 0;
			for (auto &values : childList) { //Iterate through the vector of STRING VALUE
				resultArray[counter] = strdup(values.value().string_value());  //strdup makes sure our char in the memory stays in the memory even when out of scope by creating a duplicate char array (string
				counter++;
			}
		} 
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}

	return resultArray;
}

const char **DataManager::retrieveData(std::string parent) {

	const char **resultArray = nullptr;

	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).GetValue();

	while (result.status() != firebase::kFutureStatusComplete) {} //Loop to wait until retrieval is complete
	if (result.error() == firebase::database::kErrorNone) {
		std::cout << "Retrival Complete" << std::endl;

		std::vector<firebase::database::DataSnapshot> childList = result.result()->children();

		unsigned int heightMax = childList.size();
		resultArray = new const char*[heightMax];

		int counter = 0;
		for (auto &values : childList) { //Iterate through the vector of STRING VALUE
			resultArray[counter] = strdup(values.value().string_value());  //strdup makes sure our char in the memory stays in the memory even when out of scope by creating a duplicate char array (string
			counter++;
		}
	}
	else {
		std::cout << "Error Retrieving Data" << std::endl;
	}

	return resultArray;
}

void DataManager::retrieveData(std::string parent, firebase::Variant &object) {

	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).GetValue();

	while (result.status() != firebase::kFutureStatusComplete) {} //Loop to wait until retrieval is complete //TODO add a runtime exception
	if (result.error() == firebase::database::kErrorNone) {
		std::cout << "Retrival Complete" << std::endl;

		std::vector<firebase::database::DataSnapshot> childList = result.result()->children();
		std::vector<firebase::Variant> variantList;
		int counter = 0;
		for (auto &values : childList) { //Iterate through the vector of STRING VALUE
			firebase::Variant value = values.value();
			if (value.is_mutable_string()) {
				variantList[counter] = value.mutable_string();
			}
			else if (value.is_int64()) {
				variantList[counter] = value.int64_value();
			}
			else if (value.is_bool()) {
				variantList[counter] = value.bool_value();
			}
			counter++;
		}
		object = variantList;
	}
	else {
		std::cout << "Error Retrieving Data" << std::endl;
	}
}

void DataManager::retrieveData(std::string parent, std::string key, firebase::Variant &object) {

	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).Child(key).GetValue();

	//while (result.status() != firebase::kFutureStatusComplete) {} //Loop to wait until retrieval is complete

	firebase::Variant *ob = &object;

	result.OnCompletion([](const firebase::Future<firebase::database::DataSnapshot>& result, void* user_data) {
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;
			firebase::Variant childList = result.result()->value();
			firebase::Variant ob = static_cast<firebase::Variant*>(user_data);
			if (childList.is_vector()) {
				ob = childList.vector();
			}
		}
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}
	}, ob);
#ifdef _WIN32
	std::clock_t start;
	double duration = 0;
	start = std::clock();
	while (duration != 5000) {
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		if (result.result_void() != nullptr) {
			return;
		}
	}
#endif // _WIN32
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref;
}

