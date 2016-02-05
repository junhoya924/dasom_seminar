#include "GameMap.h"

CGameMap::CGameMap()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			dMapAry[i][j] = 0;
		}
	}
}

CGameMap::~CGameMap()
{
}

void CGameMap::fnRandom() // 랜덤으로 0인 위치에 2생성
{
	srand(time(NULL));
	int nCount = 0;
	int nCount2 = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount++;
			}
		}
	}

	int nRand = rand() % nCount + 1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount2++;
				if (nRand == nCount2)
				{
					dMapAry[i][j] = 2;
				}
			}
		}
	}

	return;
}

void CGameMap::fnLeft()
{
	int nCount;
	for (int i = 0; i < 4; i++)
	{
		nCount = 0;
		//---------------------------------- 모든 값들을 왼쪽으로 밀기 
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4)
		{
			if (dMapAry[i][0] == 0)
			{
				while (dMapAry[i][0] == 0)
				{
					dMapAry[i][0] = dMapAry[i][1];
					dMapAry[i][1] = dMapAry[i][2];
					dMapAry[i][2] = dMapAry[i][3];
					dMapAry[i][3] = 0;
				}
			}
			
			if (dMapAry[i][1] == 0)
			{
				while (dMapAry[i][1] == 0)
				{
					dMapAry[i][1] = dMapAry[i][2];
					dMapAry[i][2] = dMapAry[i][3];
					dMapAry[i][3] = 0;

					if (dMapAry[i][2] == 0)
					{
						break;
					}
				}
			}
			
			if (dMapAry[i][2] == 0)
			{
				dMapAry[i][2] = dMapAry[i][3];
				dMapAry[i][3] = 0;
			}
		}
		//--------------------------------- 같은 값끼리 왼쪽으로 더하기(더 왼쪽일수록 우선순위 높음)
		if (dMapAry[i][0] == dMapAry[i][1])
		{
			dMapAry[i][0] += dMapAry[i][1];
			dMapAry[i][1] = 0;
		}
		if (dMapAry[i][1] == dMapAry[i][2])
		{
			dMapAry[i][1] += dMapAry[i][2];
			dMapAry[i][2] = 0;
		}
		if (dMapAry[i][2] == dMapAry[i][3])
		{
			dMapAry[i][2] += dMapAry[i][3];
			dMapAry[i][3] = 0;
		}
		//---------------------------------- 모든 값들을 왼쪽으로 밀기
		nCount = 0;
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4)
		{
			if (dMapAry[i][0] == 0)
			{
				while (dMapAry[i][0] == 0)
				{
					dMapAry[i][0] = dMapAry[i][1];
					dMapAry[i][1] = dMapAry[i][2];
					dMapAry[i][2] = dMapAry[i][3];
					dMapAry[i][3] = 0;
				}
			}

			if (dMapAry[i][1] == 0)
			{
				while (dMapAry[i][1] == 0)
				{
					dMapAry[i][1] = dMapAry[i][2];
					dMapAry[i][2] = dMapAry[i][3];
					dMapAry[i][3] = 0;

					if (dMapAry[i][2] == 0)
					{
						break;
					}
				}
			}

			if (dMapAry[i][2] == 0)
			{
				dMapAry[i][2] = dMapAry[i][3];
				dMapAry[i][3] = 0;
			}
		}
	}

	return;
}

