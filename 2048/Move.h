#pragma once
#include<conio.h>
#include"GameMap.h"

class CMove : public CGameMap
{
public:
	CMove();
	~CMove();
public:
	bool fnMove();
};
