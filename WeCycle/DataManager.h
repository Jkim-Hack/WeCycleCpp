#pragma once
#include <firebase\app.h>
#include <firebase\database.h>

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
	void writeOrUpdateData(void *objectToPass);
	firebase::database::DatabaseReference getDBref();
};

