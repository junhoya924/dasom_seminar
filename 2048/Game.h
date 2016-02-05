#pragma once
#include"Move.h"
#include"FileManager.h"

class CGame : public CMove, public CFileManager
{
private:
	string sPlayer;
public:
	CGame();
	~CGame();
public:
	void fnIntro();
	bool IsEnd();
	void fnRun();
};
