#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Map.h"
using namespace std;

class ClBoard
{
private:
	string aString[10][10];
public:
	ClBoard();
	~ClBoard();
public:
	ClMap<int, int*> checkBoard(int);
	void changeBoard(int, int*);
	void cleanBoard();
	bool endGame();
	void print();
};