#include "User.h"

CUser::CUser()
{
}

CUser::~CUser()
{
}

void CUser::fnInsert(string ID, string PW)
{
	UserInfor.insert(ClPair<string, string>(ID, PW));
	return;
}

string CUser::fnJoin()
{
	string sID;
	string sPassWard;

	cout << "\t\t\tID : ";
	cin >> sID;
	cout << "\t\t\tPassWard : ";
	cin >> sPassWard;

	UserInfor.insert(ClPair<string, string>(sID, sPassWard));
	cout << "\t\t\t가입되었습니다!" << endl;
	return sID;
}

string CUser::fnLogIn()
{
	string sID;
	string sPassWard;

	while (true)
	{
		cout << "\t\t\tID : ";
		cin >> sID;
		cout << "\t\t\tPassWard : ";
		cin >> sPassWard;

		if (UserInfor.search(sID, sPassWard)) // 일치하는 사용자가 있으면
		{
			break;
		}
		else
		{
			cout << "\t\t\t일치하는 사용자가 없습니다." << endl << endl;
		}
	}

	return sID;
}

ClMap<string, string> CUser::fn_getUserInfor()
{
	return UserInfor;
}
