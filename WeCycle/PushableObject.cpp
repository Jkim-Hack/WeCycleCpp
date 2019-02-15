#include "PushableObject.h"



PushableObject::PushableObject()
{

}

std::map<std::string, firebase::Variant> PushableObject::toMap() {
	std::map<std::string, firebase::Variant> map;
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

