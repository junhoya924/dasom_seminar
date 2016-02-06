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
	void run(); //전체 프로그램 실행
	void show(); //맵을 그려준다
	void selectBlock(); //블럭 초기 선택
	bool checkBlock(); //블럭 한 회수가 끝났는지 알려줌 true 끝남 false 안끝남
	void keyProcess(char i_key); //키보드값 받아서 실행
	void checkGameOver(); //게임 오버 확인
	void checkLevel(); //레벨 라인확인
	void checkKey(); //키 입력 확인
	void GameOver();
};