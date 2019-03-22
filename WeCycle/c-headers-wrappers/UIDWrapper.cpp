#include "UIDWrapper.hpp"
#include "DataManager.h"
#include "UID.h"

const void *intitalizeUID(const void *dataManager) {
	UID *uid = new UID((DataManager *)dataManager);
	return uid;
}
void registerListener(const void *uidobject, const char *email) {
	UID *uid = (UID *)uidobject;
	uid->registerListener(email);
}
const char *getUID(const void *uidobject) {
	UID *uid = (UID *)uidobject;
	return uid->getUID();
}