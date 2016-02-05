#include "FileManager.h"

CFileManager::CFileManager()
{
}

CFileManager::~CFileManager()
{
}

void CFileManager::fnFileLoad()
{
	ifstream fsUserInfo;
	fsUserInfo.open("UserInfo.txt");

	unsigned int uiTemp = 0;

	while (!fsUserInfo.eof())
	{
		fsUserInfo >> sID >> sPassWard >> uiScore;
		Cl_User.fnInsert(sID, sPassWard);
		Cl_Score.fnInsert(sID, uiScore);

		if (uiTemp < uiScore)
		{
			uiTemp = uiScore;
			Cl_Score.fn_setTotalHigestScore(uiScore); // 전체 최고점수 저장
		}
	}

	fsUserInfo.close();

	return;
}

void CFileManager::fnFileSave()
{
	ofstream fsOutput;
	fsOutput.open("UserInfo.txt", ios::trunc);

	for (ClIterator<string, string> Cl_it = Cl_User.fn_getUserInfor().begin(); Cl_it <= Cl_User.fn_getUserInfor().end(); Cl_it++)
	{
		fsOutput << (*Cl_it).first() << " " << (*Cl_it).second() << " " << Cl_Score.fn_getUserScore()[(*Cl_it).first()];
		if (Cl_it != Cl_User.fn_getUserInfor().end())
		{
			fsOutput << endl;
		}
	}

	fsOutput.close();

	return;
}
