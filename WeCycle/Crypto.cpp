#include "Crypto.h"

Crypto::Crypto(DataManager *dbManager) {
	acquireSaltConfiguration(dbManager);
}

Crypto::Crypto() {

}
void Crypto::acquireSaltConfiguration(DataManager *dbManager) {
	const char** salts = dbManager->retrieveData("s4lT");
	salt0 = salts[0];
	salt1 = salts[1];
}

std::string Crypto::hashSHAKE128(std::string stringToEncrypt) {

	std::string msg = stringToEncrypt;
	std::string digest;

	CryptoPP::SHAKE128 hash;
	CryptoPP::StringSource(msg, true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest))));

	std::string msgSalts = salt0 + digest + salt1;
	std::string resultDigest;

	CryptoPP::StringSource(msgSalts, true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(resultDigest))));

	return resultDigest;
}

const bool Crypto::verifySHAKE128(std::string stringToVerify, std::string encoding) {
	std::string encoded_initial = stringToVerify;
	std::string resultDigest = hashSHAKE128(encoded_initial);
	return (resultDigest == encoding);
}