#ifndef UIDWrapper_hpp
#define UIDWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif

	const void* intitalizeUID(const void *dataManager);
	void registerListener(const void *uidobject, const char *email);
	const char *getUID(const void *uidobject);

#ifdef __cplusplus
}
#endif

#endif
