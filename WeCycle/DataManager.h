#pragma once
#include <firebase\app.h>
#include <firebase\database.h>
#include "Account.h"
#include "PushableObject.h"
#include "FirebaseManager.h"

//TODO: ADD AUTHENTICATION TO FIREBASE

class DataManager
{
private:
	
	firebase::database::Database *database;
	firebase::database::DatabaseReference dbref;

public:
	DataManager(FirebaseManager &fbManager);
	~DataManager(); //Called at the object's termination

	void pushData(PushableObject objectToPass, std::string parent);
	firebase::database::DatabaseReference getDBref();

};

