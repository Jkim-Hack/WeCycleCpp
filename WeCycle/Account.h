#pragma once
#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"


using stringMap = std::map<std::string, std::string>;
using uIntMap = std::map<std::string, unsigned int>;
using VariantMap = std::map<firebase::Variant, firebase::Variant>;


class Account : public PushableObject
{
private:

	std::string uid;
	long phoneNumber;
	std::string rank;
	int experience;
	int coins;
	std::string profilePicLink;
	std::string display_name;
	std::vector<std::map<firebase::Variant, firebase::Variant>> dataList;

	bool checkXPforRank(DataManager *dbm);

public:
	Account();
	Account(std::string uid);
	Account(std::string rank, unsigned int experience, unsigned int coins, std::string profilePicLink, std::string uid);
	Account(std::vector<firebase::Variant> dataList, std::string uid);
	//TODO add intialize override function and addData function

	~Account();

	const char* rankA() const;
	int experienceA() const;
	int coinsA() const;
	const char* profilePicLinkA() const;

	void updateRank(DataManager *dbm);
	void updateXP(int increment, DataManager *dbm);
	void updateCoins(int incremenet, DataManager *dbm);
	void updatePFP(std::string link, DataManager *dbm);

	void updateProfile(std::string displayName, std::string pfpLink, DataManager *dbm);
};
