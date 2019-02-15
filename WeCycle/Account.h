#pragma once
#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"

class Account : public PushableObject
{
private:
	std::string emailAddress;
	std::string password;
	long phoneNumber;
public:
	Account(std::string emailAddress, std::string password);
	Account(std::string emailAddress, std::string password, long phoneNumber);

	~Account();
};

