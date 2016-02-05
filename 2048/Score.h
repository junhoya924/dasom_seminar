#pragma once
#include<iostream>
#include<string>
#include"Map.h"
using namespace std;

class CScore
{
private:
	unsigned int uiTotalHigestScore;
	ClMap<string, unsigned int> UserScore;
public:
	CScore();
	~CScore();
public:
	void fnInsert(string ID, unsigned int score);
	unsigned int fnPersonalHighestScore(string ID);
	unsigned int fnTotalHigestScore();
	void fn_setTotalHigestScore(unsigned int Highest);
	ClMap<string, unsigned int> fn_getUserScore();
};
