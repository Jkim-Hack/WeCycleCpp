#include "Account.h"


Account::Account(std::string username, std::string password, int phoneNum) {
	this->username = username;
	this->password = password;
	this->phoneNum = phoneNum;
}

Account::Account(std::string username, std::string password, std::string emailAddress, int phoneNum) {
	this->username = username;
	this->password = password;
	this->phoneNum = phoneNum;
	this->emailAddress = emailAddress;
}

std::map<std::string, std::map<std::string, std::string>> Account::toMap() {
	std::map<std::string, std::string> emailPass;
	emailPass[this->emailAddress] = this->password;

	std::map<int, int> numPass;
	numPass[this->phoneNum];
	//I'm not sure about this line I'm just experimenting^^^

	std::map<std::string, std::map<std::string, std::string>> result;
	result[this->username] = emailPass;
	3
	return result;
}




Account::~Account() {

}
