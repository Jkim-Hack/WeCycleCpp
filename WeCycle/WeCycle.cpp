// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 


int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json";

	DataManager dataManager(filename);

	Account acc("Jkim", "Hack", "E");

	std::map<std::string, std::map<std::string, std::string>> map = acc.toMap();

	std::map<std::string, std::map<std::string, std::string>>::iterator it = map.begin();
	std::string user;
	std::string pass;
	std::string email;

	user = it->first;
	std::map<std::string, std::string> subMap = it->second;

	std::map<std::string, std::string>::iterator it2 = subMap.begin();
	pass = it2->first;
	email = it2->second;



	std::cout << user + ", " + pass + ", " + email << std::endl;
	system("pause");
	return 0;
}