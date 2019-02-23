#ifndef AccountWrapper_hpp
#define AccountWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initialize(const char *emailAddress, const char *password);
	const void *initialize(const char *emailAddress, const char *password, long phoneNumber);
#ifdef __cplusplus
}
#endif

#endif
