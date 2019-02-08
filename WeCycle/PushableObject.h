#pragma once
#include <iostream>
#include <map>
class PushableObject
{
public:
	PushableObject();
	virtual ~PushableObject();
	virtual std::map<std::string, std::map<std::string, std::string>> toMap() = 0;
	//TODO: Think of more ways that a pushable object MUST have
};

