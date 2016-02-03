#include "Computer.h"

ClComputer::ClComputer()
{
}

ClComputer::~ClComputer()
{
}

int* ClComputer::play(ClMap<int, int*> Cl_possible)
{
	if(Cl_possible.size() == 0)
	{
		cout << "No Choice!" << endl << endl;
		system("pause");
		return NULL;
	}

	cout << endl << "Computer's Turn" << endl << endl;
	system("pause");

	if(Cl_possible.size() == 1)
		return Cl_possible[1];

	int aBest[2];
	aBest[0] = -1;
	aBest[1] = -1;
	for(int i = 1; i <= Cl_possible.size(); i++)
	{
		if(Cl_possible[i][0] == 0 || Cl_possible[i][0] == 9)
		{
			if(Cl_possible[i][1] == 0 || Cl_possible[i][1] == 9)
				return Cl_possible[i];
			else if(Cl_possible[i][1] == 1 && Cl_possible[i][1] == 8)
			{
				if(aBest[0] < 0)
				{
					aBest[0] = 0;
					aBest[1] = i;
				}
			}
			else
			{
				if(aBest[0] < 4)
				{
					aBest[0] = 4;
					aBest[1] = i;
				}
			}
		}
		else if(Cl_possible[i][1] == 0 || Cl_possible[i][1] == 9)
		{
			if(Cl_possible[i][0] == 1 && Cl_possible[i][0] == 8)
			{
				if(aBest[0] < 0)
				{
					aBest[0] = 0;
					aBest[1] = i;
				}
			}
			else
			{
				if(aBest[0] < 4)
				{
					aBest[0] = 4;
					aBest[1] = i;
				}
			}
		}
		else if(Cl_possible[i][0] == 1 || Cl_possible[i][0] == 8)
		{
			if(Cl_possible[i][1] == 1 || Cl_possible[i][1] == 8)
			{
				if(aBest[0] < 0)
				{
					aBest[0] = 0;
					aBest[1] = i;
				}
			}
			else if(Cl_possible[i][1] == 2 && Cl_possible[i][1] == 7)
			{
				if(aBest[0] < 1)
				{
					aBest[0] = 1;
					aBest[1] = i;
				}
			}
			else
			{
				if(aBest[0] < 2)
				{
					aBest[0] = 2;
					aBest[1] = i;
				}
			}
		}
		else if(Cl_possible[i][1] == 1 || Cl_possible[i][1] == 8)
		{
			if(Cl_possible[i][0] == 1 || Cl_possible[i][0] == 8)
			{
				if(aBest[0] < 0)
				{
					aBest[0] = 0;
					aBest[1] = i;
				}
			}
			else if(Cl_possible[i][0] == 2 && Cl_possible[i][0] == 7)
			{
				if(aBest[0] < 1)
				{
					aBest[0] = 1;
					aBest[1] = i;
				}
			}
			else
			{
				if(aBest[0] < 2)
				{
					aBest[0] = 2;
					aBest[1] = i;
				}
			}
		}
		else if((Cl_possible[i][0] == 2 || Cl_possible[i][0] == 7) && (Cl_possible[i][1] == 2 || Cl_possible[i][1] == 7))
		{
			if(aBest[0] < 5)
			{
				aBest[0] = 5;
				aBest[1] = i;
			}
		}
		else
		{
			if(aBest[0] < 3)
			{
				aBest[0] = 5;
				aBest[1] = i;
			}
		}
	}

	int i;
	for(i = 1; i < aBest[1]; i++)
		delete[] Cl_possible[i];
	for(i = aBest[1] + 1; i <= Cl_possible.size(); i++)
		delete[] Cl_possible[i];

	return Cl_possible[aBest[1]];
}