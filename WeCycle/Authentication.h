#pragma once
#include "Account.h"
#include "FirebaseManager.h"
#include <iostream>
#include <firebase/auth.h>
#include <firebase/future.h>

class Authentication {

public: 

	firebase::auth::Auth* auth;
	firebase::App* app;

	Authentication(FirebaseManager *fbManager);
	~Authentication();

	std::string createAndRegisterAccount(Account account); //Returns user ID
	std::string createAndRegisterAccount(std::string email, std::string password); //Returns user ID

	std::string signInUser(Account account); //Returns user ID
	std::string signInUser(std::string email, std::string password); //Returns user ID
};