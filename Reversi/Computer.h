#pragma once

#include "Player.h"

class ClComputer : public ClPlayer
{
public:
	ClComputer();
	~ClComputer();
public:
	int* play(ClMap<int, int*>);
};