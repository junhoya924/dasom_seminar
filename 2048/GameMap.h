#pragma once
#include<iostream>
#include<ctime>
using namespace std;

class CGameMap
{
protected:
	unsigned int dMapAry[4][4];
public:
	CGameMap();
	~CGameMap();
public:
	void fnRandom(); // 랜덤으로 0인 위치에 2생성
	void fnLeft();
	void fnRight();
	void fnUp();
	void fnDown();
};
