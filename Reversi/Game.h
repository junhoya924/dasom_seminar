#pragma once

#include <iostream>
#include <string>
#include "Board.h"
#include "Computer.h"
using namespace std;

class ClGame
{
private:
	ClBoard Cl_board;
	ClPlayer* pPlayer[2];
private:
	ClGame();
public:
	~ClGame();
public:
	static ClGame* getInstance();
public:
	// void startScreen();
	void gameProceed();
};