void CGameMap::fnRight()
{
	int nCount;
	for (int i = 0; i < 4; i++)
	{
		nCount = 0;
		//---------------------------------- 모든 값들을 오른쪽으로 밀기
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4)
		{
			if (dMapAry[i][3] == 0)
			{
				while (dMapAry[i][3] == 0)
				{
					dMapAry[i][3] = dMapAry[i][2];
					dMapAry[i][2] = dMapAry[i][1];
					dMapAry[i][1] = dMapAry[i][0];
					dMapAry[i][0] = 0;
				}
			}

			if (dMapAry[i][2] == 0)
			{
				while (dMapAry[i][2] == 0)
				{
					dMapAry[i][2] = dMapAry[i][1];
					dMapAry[i][1] = dMapAry[i][0];
					dMapAry[i][0] = 0;

					if (dMapAry[i][1] == 0)
					{
						break;
					}
				}
			}

			if (dMapAry[i][1] == 0)
			{
				dMapAry[i][1] = dMapAry[i][0];
				dMapAry[i][0] = 0;
			}
		}
		//--------------------------------- 같은 값끼리 오른쪽으로 더하기(더 오른쪽일수록 우선순위 높음)
		if (dMapAry[i][3] == dMapAry[i][2])
		{
			dMapAry[i][3] += dMapAry[i][2];
			dMapAry[i][2] = 0;
		}
		if (dMapAry[i][2] == dMapAry[i][1])
		{
			dMapAry[i][2] += dMapAry[i][1];
			dMapAry[i][1] = 0;
		}
		if (dMapAry[i][1] == dMapAry[i][0])
		{
			dMapAry[i][1] += dMapAry[i][0];
			dMapAry[i][0] = 0;
		}
		//---------------------------------- 모든 값들을 오른쪽으로 밀기
		nCount = 0;
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4)
		{
			if (dMapAry[i][3] == 0)
			{
				while (dMapAry[i][3] == 0)
				{
					dMapAry[i][3] = dMapAry[i][2];
					dMapAry[i][2] = dMapAry[i][1];
					dMapAry[i][1] = dMapAry[i][0];
					dMapAry[i][0] = 0;
				}
			}
			
			if (dMapAry[i][2] == 0)
			{
				while (dMapAry[i][2] == 0)
				{
					dMapAry[i][2] = dMapAry[i][1];
					dMapAry[i][1] = dMapAry[i][0];
					dMapAry[i][0] = 0;

					if (dMapAry[i][1] == 0)
					{
						break;
					}
				}
			}
			
			if (dMapAry[i][1] == 0)
			{
				dMapAry[i][1] = dMapAry[i][0];
				dMapAry[i][0] = 0;
			}
		}
	}

	return;
}

void CGameMap::fnUp()
{
	int nCount;
	for (int i = 0; i < 4; i++)
	{
		nCount = 0;
		//---------------------------------- 모든 값들을 위쪽으로 밀기
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4) // 0이 1,2,3개일때
		{
			if (dMapAry[0][i] == 0)
			{
				while (dMapAry[0][i] == 0 ) // 무한루프
				{
					dMapAry[0][i] = dMapAry[1][i];
					dMapAry[1][i] = dMapAry[2][i];
					dMapAry[2][i] = dMapAry[3][i];
					dMapAry[3][i] = 0;
				}
			}

			if (dMapAry[1][i] == 0)
			{
				while (dMapAry[1][i] == 0)
				{
					dMapAry[1][i] = dMapAry[2][i];
					dMapAry[2][i] = dMapAry[3][i];
					dMapAry[3][i] = 0;

					if (dMapAry[2][i] == 0)
					{
						break;
					}
				}
			}

			if (dMapAry[2][i] == 0)
			{
				dMapAry[2][i] = dMapAry[3][i];
				dMapAry[3][i] = 0;
			}
		}
		//--------------------------------- 같은 값끼리 위쪽으로 더하기(더 위쪽일수록 우선순위 높음)
		if (dMapAry[0][i] == dMapAry[1][i])
		{
			dMapAry[0][i] += dMapAry[1][i];
			dMapAry[1][i] = 0;
		}
		if (dMapAry[1][i] == dMapAry[2][i])
		{
			dMapAry[1][i] += dMapAry[2][i];
			dMapAry[2][i] = 0;
		}
		if (dMapAry[2][i] == dMapAry[3][i])
		{
			dMapAry[2][i] += dMapAry[3][i];
			dMapAry[3][i] = 0;
		}
		//---------------------------------- 모든 값들을 위쪽으로 밀기
		nCount = 0;
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[i][j] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4) // 0이 1,2,3개일때
		{
			if (dMapAry[0][i] == 0)
			{
				while (dMapAry[0][i] == 0) // 무한루프
				{
					dMapAry[0][i] = dMapAry[1][i];
					dMapAry[1][i] = dMapAry[2][i];
					dMapAry[2][i] = dMapAry[3][i];
					dMapAry[3][i] = 0;
				}
			}

			if (dMapAry[1][i] == 0)
			{
				while (dMapAry[1][i] == 0)
				{
					dMapAry[1][i] = dMapAry[2][i];
					dMapAry[2][i] = dMapAry[3][i];
					dMapAry[3][i] = 0;

					if (dMapAry[2][i] == 0)
					{
						break;
					}
				}
			}

			if (dMapAry[2][i] == 0)
			{
				dMapAry[2][i] = dMapAry[3][i];
				dMapAry[3][i] = 0;
			}
		}
	}

	return;
}

