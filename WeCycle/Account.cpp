#include "Account.h"


Account::Account(std::string username, std::string password) {
	this->username = username;
	this->password = password;
}

Account::Account(std::string username, std::string password, std::string emailAddress) {
	this->username = username;
	this->password = password;
	this->emailAddress = emailAddress;
}

std::map<std::string, std::map<std::string, std::string>> Account::toMap() {
	std::map<std::string, std::string> emailPass;
	emailPass[this->emailAddress] = this->password;

	std::map<std::string, std::map<std::string, std::string>> result;
	result[this->username] = emailPass;
	
	return result;
}


Account::~Account() {
	
}
