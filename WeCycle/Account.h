#pragma once
#include <iostream>
#include "DataManager.h"

class Account
{
private:
	std::string username;
	std::string password;
	std::string emailAddress;
public:
	Account(std::string username, std::string password);
	Account(std::string username, std::string password, std::string emailAddress);

	std::map<std::string, std::map<std::string, std::string>> toMap();
	virtual ~Account();
};

