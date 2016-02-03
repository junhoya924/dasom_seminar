#include "Player.h"

ClPlayer::ClPlayer()
{
}

ClPlayer::~ClPlayer()
{
}

int* ClPlayer::play(ClMap<int, int*> Cl_possible)
{
	if(Cl_possible.size() == 0)
	{
		cout << "No Choice!" << endl << endl;
		system("pause");
		return NULL;
	}

	while(1)
	{
		int nChoice;
		cout << endl << Cl_name << "'s Turn: ";
		cin >> nChoice;

		if(nChoice < 1 || nChoice > Cl_possible.size())
			cout << "Wrong!" << endl;
		else
		{
			int i;
			for(i = 1; i < nChoice; i++)
				delete[] Cl_possible[i];
			for(i = nChoice + 1; i <= Cl_possible.size(); i++)
				delete[] Cl_possible[i];

			return Cl_possible[nChoice];
		}
	}
}