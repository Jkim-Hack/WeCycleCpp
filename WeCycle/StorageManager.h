#pragma once
#include <iostream>
#include <firebase\storage.h>
#include <firebase\app.h>
#include <firebase\future.h>
#include <firebase\storage\metadata.h>
#include "DataManager.h"

class StorageManager {

private:
	firebase::storage::Storage *storage;
	firebase::storage::StorageReference storage_ref;
public:
	StorageManager(FirebaseManager fbManager);
	~StorageManager();
	const std::string *uploadImageRetreiveLink(std::string filepath);


};
