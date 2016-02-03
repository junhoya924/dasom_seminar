#include "Board.h"

ClBoard::ClBoard()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			aString[i][j] = "¦«";

	aString[4][4] = "¡Ü";
	aString[4][5] = "¡Û";
	aString[5][4] = "¡Û";
	aString[5][5] = "¡Ü";
}

ClBoard::~ClBoard()
{
}

ClMap<int, int*> ClBoard::checkBoard(int nTurn)
{
	ClMap<int, int*> Cl_possible;
	int cCount = 1;

	if(nTurn == 0)	// white
	{
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				if(aString[i][j] == "¡Ü")
				{
					if(i > 0 && aString[i-1][j] == "¡Û")
						for(int k = 2; k <= i; k++)
						{
							if(aString[i-k][j] == "¡Û")
								continue;
							else if(aString[i-k][j] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i-k;
								aCoordinate[1] = j;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i-k][j] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(i < 9 && aString[i+1][j] == "¡Û")
						for(int k = 2; k <= 10-i; k++)
						{
							if(aString[i+k][j] == "¡Û")
								continue;
							else if(aString[i+k][j] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i+k;
								aCoordinate[1] = j;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i+k][j] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(j > 0 && aString[i][j-1] == "¡Û")
						for(int k = 2; k <= j; k++)
						{
							if(aString[i][j-k] == "¡Û")
								continue;
							else if(aString[i][j-k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i;
								aCoordinate[1] = j-k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i][j-k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(j < 9 && aString[i][j+1] == "¡Û")
						for(int k = 2; k <= 10-j; k++)
						{
							if(aString[i][j+k] == "¡Û")
								continue;
							else if(aString[i][j+k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i;
								aCoordinate[1] = j+k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
 								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i][j+k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(i > 0 && j > 0 && aString[i-1][j-1] == "¡Û")
					{
						int k = 2;
						while(i-k >= 0 && j-k >= 0)
						{
							if(aString[i-k][j-k] == "¡Û")
								k++;
							else if(aString[i-k][j-k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i-k;
								aCoordinate[1] = j-k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i-k][j-k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}

					if(i < 9 && j < 9 && aString[i+1][j+1] == "¡Û")
					{
						int k = 2;
						while(i+k <= 9 && j+k <= 9)
						{
							if(aString[i+k][j+k] == "¡Û")
								k++;
							else if(aString[i+k][j+k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i+k;
								aCoordinate[1] = j+k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i+k][j+k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}

					if(i > 0 && j < 9 && aString[i-1][j+1] == "¡Û")
					{
						int k = 2;
						while(i-k >= 0 && j+k <= 9)
						{
							if(aString[i-k][j+k] == "¡Û")
								k++;
							else if(aString[i-k][j+k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i-k;
								aCoordinate[1] = j+k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i-k][j+k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}

					if(i < 9 && j > 0 && aString[i+1][j-1] == "¡Û")
					{
						int k = 2;
						while(i+k <= 9 && j-k >= 0)
						{
							if(aString[i+k][j-k] == "¡Û")
								k++;
							else if(aString[i+k][j-k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i+k;
								aCoordinate[1] = j-k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i+k][j-k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}
				}
	}
	else			// black
	{
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				if(aString[i][j] == "¡Û")
				{
					if(i > 0 && aString[i-1][j] == "¡Ü")
						for(int k = 2; k <= i; k++)
						{
							if(aString[i-k][j] == "¡Ü")
								continue;
							else if(aString[i-k][j] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i-k;
								aCoordinate[1] = j;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i-k][j] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(i < 9 && aString[i+1][j] == "¡Ü")
						for(int k = 2; k <= 10-i; k++)
						{
							if(aString[i+k][j] == "¡Ü")
								continue;
							else if(aString[i+k][j] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i+k;
								aCoordinate[1] = j;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i+k][j] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(j > 0 && aString[i][j-1] == "¡Ü")
						for(int k = 2; k <= j; k++)
						{
							if(aString[i][j-k] == "¡Ü")
								continue;
							else if(aString[i][j-k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i;
								aCoordinate[1] = j-k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i][j-k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(j < 9 && aString[i][j+1] == "¡Ü")
						for(int k = 2; k <= 10-i; k++)
						{
							if(aString[i][j+k] == "¡Ü")
								continue;
							else if(aString[i][j+k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i;
								aCoordinate[1] = j+k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i][j+k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}

					if(i > 0 && j > 0 && aString[i-1][j-1] == "¡Ü")
					{
						int k = 2;
						while(i-k >= 0 && j-k >= 0)
						{
							if(aString[i-k][j-k] == "¡Ü")
								k++;
							else if(aString[i-k][j-k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i-k;
								aCoordinate[1] = j-k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i-k][j-k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}

					if(i < 9 && j < 9 && aString[i+1][j+1] == "¡Ü")
					{
						int k = 2;
						while(i+k <= 9 && j+k <= 9)
						{
							if(aString[i+k][j+k] == "¡Ü")
								k++;
							else if(aString[i+k][j+k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i+k;
								aCoordinate[1] = j+k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i+k][j+k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}

					if(i > 0 && j < 9 && aString[i-1][j+1] == "¡Ü")
					{
						int k = 2;
						while(i-k >= 0 && j+k <= 9)
						{
							if(aString[i-k][j+k] == "¡Ü")
								k++;
							else if(aString[i-k][j+k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i-k;
								aCoordinate[1] = j+k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i-k][j+k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}

					if(i < 9 && j > 0 && aString[i+1][j-1] == "¡Ü")
					{
						int k = 2;
						while(i+k <= 9 && j-k >= 0)
						{
							if(aString[i+k][j-k] == "¡Ü")
								k++;
							else if(aString[i+k][j-k] == "¦«")
							{
								int* aCoordinate = new int[2];
								aCoordinate[0] = i+k;
								aCoordinate[1] = j-k;
								ClPair<int, int*> Cl_pair(cCount, aCoordinate);
								Cl_possible.insert(Cl_pair);

								stringstream Cl_ss;
								Cl_ss << cCount;
								if(cCount < 10)
									Cl_ss << " ";
								aString[i+k][j-k] = Cl_ss.str();

								cCount++;

								break;
							}
							else
								break;
						}
					}
				}
	}

	print();

	return Cl_possible;
}

void ClBoard::cleanBoard()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(aString[i][j] != "¦«" && aString[i][j] != "¡Ü" && aString[i][j] != "¡Û")
				aString[i][j] = "¦«";
}

void ClBoard::changeBoard(int nTurn, int* aCoordinate)
{
	if(aCoordinate == NULL)
		return;

	if(nTurn == 0)	// white
	{
		aString[aCoordinate[0]][aCoordinate[1]] = "¡Ü";

		if(aCoordinate[0] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]] == "¡Û")
		{
			for(int i = 1; i <= aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]] == "¡Û")
					continue;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "¦«")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]] = "¡Ü";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aString[aCoordinate[0]+1][aCoordinate[1]] == "¡Û")
		{
			for(int i = 1; i <= 10-aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]] == "¡Û")
					continue;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "¦«")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]] = "¡Ü";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] > 0 && aString[aCoordinate[0]][aCoordinate[1]-1] == "¡Û")
		{
			for(int i = 1; i <= aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]-i] == "¡Û")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "¦«")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]-j] = "¡Ü";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] < 10 && aString[aCoordinate[0]][aCoordinate[1]+1] == "¡Û")
		{
			for(int i = 1; i <= 10-aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]+i] == "¡Û")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "¦«")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]+j] = "¡Ü";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]-1] == "¡Û")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "¡Û")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "¦«")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]-j] = "¡Ü";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 9 && aCoordinate[1] < 9 && aString[aCoordinate[0]+1][aCoordinate[1]+1] == "¡Û")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 9 && aCoordinate[1]+i <= 9)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "¡Û")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "¦«")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]+j] = "¡Ü";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] < 9 && aString[aCoordinate[0]-1][aCoordinate[1]+1] == "¡Û")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]+i <= 9)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "¡Û")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "¦«")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]+j] = "¡Ü";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 9 && aCoordinate[1] > 0 && aString[aCoordinate[0]+1][aCoordinate[1]-1] == "¡Û")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 9 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "¡Û")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "¦«")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "¡Ü")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]-j] = "¡Ü";

					break;
				}
				else
					break;
			}
		}
	}
	else			// black
	{
		aString[aCoordinate[0]][aCoordinate[1]] = "¡Û";

		if(aCoordinate[0] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]] == "¡Ü")
		{
			for(int i = 1; i <= aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]] == "¡Ü")
					continue;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "¦«")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]] = "¡Û";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aString[aCoordinate[0]+1][aCoordinate[1]] == "¡Ü")
		{
			for(int i = 1; i <= 10-aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]] == "¡Ü")
					continue;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "¦«")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]] = "¡Û";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] > 0 && aString[aCoordinate[0]][aCoordinate[1]-1] == "¡Ü")
		{
			for(int i = 1; i <= aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]-i] == "¡Ü")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "¦«")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]-j] = "¡Û";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] < 10 && aString[aCoordinate[0]][aCoordinate[1]+1] == "¡Ü")
		{
			for(int i = 1; i <= 10-aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]+i] == "¡Ü")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "¦«")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]+j] = "¡Û";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]-1] == "¡Ü")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "¡Ü")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "¦«")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]-j] = "¡Û";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 9 && aCoordinate[1] < 9 && aString[aCoordinate[0]+1][aCoordinate[1]+1] == "¡Ü")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 9 && aCoordinate[1]+i <= 9)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "¡Ü")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "¦«")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]+j] = "¡Û";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] < 9 && aString[aCoordinate[0]-1][aCoordinate[1]+1] == "¡Ü")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]+i <= 9)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "¡Ü")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "¦«")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]+j] = "¡Û";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 9 && aCoordinate[1] > 0 && aString[aCoordinate[0]+1][aCoordinate[1]-1] == "¡Ü")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 9 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "¡Ü")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "¦«")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "¡Û")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]-j] = "¡Û";

					break;
				}
				else
					break;
			}
		}
	}

	delete[] aCoordinate;
}

bool ClBoard::endGame()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(aString[i][j] == "¦«")
				return false;

	return true;
}

int* ClBoard::countGame()
{
	int* aScore = new int[2];
	aScore[0] = 0;

	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(aString[i][j] == "¡Ü")
				aScore[0]++;

	aScore[1] = 100 - aScore[0];

	return aScore;
}

void ClBoard::print()
{
	system("cls");

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
			cout << aString[i][j];
		cout << endl;
	}
}