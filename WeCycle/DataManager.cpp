#include "DataManager.h"
#include <iostream>
#include <firebase\app.h>



DataManager::DataManager(char* filename)
{
	loadFirebaseJSON(filename);


}


DataManager::~DataManager()
{
}

void DataManager::loadFirebaseJSON(char * filename) {
	firebase::AppOptions::LoadFromJsonConfig(filename);
}
