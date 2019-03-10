#pragma once
#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"
#include "Rank.h"

using stringMap = std::map<std::string, std::string>;
using uIntMap = std::map<std::string, unsigned int>;
using VariantMap = std::map<std::string, firebase::Variant>;


class Account : public PushableObject
{
private:

	std::string uid;
	long phoneNumber;
	std::string rank;
	int experience;
	int coins;
	std::string profilePicLink;
	std::vector<std::map<std::string, firebase::Variant>> dataList;

	bool checkXPforRank(DataManager *dbm);

public:

	Account(std::string uid);
	Account(std::string rank, unsigned int experience, unsigned int coins, std::string profilePicLink, std::string uid);
	
	//TODO add intialize override function and addData function

	~Account();

	void updateRank(DataManager *dbm);
	void updateXP(int increment, DataManager *dbm);
	void updateCoins(int incremenet, DataManager *dbm);
	void updatePFP(std::string link, DataManager *dbm);
};

