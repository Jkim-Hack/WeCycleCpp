#include "AccountWrapper.hpp"
#include "Account.h"

const void *initialize(const char *emailAddress, const char *password) {
	Account *account = new Account(emailAddress, password);
	return (void *)account;
}
const void *initialize(const char *emailAddress, const char *password, long phoneNumber) {
	Account *account = new Account(emailAddress, password, phoneNumber);
	return (void *)account;
}