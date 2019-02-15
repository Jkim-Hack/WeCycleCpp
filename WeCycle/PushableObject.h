#pragma once
#include <iostream>
#include <map>
#include <firebase\variant.h>

class PushableObject : public std::map<std::string, firebase::Variant>
{
private:
	std::string objKey;

public:
	PushableObject();
	~PushableObject();

	void initialize(std::map<std::string, firebase::Variant> map); //Creates a new map and replaces original
	void addData(std::string key, firebase::Variant value); //Adds data to existing map
	//TODO: Think of more ways that a pushable object MUST have
	std::string getKey();
	void setKey(std::string key);
};

