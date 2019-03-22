#include "EmailValueListener.h"

EmailValueListener::EmailValueListener(UID *id) {
	uid = id;
}
void EmailValueListener::OnValueChanged(const firebase::database::DataSnapshot &snapshot) {
	firebase::Variant obj = snapshot.value();
	if (obj.is_mutable_string()) {
		uid->updateUID(obj.mutable_string());
		printf("Done454545\n");
	}
}
void EmailValueListener::OnCancelled(const firebase::database::Error& error_code,
				 const char* error_message) {
	printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
		   error_message);
}