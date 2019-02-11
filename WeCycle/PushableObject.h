#pragma once
#include <iostream>
#include <map>
class PushableObject
{
private:
	std::string objKey;

public:
	PushableObject();
	virtual std::map<std::string, std::map<std::string, std::string>> toMap();
	//TODO: Think of more ways that a pushable object MUST have

	std::string getKey();
	void setKey(std::string key);
	~PushableObject();
};

