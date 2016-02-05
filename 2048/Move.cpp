#include "Move.h"

CMove::CMove()
{
}

CMove::~CMove()
{
}

bool CMove::fnMove()

{
	int nInput;
	cout << "\tf1을 누르면 프로그램이 종료됩니다." << endl;
	while (true)
	{
		cout << "\t방향키 입력" << endl;
		cout << "\t";
		nInput = getch();
		if (nInput == 0 || nInput == 0x00 || nInput == 224)
		{
			nInput = getch();
		}

		if (nInput == 75)
		{
			fnLeft();
			break;
		}
		else if (nInput == 77)
		{
			fnRight();
			break;
		}
		else if (nInput == 72)
		{
			fnUp();
			break;
		}
		else if (nInput == 80)
		{
			fnDown();
			break;
		}
		else if (nInput == 59)
		{
			return false;
		}
		else
		{
			cout << "\t유효하지 않은 입력입니다." << endl;
		}
	}

	return true;
}
