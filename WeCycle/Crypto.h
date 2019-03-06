#pragma once
#include <iostream>
class Crypto {

public: 
	std::string encrypt(std::string stringToEncrypt);
	std::string encrypt(std::string stringToEncrypt, std::string salt);
	std::string decrypt(std::string digest);
};