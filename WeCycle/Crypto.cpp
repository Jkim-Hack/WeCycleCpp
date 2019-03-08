#include "Crypto.h"

Crypto::Crypto() {

}

void Crypto::acquireSaltConfiguration(DataManager dbManager) {
	const char** salts = dbManager.retrieveData("s4lT");
	salt0 = salts[0];
	salt1 = salts[1];
}

std::string Crypto::encrypt(std::string data) {
	
	std::string msg = "Yoda said, Do or do not. There is not try.";
	std::string digest;
	/*
	CryptoPP::SHAKE128 hash;
	
	hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
	digest.resize(hash.DigestSize());
	hash.Final((CryptoPP::byte*)&digest[0]);
	*/
	std::cout << digest << std::endl;
	return " ";
}

std::string Crypto::encrypt(std::string data, std::string salt, std::string salt1) {
	return " ";
}

std::string Crypto::decrypt(std::string data) {
	return " ";
}