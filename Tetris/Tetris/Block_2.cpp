#include "Block_2.h"
#include "System.h"

Block_2::Block_2()
{
	x = 5;
	y = 1;
	type = 0;
	gameOver = false;
	finish = false;
	initShape();
}

void Block_2::initShape()
{
	if (System::getInstance()->getMap()->getMap(x, y) == "，"
		&& System::getInstance()->getMap()->getMap(x, y + 1) == "，"
		&& System::getInstance()->getMap()->getMap(x - 1, y) == "，"
		&& System::getInstance()->getMap()->getMap(x - 1, y + 1) == "，")
	{
		setShape(type);
	}
	else
	{
		gameOver = true;
	}
}

void Block_2::setShape(int i_type)
{
	System::getInstance()->getMap()->setMap(x, y, "＝");
	System::getInstance()->getMap()->setMap(x, y + 1, "＝");
	System::getInstance()->getMap()->setMap(x - 1, y, "＝");
	System::getInstance()->getMap()->setMap(x - 1, y + 1, "＝");
}

void Block_2::clearShape()
{
	System::getInstance()->getMap()->setMap(x, y, "，");
	System::getInstance()->getMap()->setMap(x, y + 1, "，");
	System::getInstance()->getMap()->setMap(x - 1, y, "，");
	System::getInstance()->getMap()->setMap(x - 1, y + 1, "，");
}

void Block_2::move(int i_direction)
{
	if (i_direction == 0)
	{
		if (2 <= x && x <= 10)
		{
			if (System::getInstance()->getMap()->getMap(x - 2, y) == "，"
				&& System::getInstance()->getMap()->getMap(x - 2, y - 1) == "，")
			{
				clearShape();
				x--;
				setShape(type);
			}
		}
	}
	else if (i_direction == 1)
	{
		if (2 <= x && x <= 9)
		{
			if (System::getInstance()->getMap()->getMap(x + 1, y) == "，"
				&& System::getInstance()->getMap()->getMap(x + 1, y - 2) == "，")
			{
				clearShape();
				x++;
				setShape(type);
			}
		}
	}
	else if (i_direction == 2)
	{
		if (1 <= y && y <= 22)
		{
			if (System::getInstance()->getMap()->getMap(x, y + 2) == "，"
				&& System::getInstance()->getMap()->getMap(x - 1, y + 2) == "，")
			{
				clearShape();
				y++;
				setShape(type);
			}
			else
			{
				finish = true;
			}
		}
	}
	else if (i_direction == 3)
	{
		for (int i = 1; i < 23; i++)
		{
			if (System::getInstance()->getMap()->getMap(x, y + 1 + i) != "，"
				|| System::getInstance()->getMap()->getMap(x - 1, y + 1 + i) != "，")
			{
				clearShape();
				y = y + i - 1;
				setShape(type);
				finish = true;
				break;
			}
			
		}
	}
}