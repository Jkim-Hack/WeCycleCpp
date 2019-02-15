#include "PushableObject.h"



PushableObject::PushableObject()
{
}

PushableObject::~PushableObject()
{
}

void PushableObject::initialize(std::map<std::string, firebase::Variant> map) {
	this->clear();
	for (auto const& item : map) {
		this->insert(std::pair<std::string, firebase::Variant>(item.first, item.second));
	}
}
void PushableObject::addData(std::string key, firebase::Variant value) {
	this->insert(std::pair<std::string, firebase::Variant>(key, value));
}

std::string PushableObject::getKey() {
	return objKey;
}

void PushableObject::setKey(std::string key) {
	objKey = key;
}


