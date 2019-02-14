// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 


int main() {

	//const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop

	DataManager dataManager(filename);

	Account acc("Jkim", "FFFFF", "HHHH");
	std::map<std::string, std::map<std::string, std::string>> map = acc.toMap();

	dataManager.writeOrUpdateData(acc);

	system("pause");
	return 0;
}