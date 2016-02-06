#include "Map.h"

Map::Map()
{
	for (int i = 0; i < 25; i++)
	{
		myMap[i][0] = "¢Æ";
		myMap[i][11] = "¢Æ";
	}
	for (int i = 0; i < 12; i++)
	{
		myMap[0][i] = "¢Æ";
		myMap[24][i] = "¢Æ";
	}
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			myMap[i + 1][j + 1] = "¡¤";
		}
	}
}


void Map::show()
{

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << myMap[i][j];
		}
		cout << endl;
	}
}


string Map::getMap(int i_x, int i_y)
{
	return myMap[i_y][i_x];
}

void Map::setMap(int i_x, int i_y, string i_s)
{
	myMap[i_y][i_x] = i_s;
}