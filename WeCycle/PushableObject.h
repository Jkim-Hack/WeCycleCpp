#pragma once
#include <iostream>
#include <map>
#include <firebase\variant.h>

using stringMap = std::map<std::string, std::string>;

class PushableObject
{
private:
	std::string objKey;
	std::map<std::string, firebase::Variant> pushableData;
public:
	PushableObject();
	~PushableObject();

	virtual void initialize(std::map<std::string, firebase::Variant> &map); //Creates a new map and replaces original
	virtual void addData(std::string key, stringMap value); //Adds data to existing map

	//TODO: Think of more ways that a pushable object MUST have
	std::string getKey();
	void setKey(std::string key);

	virtual std::map<std::string, firebase::Variant> dataMap(); //Final data product
};

