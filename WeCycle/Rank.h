#pragma once

class Rank
{
private:
	unsigned int xp;
	std::string rank;

public:
	Rank(0, "Beginner");
	Rank(unsigned int xp, std::string rank);

	void LevelUpRank();
};