#ifndef StorageManagerWrapper_hpp
#define StorageManagerWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initialize(const void *object);
	const char *uploadImageRetreiveLink(const void *object, const char* filepath);
#ifdef __cplusplus
}
#endif

#endif