#include "FirebaseManagerWrapper.hpp"
#include "FirebaseManager.h"

const void *initialize(const char *filename) {
	FirebaseManager *fireManager = new FirebaseManager(filename);
	return (void *)fireManager;
}
