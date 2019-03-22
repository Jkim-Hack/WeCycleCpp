#pragma once
#include <iostream>
#include <firebase/variant.h>
#include <firebase/database/listener.h>
#include <firebase/database/data_snapshot.h>

class EmailValueListener : public firebase::database::ValueListener {\
	firebase::Variant *object;
public:
	EmailValueListener(firebase::Variant *obj) {
		object = obj;
	}
	void OnValueChanged(const firebase::database::DataSnapshot &snapshot) override {
		firebase::Variant obj = snapshot.value();
		if (obj.is_mutable_string()) {
			object->set_mutable_string(obj.mutable_string());
			printf("Done454545\n");
		}
	}
	void OnCancelled(const firebase::database::Error& error_code,
					 const char* error_message) override {
		printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
			   error_message);
	}
};