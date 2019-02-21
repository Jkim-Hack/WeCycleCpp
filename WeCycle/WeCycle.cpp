// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include "StorageManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 

using stringMap = std::map<std::string, std::string>;

int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop


	FirebaseManager fbManager(filename);
	DataManager dataManager(fbManager);
	StorageManager storageManager(fbManager);
	Account acc("jkim@droptablecom", "passwordE");
	dataManager.pushData(acc, "Accounts");

	const std::string link = storageManager.uploadImageRetreiveLink("C:/Users/Kim/Desktop/image.jpg");
	std::cout << link << std::endl;

	stringMap dataRetrived = dataManager.retrieveData("Accounts", "jkim@droptablecom");

	for (auto &x : dataRetrived) {
		std::cout << x.first << ", " << x.second << std::endl;
	}

	system("pause");

	return 0;
}