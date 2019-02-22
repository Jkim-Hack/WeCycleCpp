#include "PushableObjectWrapper.hpp"
#include "PushableObject.h"
#include <firebase\variant.h>

const void *initialize() {
	PushableObject *pushableObject = new PushableObject();
	return (void *)pushableObject;
}

void addData(const void *object, const char *key, const char *mapKey, const char *mapValue) {
	PushableObject *pushableObject = (PushableObject *)object;
	std::map<std::string, std::string> map;
	map[mapKey] = mapValue;
	pushableObject->addData(key,map);
}

