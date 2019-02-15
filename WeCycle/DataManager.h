#pragma once
#include <firebase\app.h>
#include <firebase\database.h>
#include <json.hpp>
#include "Account.h"
#include "PushableObject.h"

class DataManager
{
private:
	firebase::AppOptions appOptions;
	firebase::database::Database *database;
	firebase::database::DatabaseReference dbref;
	std::map<std::string, std::string> parseJSONfromFile(const char* filename);
	void loadFirebaseJSON(const char* parsedFile, firebase::AppOptions *appOptions);

public:
	DataManager(const char* filename);
	~DataManager(); //Called at the object's termination

	void writeOrUpdateData(PushableObject objectToPass); 
	firebase::database::DatabaseReference getDBref();
};

