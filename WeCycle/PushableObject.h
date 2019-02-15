#pragma once
#include <iostream>
#include <map>
#include <firebase\variant.h>

class PushableObject : std::map<std::string, firebase::Variant>
{
private:
	std::string objKey;

public:
	PushableObject();
	std::map<std::string, firebase::Variant> toMap();
	//TODO: Think of more ways that a pushable object MUST have

	std::string getKey();
	void setKey(std::string key);
	~PushableObject();
};

