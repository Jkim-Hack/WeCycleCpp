#include "AccountWrapper.hpp"
#include "Account.h"

const void *initializeAccount(const void *dataManager) {
	DataManager *dataM = (DataManager *)dataManager;
	Account *account = new Account(dataM);
	return (void *)account;
}
const void updateRank(const void *accountObj) {
	Account *account = (Account *)accountObj;
	account->updateRank();
}
const void updateXP(const void *accountObj, int increment) {
	Account *account = (Account *)accountObj;
	account->updateXP(increment);
}
const void updateCoins(const void *accountObj, int incremenet) {
	Account *account = (Account *)accountObj;
	account->updateCoins(incremenet);
}
const void updatePFP(const void *accountObj, const char* link) {
	Account *account = (Account *)accountObj;
	account->updatePFP(link);
}
const char* rank(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->rankA();
}
const int experience(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->experienceA();
}
const int coins(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->coinsA();
}
const char* profilePicLink(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->profilePicLinkA();
}