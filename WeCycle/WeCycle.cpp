// WeCycle.cpp : Defines the entry point for the application.
//
#ifdef _WIN32

#include "WeCycle.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include "StorageManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 
#include "Authentication.h"
#include "Crypto.h"

//using stringMap = std::map<std::string, firebase::Variant>;

int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop


	FirebaseManager *fbManager = new FirebaseManager(filename);
	DataManager *dataManager = new DataManager(fbManager);
	//StorageManager storageManager(fbManager);

	Authentication auth(fbManager, dataManager);
	Account acc(dataManager);
	auth.signInUser(&acc, "jkim@gmail.com", "password");
	auth.updateUserProfile(&acc, "https://firebasestorage.googleapis.com/v0/b/wecycle-316c1.appspot.com/o/Gial_Ackbar_Resistance.jpg?alt=media&token=1059357a-f84f-4185-a798-7f6c7b730778"
	,"tester");

	delete fbManager;
	delete dataManager;

	system("pause");

	return 0;
}
#endif // _WIN32