#pragma once
#include "EmailValueListener.h"
#include "Account.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include <iostream>
#include <firebase/auth.h>
#include <firebase/future.h>
#include <firebase/database/listener.h>
#include "EmailValueListener.h"
#include <ctime>

class UID {

private:
	DataManager *dbManage;
	std::string uid;
public:

	UID(DataManager *dbm);
	void updateUID(std::string id);
	void registerListener(const char* email);
	const char *getUID();

};