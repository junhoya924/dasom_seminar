#pragma once

#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

class ClPlayer
{
private:
	string Cl_name;
public:
	ClPlayer();
	virtual ~ClPlayer();
public:
	void setName(string Cl_name) { this->Cl_name = Cl_name; }
	string getName() { return Cl_name; }
	virtual int* play(ClMap<int, int*>);
};