#include "Block_3.h"
#include "System.h"

Block_3::Block_3()
{
	x = 6;
	y = 2;
	type = 0;
	gameOver = false;
	finish = false;
	initShape();
}

void Block_3::changeShape()
{
	if (type == 0)
	{
		clearShape();
		type = 1;
		setShape(type);
	}
	else
	{
		clearShape();
		type = 0;
		setShape(type);
	}
}
void Block_3::initShape()
{
	if (System::getInstance()->getMap()->getMap(x, y) != "，"
		|| System::getInstance()->getMap()->getMap(x, y - 1) != "，"
		|| System::getInstance()->getMap()->getMap(x - 1, y) != "，"
		|| System::getInstance()->getMap()->getMap(x - 1, y + 1) != "，")
	{
		gameOver = true;
	}
	else
	{
		setShape(type);
	}
}
void Block_3::setShape(int i_type)
{

	if (i_type == 0)
	{
		if (System::getInstance()->getMap()->getMap(x - 1, y) == "，"
			&& System::getInstance()->getMap()->getMap(x - 1, y + 1) == "，")
		{
			System::getInstance()->getMap()->setMap(x, y, "＝");
			System::getInstance()->getMap()->setMap(x, y - 1, "＝");
			System::getInstance()->getMap()->setMap(x - 1, y, "＝");
			System::getInstance()->getMap()->setMap(x - 1, y + 1, "＝");
		}
		
		else
		{
			type = 1;
			setShape(1);
		}
	}
	else
	{
		if (System::getInstance()->getMap()->getMap(x + 1, y) == "，"
			&& System::getInstance()->getMap()->getMap(x - 1, y - 1) == "，")
		{
			System::getInstance()->getMap()->setMap(x, y, "＝");
			System::getInstance()->getMap()->setMap(x, y - 1, "＝");
			System::getInstance()->getMap()->setMap(x - 1, y - 1, "＝");
			System::getInstance()->getMap()->setMap(x + 1, y, "＝");
		}
		else
		{
			type = 0;
			setShape(0);
		}
	}
}

void Block_3::clearShape()
{
	if (type == 0)
	{
		System::getInstance()->getMap()->setMap(x, y, "，");
		System::getInstance()->getMap()->setMap(x - 1, y, "，");
		System::getInstance()->getMap()->setMap(x, y - 1, "，");
		System::getInstance()->getMap()->setMap(x - 1, y + 1, "，");
	}
	else
	{
		System::getInstance()->getMap()->setMap(x, y, "，");
		System::getInstance()->getMap()->setMap(x, y - 1, "，");
		System::getInstance()->getMap()->setMap(x + 1, y, "，");
		System::getInstance()->getMap()->setMap(x - 1, y - 1, "，");
	}
}

void Block_3::move(int i_direction)
{
	if (i_direction == 0)
	{
		if (type == 0)
		{
			if (2 <= x && x <= 10)
			{
				if (System::getInstance()->getMap()->getMap(x - 2, y) == "，"
					&& System::getInstance()->getMap()->getMap(x - 2, y + 1) == "，")
				{
					clearShape();
					x--;
					setShape(type);
				}
			}
		}
		else
		{
			if (2 <= x && x <= 9)
			{
				if (System::getInstance()->getMap()->getMap(x - 2, y - 1) == "，"
					&& System::getInstance()->getMap()->getMap(x - 1, y) == "，")
				{
					clearShape();
					x--;
					setShape(type);
				}
			}
		}
	}
	else if (i_direction == 1)
	{
		if (type == 0)
		{
			if (2 <= x && x <= 10)
			{
				if (System::getInstance()->getMap()->getMap(x + 1, y - 1) == "，"
					&& System::getInstance()->getMap()->getMap(x + 1, y) == "，"
					&& System::getInstance()->getMap()->getMap(x, y + 1) == "，")
				{
					clearShape();
					x++;
					setShape(type);
				}
			}
		}
		else
		{
			if (2 <= x && x <= 9)
			{
				if (System::getInstance()->getMap()->getMap(x + 2, y) == "，"
					&& System::getInstance()->getMap()->getMap(x + 1, y - 1) == "，")
				{
					clearShape();
					x++;
					setShape(type);
				}
			}
		}
	}
	else if (i_direction == 2)
	{
		if (type == 0)
		{
			if (2 <= y && y <= 22)
			{
				if (System::getInstance()->getMap()->getMap(x, y + 1) == "，"
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
		else
		{
			if (2 <= y && y <= 23)
			{
				if (System::getInstance()->getMap()->getMap(x - 1, y) == "，"
					&& System::getInstance()->getMap()->getMap(x, y + 1) == "，"
					&& System::getInstance()->getMap()->getMap(x + 1, y + 1) == "，")
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
	}
	else if (i_direction == 3)
	{
		if (type == 0)
		{
			for (int i = 1; i < 23; i++)
			{
				if (2 <= y && y <= 22)
				{
					if (System::getInstance()->getMap()->getMap(x - 1, y + 1 + i) != "，"
						|| System::getInstance()->getMap()->getMap(x, y + i) != "，")
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
		else
		{
			for (int i = 1; i < 23; i++)
			{
				if (2 <= y && y <= 23)
				{
					if (System::getInstance()->getMap()->getMap(x - 1, y - 1 + i) != "，"
						|| System::getInstance()->getMap()->getMap(x, y + i) != "，"
						|| System::getInstance()->getMap()->getMap(x + 1, y + i) != "，")
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
	}
}