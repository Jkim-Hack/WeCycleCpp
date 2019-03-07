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
#include "Authentication.h"

using stringMap = std::map<std::string, firebase::Variant>;

int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop


	FirebaseManager *fbManager = new FirebaseManager(filename);
	DataManager dataManager(fbManager);
	StorageManager storageManager(fbManager);
	Account acc("Raghav@droptable.com", "passwordE");
	PushableObject object();

	stringMap map;
	map.insert(std::pair<std::string, std::string>("salt0", "m4rk4ss"));
	stringMap map2;
	map2.insert(std::pair<std::string, std::string>("salt1", "br0wnl33"));

	PushableObject *push = new PushableObject();
	push->initialize(map);
	PushableObject *push1 = new PushableObject();
	push->initialize(map2);
	dataManager.pushData(push, "s4lT");
	dataManager.pushData(push1, "s4lT");

	//Authentication auth(fbManager);
	//auth.createAndRegisterAccount(acc);

	//const std::string link = storageManager.uploadImageRetreiveLink("C:/Users/Kim/Desktop/image.jpg");
	//std::cout << link << std::endl;

	//const char **dataRetrived = dataManager.retrieveData("Accounts", "C@droptablecom");

	//for (size_t i = 0; i < 2; i++)
	//{
	//	std::cout << dataRetrived[i] << std::endl;
	//}

	system("pause");

	return 0;
}
