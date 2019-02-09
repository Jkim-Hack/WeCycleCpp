#pragma once
#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"

class Account : public PushableObject
{
private:
	int phoneNum;
	std::string username;
	std::string password;
	std::string emailAddress;
public:
	Account(std::string username, std::string password, int phoneNum);
	Account(std::string username, std::string password, std::string emailAddress, int phoneNum);

	std::map<std::string, std::map<std::string, std::string>> toMap();
	virtual ~Account();
};

