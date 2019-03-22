#include "EmailValueListener.h"

EmailValueListener::EmailValueListener(firebase::Variant *obj) {
	object = obj;
}
void EmailValueListener::OnValueChanged(const firebase::database::DataSnapshot &snapshot) {
	firebase::Variant obj = snapshot.value();
	if (obj.is_mutable_string()) {
		object->set_mutable_string(obj.mutable_string());
		printf("Done454545\n");
	}
}
void EmailValueListener::OnCancelled(const firebase::database::Error& error_code,
				 const char* error_message) {
	printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
		   error_message);
}