void CGameMap::fnDown()
{
	int nCount;
	for (int i = 0; i < 4; i++)
	{
		nCount = 0;
		//---------------------------------- 모든 값들을 아래쪽으로 밀기
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[j][i] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4) // 0이 1,2,3개일때
		{
			if (dMapAry[3][i] == 0)
			{
				while (dMapAry[3][i] == 0)
				{
					dMapAry[3][i] = dMapAry[2][i];
					dMapAry[2][i] = dMapAry[1][i];
					dMapAry[1][i] = dMapAry[0][i];
					dMapAry[0][i] = 0;
				}
			}
			
			if (dMapAry[2][i] == 0)
			{
				while (dMapAry[2][i] == 0)
				{
					dMapAry[2][i] = dMapAry[1][i];
					dMapAry[1][i] = dMapAry[0][i];
					dMapAry[0][i] = 0;

					if (dMapAry[1][i] == 0)
					{
						break;
					}
				}
			}
			
			if (dMapAry[1][i] == 0)
			{
				dMapAry[1][i] = dMapAry[0][i];
				dMapAry[0][i] = 0;
			}
		}
		//--------------------------------- 같은 값끼리 아래쪽으로 더하기(더 아래쪽일수록 우선순위 높음)
		if (dMapAry[3][i] == dMapAry[2][i])
		{
			dMapAry[3][i] += dMapAry[2][i];
			dMapAry[2][i] = 0;
		}
		if (dMapAry[2][i] == dMapAry[1][i])
		{
			dMapAry[2][i] += dMapAry[1][i];
			dMapAry[1][i] = 0;
		}
		if (dMapAry[1][i] == dMapAry[0][i])
		{
			dMapAry[1][i] += dMapAry[0][i];
			dMapAry[0][i] = 0;
		}
		//---------------------------------- 모든 값들을 아래쪽으로 밀기
		nCount = 0;
		for (int j = 0; j < 4; j++)
		{
			if (dMapAry[j][i] == 0)
			{
				nCount++;
			}
		}

		if (nCount != 0 && nCount != 4) // 0이 1,2,3개일때
		{
			if (dMapAry[3][i] == 0)
			{
				while (dMapAry[3][i] == 0)
				{
					dMapAry[3][i] = dMapAry[2][i];
					dMapAry[2][i] = dMapAry[1][i];
					dMapAry[1][i] = dMapAry[0][i];
					dMapAry[0][i] = 0;
				}
			}

			if (dMapAry[2][i] == 0)
			{
				while (dMapAry[2][i] == 0)
				{
					dMapAry[2][i] = dMapAry[1][i];
					dMapAry[1][i] = dMapAry[0][i];
					dMapAry[0][i] = 0;

					if (dMapAry[1][i] == 0)
					{
						break;
					}
				}
			}

			if (dMapAry[1][i] == 0)
			{
				dMapAry[1][i] = dMapAry[0][i];
				dMapAry[0][i] = 0;
			}
		}
	}

	return;
}
