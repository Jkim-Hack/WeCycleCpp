// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 


int main() {

	//const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json";
	const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle";

	std::ifstream ifs(filename);
	nlohmann::json j;
	ifs >> j;

	try { 

		const char * string = j["client"][0]["api_key"][0].value("current_key", "NULL").c_str();
		std::cout << string;

	}
	catch (nlohmann::json::type_error &e) {
		std::cout << e.what();
	}

	//DataManager dtmnger(filename);

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