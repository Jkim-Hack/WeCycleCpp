#ifndef PushableObjectWrapper_hpp
#define PushableObjectWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initialize();
	void addData(const void *object, const char *key, const char *mapKey, const char *mapValue);
	void initializeMap(const void *object, const char *keyMap, const char *keyValue);
	void initializeMap(const void *object, const char *keyMap, const char *keyValue, const char *keyValue2);

#ifdef __cplusplus
}
#endif

#endif