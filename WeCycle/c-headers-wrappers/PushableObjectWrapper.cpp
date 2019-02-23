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

void initializeMap(const void *object, const char *keyMap, const char *keyValue) {
	PushableObject *pushableObject = (PushableObject *)object;
	firebase::Variant keyValueVariant(keyValue);
	std::map<std::string, firebase::Variant> map;
	map[keyMap] = keyValueVariant;
	pushableObject->initialize(map);
}

void initializeMap(const void *object, const char *keyMap, const char *keyValue, const char *keyValue2) {
	PushableObject *pushableObject = (PushableObject *)object;
	std::map<std::string, std::string> valueMap(keyValue, keyValue2);
	firebase::Variant keyValueVariant(valueMap);
	std::map<std::string, firebase::Variant> map;
	map[keyMap] = keyValueVariant;
	pushableObject->initialize(map);
}
