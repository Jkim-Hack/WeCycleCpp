#pragma once
#include <firebase\app.h>

class DataManager
{
private:
	void loadFirebaseJSON(char* filename, firebase::AppOptions *appOptions);

public:
	DataManager(char* filename);
	~DataManager();
};

