#include "Account.h"

Account::Account(std::string emailAddress, std::string password) {
	this->emailAddress = emailAddress;
	this->password = password;

	std::map<std::string, firebase::Variant> map; 
	map.insert(std::pair<std::string, firebase::Variant>(this->emailAddress, firebase::Variant(this->password)));
	this->initialize(map);

}
Account::Account(std::string emailAddress, std::string password, long phoneNumber) {
	this->emailAddress = emailAddress;
	this->password = password;
	this->phoneNumber = phoneNumber;

	std::map<std::string, firebase::Variant> accountMap;

	std::map<long, std::string> phonePassMap;
	phonePassMap.insert(std::pair<long, std::string>(this->phoneNumber, this->password));

	accountMap.insert(std::pair<std::string, firebase::Variant>(this->emailAddress, firebase::Variant(phonePassMap)));
	this->initialize(accountMap);

}

Account::~Account() {
}


