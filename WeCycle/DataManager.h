#pragma once
#include <firebase\app.h>
#include <firebase\database.h>
#include "PushableObject.h"

class DataManager
{
private:
	firebase::AppOptions appOptions;
	firebase::database::Database *database;
	firebase::database::DatabaseReference dbref;
	void loadFirebaseJSON(char* filename, firebase::AppOptions *appOptions);

public:
	DataManager(char* filename);
	virtual ~DataManager(); //Called at the object's termination
	void writeOrUpdateData(PushableObject objectToPass); //TODO: Implement this
	firebase::database::DatabaseReference getDBref();
};

