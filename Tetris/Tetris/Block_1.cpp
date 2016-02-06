#include "Block_1.h"
#include "System.h"
Block_1::Block_1()
{
	x = 5;
	y = 1;
	type = 0;
	gameOver = false;
	finish = false;
	initShape();
}

void Block_1::changeShape()
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

void Block_1::initShape()
{
	if (System::getInstance()->getMap()->getMap(x - 1, y) != "，"
		|| System::getInstance()->getMap()->getMap(x, y) != "，"
		|| System::getInstance()->getMap()->getMap(x - 2, y) != "，"
		|| System::getInstance()->getMap()->getMap(x + 1, y) != "，")
	{
		gameOver = true;
	}
	else
	{
		setShape(type);
	}
}

void Block_1::setShape(int i_type)
{

	if (i_type == 0)
	{
		if (System::getInstance()->getMap()->getMap(x - 1, y) == "，"
			&& System::getInstance()->getMap()->getMap(x - 2, y) == "，"
			&& System::getInstance()->getMap()->getMap(x + 1, y) == "，")
		{
			System::getInstance()->getMap()->setMap(x, y, "＝");
			System::getInstance()->getMap()->setMap(x - 1, y, "＝");
			System::getInstance()->getMap()->setMap(x - 2, y, "＝");
			System::getInstance()->getMap()->setMap(x + 1, y, "＝");
		}
		
		else
		{
			type = 1;
			setShape(1); 
		}
	}
	else
	{
		if (System::getInstance()->getMap()->getMap(x, y - 1) == "，"
			&& System::getInstance()->getMap()->getMap(x, y + 1) == "，"
			&& System::getInstance()->getMap()->getMap(x, y + 2) == "，")
		{
			System::getInstance()->getMap()->setMap(x, y - 1, "＝");
			System::getInstance()->getMap()->setMap(x, y + 1, "＝");
			System::getInstance()->getMap()->setMap(x, y + 2, "＝");
			System::getInstance()->getMap()->setMap(x, y, "＝");
		}
		else
		{
			type = 0;
			setShape(0);
		}
	}
}

void Block_1::clearShape()
{
	if (type == 0)
	{
		System::getInstance()->getMap()->setMap(x, y, "，");
		System::getInstance()->getMap()->setMap(x - 1, y, "，");
		System::getInstance()->getMap()->setMap(x - 2, y, "，");
		System::getInstance()->getMap()->setMap(x + 1, y, "，");
	}
	else
	{
		System::getInstance()->getMap()->setMap(x, y, "，");
		System::getInstance()->getMap()->setMap(x, y - 1, "，");
		System::getInstance()->getMap()->setMap(x, y + 1, "，");
		System::getInstance()->getMap()->setMap(x, y + 2, "，");
	}
}

void Block_1::move(int i_direction)
{
	if (i_direction == 0)
	{
		if (type == 0)
		{
			if (3 <= x && x <= 9)
			{
				if (System::getInstance()->getMap()->getMap(x - 3, y) == "，")
				{
					clearShape();
					x--;
					setShape(type);
				}
			}
		}
		else
		{
			if (1 <= x && x <= 10)
			{
				if (System::getInstance()->getMap()->getMap(x - 1, y) == "，"
					&& System::getInstance()->getMap()->getMap(x - 1, y - 1) == "，"
					&& System::getInstance()->getMap()->getMap(x - 1, y + 1) == "，"
					&& System::getInstance()->getMap()->getMap(x - 1, y + 2) == "，")
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
			if (3 <= x && x <= 9)			
			{
				if (System::getInstance()->getMap()->getMap(x + 2, y) == "，")
				{
					clearShape();
					x++;
					setShape(type);
				}
			}
		}
		else
		{
			if (1 <= x && x <= 10)
			{
				if (System::getInstance()->getMap()->getMap(x + 1, y) == "，"
					&& System::getInstance()->getMap()->getMap(x + 1, y - 1) == "，"
					&& System::getInstance()->getMap()->getMap(x + 1, y + 1) == "，"
					&& System::getInstance()->getMap()->getMap(x + 1, y + 2) == "，")
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
			if (1 <= y && y <= 23)
			{
				if (System::getInstance()->getMap()->getMap(x - 2, y + 1) == "，"
					&& System::getInstance()->getMap()->getMap(x - 1, y + 1) == "，"
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
		else
		{
			if (2 <= y && y <= 21)
			{
				if (System::getInstance()->getMap()->getMap(x, y + 3) == "，")
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
				if (1 <= y && y <= 23)
				{
					if (System::getInstance()->getMap()->getMap(x - 2, y + i) != "，"
						|| System::getInstance()->getMap()->getMap(x - 1, y + i) != "，"
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
		else
		{
			for (int i = 1; i < 23; i++)
			{
				if (2 <= y && y <= 20)
				{
					if (System::getInstance()->getMap()->getMap(x, y + 2 + i) != "，")
					{
						clearShape();
						y = y - 1 + i;
						setShape(type);
						finish = true;
						break;
					}
				}
			}	
		}
	}
}