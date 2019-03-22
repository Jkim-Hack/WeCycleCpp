#include "UID.h"

UID::UID(DataManager *dbm) {
	this->dbManage = dbm;
}

void UID::updateUID(std::string id) {
	uid = id;
}
std::string findAndRemovePeriod1(std::string inp) {
	std::string input = inp;
	std::size_t index = input.find(".");
	input.erase(input.begin() + index);
	return input;
}
void UID::registerListener(const char* email) {
	EmailValueListener *listener = new EmailValueListener(this);
	std::string emailO = findAndRemovePeriod1(email);
	this->dbManage->getDBref().Child("Emails").Child(emailO).AddValueListener(listener);
}

const char *UID::getUID() {
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	const char *result = strdup(uid.c_str());
	return result;
}
