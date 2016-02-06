#pragma once
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "Map.h"
#include "Block_1.h"
#include "Block_2.h"
#include "Block_3.h"
#include "Block_4.h"
#include "Block_5.h"
#include "Block_6.h"
#include "Block_7.h"

class System
{
private:
	int lines;
	int level;
	int score;
	int speed;
	int spaceOn;
	bool endOfGame;
	Map myMap;
	Block* myBlock;
public:
	System();
public:
	static System* getInstance();
	Map* getMap();
	void checkLine();
	void run(); //��ü ���α׷� ����
	void show(); //���� �׷��ش�
	void selectBlock(); //�� �ʱ� ����
	bool checkBlock(); //�� �� ȸ���� �������� �˷��� true ���� false �ȳ���
	void keyProcess(char i_key); //Ű���尪 �޾Ƽ� ����
	void checkGameOver(); //���� ���� Ȯ��
	void checkLevel(); //���� ����Ȯ��
	void checkKey(); //Ű �Է� Ȯ��
	void GameOver();
};