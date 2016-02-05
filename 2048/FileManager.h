#pragma once
#include<fstream>
#include"Score.h"
#include"User.h"
using namespace std;

class CFileManager
{
private:
	string sID;
	string sPassWard;
	unsigned int uiScore;
protected:
	CUser Cl_User;
	CScore Cl_Score;
public:
	CFileManager(); // 파일 읽어와서 유저와 스코어에 저장
	~CFileManager();
public:
	void fnFileLoad();
	void fnFileSave();
};
