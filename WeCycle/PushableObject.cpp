#include "PushableObject.h"



PushableObject::PushableObject()
{
	
}

std::map<std::string, std::map<std::string, std::string>> PushableObject::toMap() {
	std::map<std::string, std::map<std::string, std::string>> map;
	return map;
}

std::string PushableObject::getKey() {
	return objKey;
}

void PushableObject::setKey(std::string key) {
	objKey = key;
}



PushableObject::~PushableObject()
{
}

