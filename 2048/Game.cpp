#include "Game.h"

CGame::CGame()
{
	fnFileLoad();
}

CGame::~CGame()
{
}

void CGame::fnIntro()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t■■■■■■　　■■■■■■　　■　　■　　　　■■■■■■" << endl;
	cout << "\t\t　　　　　■　　■　　　　■　　■　　■　　　　■　　　　■" << endl;
	cout << "\t\t　　　　　■　　■　　　　■　　■　　■　　　　■　　　　■" << endl;
	cout << "\t\t　　　　　■　　■　　　　■　　■　　■　　　　■　　　　■" << endl;
	cout << "\t\t■■■■■■　　■　　　　■　　■■■■■■　　■■■■■■" << endl;
	cout << "\t\t■　　　　　　　■　　　　■　　　　　■　　　　■　　　　■" << endl;
	cout << "\t\t■　　　　　　　■　　　　■　　　　　■　　　　■　　　　■" << endl;
	cout << "\t\t■　　　　　　　■　　　　■　　　　　■　　　　■　　　　■" << endl;
	cout << "\t\t■■■■■■　　■■■■■■　　　　　■　　　　■■■■■■" << endl;
	cout << endl << endl;

	return;
}

bool CGame::IsEnd()
{
	// 게임 종료조건
	int nCount = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0) { nCount++; }
		}
	}
	
	if (nCount == 0) // 0이 한개도 없으면
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == 0)
				{
					if (j != 3)
					{
						if (dMapAry[i][j] == dMapAry[i][j + 1] || dMapAry[i][j] == dMapAry[i + 1][j]) { return false; }
					}
					else
					{
						if (dMapAry[i][j] == dMapAry[i + 1][j]) { return false; }
					}
				}
				else if (i == 1 || i == 2)
				{
					if (j != 3)
					{
						if (dMapAry[i][j] == dMapAry[i][j + 1] || dMapAry[i][j] == dMapAry[i + 1][j]) { return false; }
					}
					else
					{
						if (dMapAry[i][j] == dMapAry[i + 1][j]) { return false; }
					}
				}
				else
				{
					if (j != 3)
					{
						if (dMapAry[i][j] == dMapAry[i][j + 1]) { return false; }
					}
				}
			}
		}
	}
	else
	{
		return false;
	}

	return true; // 종료조건 만족
}

void CGame::fnRun()
{
	int nHighest = 0;
	fnIntro();
	cout << "\t\t\t";

	while (true)
	{
		system("pause");
		system("cls");

		fnIntro();
		cout << "\t\t\t1. 회원가입\t2.로그인" << endl;
		cout << "\t\t\t->";
		int nChoose;
		cin >> nChoose;

		if (nChoose == 1)
		{
			system("cls");
			fnIntro();
			sPlayer = Cl_User.fnJoin();
			Cl_Score.fnInsert(sPlayer, 0);
			system("pause");
			break;
		}
		else if (nChoose == 2)
		{
			system("cls");
			fnIntro();
			sPlayer = Cl_User.fnLogIn();
			break;
		}
		else
		{
			cout << "\t\t\t유효하지 않은 입력입니다." << endl;
		}
	}

	while (true)
	{
		system("cls");
		fnRandom();

		cout << endl << endl;
		cout << "\t┌───────────────┐" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << "\t│";
			for (int j = 0; j < 4; j++)
			{
				cout << dMapAry[i][j] << "\t";
			}
			cout << "│\t";
			if (i == 0)
			{
				cout << "Player : " << sPlayer;
			}
			else if (i == 1)
			{
				cout << "개인 최고점수 : " << Cl_Score.fnPersonalHighestScore(sPlayer);
			}
			else if (i == 2)
			{
				cout << "전체 최고점수 : " << Cl_Score.fnTotalHigestScore();
			}

			cout << endl;
		}
		cout << "\t└───────────────┘" << endl << endl;

		if (!IsEnd()) // 게임 종료 조건을 만족하지 못하면 게임 진행
		{
			if (!fnMove()) // f1눌렀을때
			{
				cout << "Bye!" << endl;
				cout << "\t";
				break;
			}
			else // 점수 갱신 확인
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (nHighest < dMapAry[i][j])
						{
							nHighest = dMapAry[i][j]; // 현재 판에서 가장 높은 점수
						}
					}
				}

				if (Cl_Score.fnPersonalHighestScore(sPlayer) < nHighest)
				{
					Cl_Score.fn_getUserScore()[sPlayer] = nHighest; // 개인 최고점수 갱신

					if (Cl_Score.fnTotalHigestScore() < nHighest)
					{
						Cl_Score.fn_setTotalHigestScore(nHighest); // 전체 최고점수 갱신
					}
				}
			}
		}
		else
		{
			cout << "You Lose!" << endl;
			cout << "\t";
			break;
		}
	}

	fnFileSave();

	return;
}
