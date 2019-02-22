#include "Rank.h"

Rank::Rank(0, "Beginner")
{
	this->xp = 0;
	this->rank = "Beginner";
}

Rank::Rank(unsigned int xp, std::string rank)
{
	this->xp = xp;
	this->rank = rank;
}

void Rank::LevelUpRank()
{

}