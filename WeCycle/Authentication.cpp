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

	result.OnCompletion([](const firebase::Future<firebase::auth::User*>& result, void* user_data) {
		std::cout << "reuslt completed" << std::endl;
		if (result.error() == firebase::auth::kAuthErrorNone) {
			Account *acc = static_cast<Account *>(user_data);
			firebase::auth::User *user = *result.result();
			std::string uID = user->uid();
			acc->createNewAccount(uID);
			acc->updateCheckAccount(true);
			std::cout << "Successfully created account: " << user->email() << std::endl;
		}
		else {
			Account *acc = static_cast<Account *>(user_data);
			acc->updateCheckAccount(false);
			std::cout << "Error creating account..." << result.error_message() << std::endl;
		}
	}, acc);
}

void Authentication::signInUser(Account *acc, std::string emailO, std::string passwordO) {

	const char *email = strdup(emailO.c_str());
	const char *password = strdup(passwordO.c_str());

	firebase::Future<firebase::auth::User*> result =
		auth->SignInWithEmailAndPassword(email, password);

	//while (result.status() != firebase::kFutureStatusComplete) {}


	result.OnCompletion([](const firebase::Future<firebase::auth::User*>& result, void* user_data) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			std::cout << "result completed" << std::endl;
			Account *acc = static_cast<Account *>(user_data);
			firebase::auth::User* user = *result.result();
			std::string uID = user->uid();
			acc->updateUID(uID);
			acc->updateDataList();
			acc->updateCheckAccount(true);
			printf("Sign in succeeded for email %s\n", user->email().c_str());
		}
		else {
			Account *acc = static_cast<Account *>(user_data);
			acc->updateCheckAccount(false);
			printf("Sign in failed with error '%s'\n", result.error_message());
		}
	}, acc);
#ifdef _WIN32
	std::clock_t start;
	double duration = 0;
	start = std::clock();
	while (duration != 5000) {
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		if (result.result_void() != nullptr) {
			return;
		}
	}
#endif // _WIN32

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
		while (future.status() != firebase::kFutureStatusComplete);
		if (future.error() == 0) {
			printf("Updated user profile");
		}
		else {
			printf("Failed to update user profile");
		}
		acc->updatePFP(profile.photo_url);
		acc->updateDisplayName(profile.display_name);
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
		while (future.status() != firebase::kFutureStatusComplete);
		if (future.error() == 0) {
			printf("Updated user profile pic link");
		}
		else {
			printf("Failed to update user profile pic link");
		}
		acc->updatePFP(profile.photo_url);
	}
}