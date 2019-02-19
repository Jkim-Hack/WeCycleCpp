#include "StorageManager.h"

StorageManager::StorageManager(FirebaseManager fbManager) {
	
	storage = firebase::storage::Storage::GetInstance(fbManager.getApp);
	storage_ref = storage->GetReferenceFromUrl("gs://wecycle-316c1.appspot.com");

}

StorageManager::~StorageManager() {
	delete storage;
}

const std::string* StorageManager::uploadImageRetreiveLink(std::string filepath) {
	const std::string *result;

	firebase::storage::StorageReference image_ref = storage_ref.Child("images/image.jpg");

	firebase::storage::Listener *listener;
	firebase::storage::Controller *controller;

	const char* filePath = filepath.c_str();
	firebase::Future<firebase::storage::Metadata> futureUpload = image_ref.PutFile(filePath, listener, controller);

	if (futureUpload.error() != firebase::storage::kErrorNone) {
		std::cout << "ERROR";
	}
	else {
		const firebase::storage::Metadata *metadata = futureUpload.result();
	}

	firebase::Future<std::string> futureDownload = image_ref.GetDownloadUrl();
	result = futureDownload.result();
	return result;
}
