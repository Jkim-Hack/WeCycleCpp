#include "Authentication.h"

Authentication::Authentication(FirebaseManager *fbManager, DataManager *dbManager) {
	app = fbManager->getApp();
	auth = firebase::auth::Auth::GetAuth(app);
	crypto = Crypto(dbManager);
	this->dbManage = dbManager;
}

Authentication::~Authentication() {}

void Authentication::createAndRegisterAccount(Account *acc, std::string emailO, std::string passwordO) {
	
	std::string uID = "";

	const char *email = strdup(emailO.c_str());
	const char *password = strdup(crypto.hashSHAKE128(passwordO).c_str());

	firebase::Future<firebase::auth::User*> result = auth->CreateUserWithEmailAndPassword(email, password);

	if (result.status() == firebase::kFutureStatusComplete) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User *user = *result.result();
			uID = user->uid();
			acc = new Account(uID);
			dbManage->pushData(acc, "Account Info");
			std::cout << "Successfully created account: " << user->email() << std::endl;
		}
		else {
			std::cout << "Error creating account..." << result.error_message() << std::endl;
		}
	}

}

void Authentication::signInUser(Account *acc, std::string emailO, std::string passwordO) {

	std::string uID = "";

	const char *email = strdup(emailO.c_str());
	const char *password = strdup(crypto.hashSHAKE128(passwordO).c_str());

	firebase::Future<firebase::auth::User*> result =
		auth->SignInWithEmailAndPassword(email, password);

	if (result.status() == firebase::kFutureStatusComplete) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User* user = *result.result();
			uID = user->uid();
			firebase::Variant list[4];
			dbManage->retrieveData("Account Info", uID, list);
			printf("Sign in succeeded for email %s\n", user->email().c_str());
		}
		else {
			printf("Sign in failed with error '%s'\n", result.error_message());
		}
	}

}