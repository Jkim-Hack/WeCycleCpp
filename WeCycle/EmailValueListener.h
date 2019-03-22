#pragma once
#include <iostream>
#include "UID.h"
#include <firebase/variant.h>
#include <firebase/database/listener.h>
#include <firebase/database/data_snapshot.h>

class UID;
class EmailValueListener : public firebase::database::ValueListener {
private:
	UID *uid;

public:
	EmailValueListener(UID *id);
	void OnValueChanged(const firebase::database::DataSnapshot &snapshot) override;
	void OnCancelled(const firebase::database::Error& error_code,
					 const char* error_message) override;
};