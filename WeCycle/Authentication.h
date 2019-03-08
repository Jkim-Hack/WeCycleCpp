#pragma once
#include "Account.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include <iostream>
#include <firebase/auth.h>
#include <firebase/future.h>
#include "Crypto.h"

class Authentication {

private:
	Crypto crypto;

public: 

	firebase::auth::Auth* auth;
	firebase::App* app;

	Authentication(FirebaseManager *fbManager, DataManager *dbManager);
	~Authentication();

	std::string createAndRegisterAccount(Account *account); //Returns user ID
	std::string createAndRegisterAccount(std::string email, std::string password); //Returns user ID

	std::string signInUser(Account *account); //Returns user ID
	std::string signInUser(std::string email, std::string password); //Returns user ID
};