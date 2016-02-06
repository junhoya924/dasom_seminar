#pragma once
#include <iostream>
#include <string>
using namespace std;

class Map
{
private:
	string myMap[25][12];
public:
	Map();
public:
	void show(); //map ÇÁ¸°Æ®
	string getMap(int i_x, int i_y);
	void setMap(int i_x, int i_y, string i_s);
};