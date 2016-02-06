#include "System.h"

System::System()
{
	lines = 3;
	level = 1;
	score = 0;
	spaceOn = 0;
	speed = 2000;
	endOfGame = false;
	myBlock = NULL;
}

System* System::getInstance()
{
	static System instance;
	return &instance;
} 

Map* System::getMap()
{
	return &myMap;
}

void System::run()
{
	char i_key = '\0';
	cout << "********Tetris********\n\nWelcome!\nPress Space to start." << endl;
	while (true)
	{
		i_key = getch();
		if (i_key == ' ')
		{
			cout << "Game Start" << endl;
			break;
		}
	}
	
	system("cls");
	show();
	
//	DWORD dwNowTimer = GetTickCount();
//	DWORD dwTickCount = 5000;

	while (endOfGame != true)
	{
		if (checkBlock())
		{
			selectBlock();
		}
	//	for (int i = 0; i < 3; i++)
	//	{
			
			checkKey();
			//system("cls");
			//show();
		
		//	if (spaceOn == 1)
		//	{
		//		spaceOn = 0;
		//		break;
		//	}
			/*if (dwNowTimer + dwTickCount - level * 500 <= GetTickCount() && myBlock != NULL)
			{
				dwNowTimer = GetTickCount();
				myBlock->move(2);
			}*/	
			
	//	}
			Sleep(speed);
		if (myBlock != NULL)
		{
			myBlock->move(2);
			system("cls");
			show();
		}
		checkLine();
		

	}
	GameOver();
	
}

void System::checkKey()
{
	char i_key = '\0';
	if (kbhit())
	{
		i_key = getch();
		keyProcess(i_key);
		system("cls");
		show();
	}
	//while (kbhit()) getch();
}

void System::keyProcess(char i_key)
{
	if (myBlock != NULL)
	{
		if (i_key == 72)
		{
			myBlock->changeShape();
		}
		else if (i_key == 75)
		{
			myBlock->move(0);
		}
		else if (i_key == 77)
		{
			myBlock->move(1);
		}
		else if (i_key == 80)
		{
			myBlock->move(2);
		}
		else if (i_key == 32)
		{
			spaceOn = 1;
			myBlock->move(3);
		}
	}
}

bool System::checkBlock()
{
	if (myBlock == NULL || myBlock->checkFinish() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void System::show()
{
	myMap.show();
	cout << endl;
	cout << "Lines : " << lines << endl;
	cout << "Level : " << level << endl;
	cout << "Score : " << score << endl;
}

void System::selectBlock()
{
	srand(time(NULL));
	int randNum = rand() % 7 + 1;
	if (randNum == 1)
	{
		if (myBlock != NULL)
		{
			delete myBlock;
			myBlock = NULL;
		}
		else
		{
			myBlock = new Block_1();
		}
	}
	else if (randNum == 2)
	{
		if (myBlock != NULL)
		{
			delete myBlock;
			myBlock = NULL;
		}
		else
		{
			myBlock = new Block_2();
		}
	}
	else if (randNum == 3)
	{
		if (myBlock != NULL)
		{
			delete myBlock;
			myBlock = NULL;
		}
		else
		{
			myBlock = new Block_3();
		}
	}
	else if (randNum == 4)
	{
		if (myBlock != NULL)
		{
			delete myBlock;
			myBlock = NULL;
		}
		else
		{
			myBlock = new Block_4();
		}
	}
	else if (randNum == 5)
	{
		if (myBlock != NULL)
		{
			delete myBlock;
			myBlock = NULL;
		}
		else
		{
			myBlock = new Block_5();
		}
	}
	else if (randNum == 6)
	{
		if (myBlock != NULL)
		{
			delete myBlock;
			myBlock = NULL;
		}
		else
		{
			myBlock = new Block_6();
		}
	}
	else
	{
		if (myBlock != NULL)
		{
			delete myBlock;
			myBlock = NULL;
		}
		else
		{
			myBlock = new Block_7();
		}
	}
	checkGameOver();
}

void System::checkLine()
{
	bool check = true;
	int countCombo = 0;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (myMap.getMap(j + 1, i + 1) != "■")
			{
				check = false;
			}
		}
		if (check == true)
		{
			for (int k = 0; k < 10; k++)
			{
				myMap.setMap(k + 1, 1, "·");
			}

			for (int k = i + 1; k != 1; k--)
			{
				for (int l = 0; l < 10; l++)
				{
					myMap.setMap(l + 1, k, myMap.getMap(l + 1, k - 1));
				}
				
			}
			lines--;
			score = score + 100;
			countCombo++;
			checkLevel();	
		}
		check = true;
	}
	if (countCombo != 0)
	{
		score = score + 100 * countCombo;
	}
	
}

void System::checkGameOver()
{
	if (myBlock != NULL)
	{
		if (myBlock->checkGameOver())
		{
			endOfGame = true;
		}
	}
}

void System::checkLevel()
{
	if (lines == 0)
	{
		level++;
		lines = 2 * level + level - 1;
		if (speed >= 500)
		{
			speed = speed - level * 500;
		}
	}
}

void System::GameOver()
{
	system("cls");
	         
	cout << "▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤" << endl; //게임오버 메세지
	cout << "▤                              ▤" << endl;
	cout << "▤  +-----------------------+   ▤" << endl;
	cout << "▤  |  G A M E  O V E R..   |   ▤" << endl;
	cout << "▤  +-----------------------+   ▤" << endl;
	cout << "▤   YOUR SCORE: " << setw(5) << score << setw(12) << "▤" << endl;
	cout << "▤                              ▤" << endl;

	
	fstream file;
	file.open("score.txt");
	int bestScore = -1;
	file >> bestScore;
	if (score > bestScore)
	{
		cout << "▤  ★★★ BEST SCORE! ★★★   ▤  " << endl;
		file << score;
	}
	cout << "▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤" << endl;
	file.close();

}