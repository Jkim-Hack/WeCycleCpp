// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include <iostream>
#include "Account.h"


int main() {

	const char *filename = "google-services.json";

	DataManager dtmnger(filename);

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



	std::cout << user + ", " + pass + ", " + email;
	system("pause");
	return 0;
}