#include "Authentication.h"

Authentication::Authentication(FirebaseManager *fbManager, DataManager *dbManager) {
	app = fbManager->getApp();
	auth = firebase::auth::Auth::GetAuth(app);
	this->dbManage = dbManager;
}

Authentication::~Authentication() {}

void Authentication::createAndRegisterAccount(Account *acc, std::string emailO, std::string passwordO) {

	const char *email = strdup(emailO.c_str());
	const char *password = strdup(passwordO.c_str());

	firebase::Future<firebase::auth::User*> result = auth->CreateUserWithEmailAndPassword(email, password);

	while (result.status() != firebase::kFutureStatusComplete) {}
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User *user = *result.result();
			std::string uID = user->uid();
			acc = new Account(uID);
			dbManage->pushData(acc, "Account Info");
			std::cout << "Successfully created account: " << user->email() << std::endl;
		}
		else {
			std::cout << "Error creating account..." << result.error_message() << std::endl;
		}

}

void Authentication::signInUser(Account *acc, std::string emailO, std::string passwordO) {

	const char *email = strdup(emailO.c_str());
	const char *password = strdup(passwordO.c_str());

	firebase::Future<firebase::auth::User*> result =
		auth->SignInWithEmailAndPassword(email, password);

	while (result.status() != firebase::kFutureStatusComplete) {}
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User* user = *result.result();
			std::string uID = user->uid();
			firebase::Variant list;
			dbManage->retrieveData("Account Info", uID, list); //should return a list of maps
			if (list.is_vector()) {
				std::vector<firebase::Variant> dataList = list.vector();
				acc = new Account(dataList, uID);
			}
			printf("Sign in succeeded for email %s\n", user->email().c_str());
		}
		else {
			printf("Sign in failed with error '%s'\n", result.error_message());
		}

}

void Authentication::signOutUser() {
	auth->SignOut();
}

void Authentication::updateUserProfile(Account *acc, const char* pfplink, const char* displayname) {
	firebase::auth::User *user = auth->current_user();
	if (user != nullptr) {
		firebase::auth::User::UserProfile profile;
		profile.display_name = displayname;
		profile.photo_url = pfplink;
		firebase::Future<void> future = user->UpdateUserProfile(profile);
		while (future.status() != firebase::kFutureStatusComplete) {}
		if (future.error() == 0) {
			printf("Updated user profile");
		}
		else {
			printf("Failed to update user profile");
		}
		acc->updatePFP(profile.photo_url, dbManage);
		acc->updateDisplayName(profile.display_name, dbManage);
	}
}
void Authentication::updateUserPFPLink(Account *acc, const char* pfplink) {
	firebase::auth::User *user = auth->current_user();
	if (user != nullptr) {
		firebase::auth::User::UserProfile profile;
		profile.photo_url = pfplink;
		printf(user->display_name().c_str());
		profile.display_name = _strdup(user->display_name().c_str());
		firebase::Future<void> future = user->UpdateUserProfile(profile);
		while (future.status() != firebase::kFutureStatusComplete) {}
		if (future.error() == 0) {
			printf("Updated user profile pic link");
		}
		else {
			printf("Failed to update user profile pic link");
		}
		acc->updatePFP(profile.photo_url, dbManage);
	}
}