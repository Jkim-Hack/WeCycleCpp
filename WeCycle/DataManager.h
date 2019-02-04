#pragma once
class DataManager
{
private:
	void loadFirebaseJSON(char* filename);

public:
	DataManager(char* filename);
	~DataManager();
};

