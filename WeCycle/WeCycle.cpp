// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 


int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop

	DataManager dataManager(filename);

	Account acc("jkim@tablecom", "passwordE");
	dataManager.pushData(acc, "Accounts");

	system("pause");
	return 0;
}