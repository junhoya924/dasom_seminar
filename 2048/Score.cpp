#include "Score.h"

CScore::CScore()
{
	uiTotalHigestScore = 0;
}

CScore::~CScore()
{
}

void CScore::fnInsert(string ID, unsigned int score)
{
	UserScore.insert(ClPair<string, unsigned int>(ID, score));
	return;
}

unsigned int CScore::fnPersonalHighestScore(string ID)
{
	return UserScore[ID];
}

unsigned int CScore::fnTotalHigestScore()
{
	return uiTotalHigestScore;
}

void CScore::fn_setTotalHigestScore(unsigned int Highest)
{
	uiTotalHigestScore = Highest;
	return;
}

ClMap<string, unsigned int> CScore::fn_getUserScore()
{
	return UserScore;
}
