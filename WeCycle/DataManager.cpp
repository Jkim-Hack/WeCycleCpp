#include "DataManager.h"
#include <iostream>
#include <firebase\app.h>



DataManager::DataManager(char* filename)
{
	firebase::AppOptions appOptions;
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON(filename, appOps);
	firebase::App *app = firebase::App::Create(appOptions);

}


DataManager::~DataManager()
{
}

void DataManager::loadFirebaseJSON(char * filename, firebase::AppOptions *appOptions) {
	appOptions->LoadFromJsonConfig(filename);
}
