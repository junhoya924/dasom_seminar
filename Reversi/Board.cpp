#include "Board.h"

ClBoard::ClBoard()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			aString[i][j] = "┼";

	aString[4][4] = "●";
	aString[4][5] = "○";
	aString[5][4] = "○";
	aString[5][5] = "●";
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
				if(aString[i][j] == "●")
				{
					if(i > 0 && aString[i-1][j] == "○")
						for(int k = 2; k < i; k++)
						{
							if(aString[i-k][j] == "○")
								continue;
							else if(aString[i-k][j] == "┼")
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

					if(i < 9 && aString[i+1][j] == "○")
						for(int k = 2; k < 10-i; k++)
						{
							if(aString[i+k][j] == "○")
								continue;
							else if(aString[i+k][j] == "┼")
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

					if(j > 0 && aString[i][j-1] == "○")
						for(int k = 2; k < j; k++)
						{
							if(aString[i][j-k] == "○")
								continue;
							else if(aString[i][j-k] == "┼")
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

					if(j < 9 && aString[i][j+1] == "○")
						for(int k = 2; k < 10-j; k++)
						{
							if(aString[i][j+k] == "○")
								continue;
							else if(aString[i][j+k] == "┼")
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

					if(i > 0 && j > 0 && aString[i-1][j-1] == "○")
					{
						int k = 2;
						while(i-k >= 0 && j-k >= 0)
						{
							if(aString[i-k][j-k] == "○")
								k++;
							else if(aString[i-k][j-k] == "┼")
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

					if(i < 10 && j < 10 && aString[i+1][j+1] == "○")
					{
						int k = 2;
						while(i+k <= 10 && j+k <= 10)
						{
							if(aString[i+k][j+k] == "○")
								k++;
							else if(aString[i+k][j+k] == "┼")
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

					if(i > 0 && j < 10 && aString[i-1][j+1] == "○")
					{
						int k = 2;
						while(i-k >= 0 && j+k <= 10)
						{
							if(aString[i-k][j+k] == "○")
								k++;
							else if(aString[i-k][j+k] == "┼")
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

					if(i < 10 && j > 0 && aString[i+1][j-1] == "○")
					{
						int k = 2;
						while(i+k <= 10 && j-k >= 0)
						{
							if(aString[i+k][j-k] == "○")
								k++;
							else if(aString[i+k][j-k] == "┼")
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
				if(aString[i][j] == "○")
				{
					if(i > 0 && aString[i-1][j] == "●")
						for(int k = 2; k < i; k++)
						{
							if(aString[i-k][j] == "●")
								continue;
							else if(aString[i-k][j] == "┼")
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

					if(i < 9 && aString[i+1][j] == "●")
						for(int k = 2; k < 10-i; k++)
						{
							if(aString[i+k][j] == "●")
								continue;
							else if(aString[i+k][j] == "┼")
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

					if(j > 0 && aString[i][j-1] == "●")
						for(int k = 2; k < j; k++)
						{
							if(aString[i][j-k] == "●")
								continue;
							else if(aString[i][j-k] == "┼")
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

					if(j < 9 && aString[i][j+1] == "●")
						for(int k = 2; k < 10-i; k++)
						{
							if(aString[i][j+k] == "●")
								continue;
							else if(aString[i][j+k] == "┼")
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

					if(i > 0 && j > 0 && aString[i-1][j-1] == "●")
					{
						int k = 2;
						while(i-k >= 0 && j-k >= 0)
						{
							if(aString[i-k][j-k] == "●")
								k++;
							else if(aString[i-k][j-k] == "┼")
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

					if(i < 10 && j < 10 && aString[i+1][j+1] == "●")
					{
						int k = 2;
						while(i+k <= 10 && j+k <= 10)
						{
							if(aString[i+k][j+k] == "●")
								k++;
							else if(aString[i+k][j+k] == "┼")
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

					if(i > 0 && j < 10 && aString[i-1][j+1] == "●")
					{
						int k = 2;
						while(i-k >= 0 && j+k <= 10)
						{
							if(aString[i-k][j+k] == "●")
								k++;
							else if(aString[i-k][j+k] == "┼")
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

					if(i < 10 && j > 0 && aString[i+1][j-1] == "●")
					{
						int k = 2;
						while(i+k <= 10 && j-k >= 0)
						{
							if(aString[i+k][j-k] == "●")
								k++;
							else if(aString[i+k][j-k] == "┼")
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
			if(aString[i][j] != "┼" && aString[i][j] != "●" && aString[i][j] != "○")
				aString[i][j] = "┼";
}

void ClBoard::changeBoard(int nTurn, int* aCoordinate)
{
	if(nTurn == 0)	// white
	{
		// 다 바꾸기
		aString[aCoordinate[0]][aCoordinate[1]] = "●";

		if(aCoordinate[0] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]] == "○")
		{
			for(int i = 1; i < aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]] == "○")
					continue;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "┼")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]] = "●";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aString[aCoordinate[0]+1][aCoordinate[1]] == "○")
		{
			for(int i = 1; i < 10-aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]] == "○")
					continue;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "┼")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]] = "●";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] > 0 && aString[aCoordinate[0]][aCoordinate[1]-1] == "○")
		{
			for(int i = 1; i < aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]-i] == "○")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "┼")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]-j] = "●";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] < 10 && aString[aCoordinate[0]][aCoordinate[1]+1] == "○")
		{
			for(int i = 1; i < 10-aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]+i] == "○")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "┼")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]+j] = "●";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]-1] == "○")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "○")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "┼")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]-j] = "●";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aCoordinate[1] < 10 && aString[aCoordinate[0]+1][aCoordinate[1]+1] == "○")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 10 && aCoordinate[1]+i <= 10)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "○")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "┼")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]+j] = "●";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] < 10 && aString[aCoordinate[0]-1][aCoordinate[1]+1] == "○")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]+i <= 10)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "○")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "┼")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]+j] = "●";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aCoordinate[1] > 0 && aString[aCoordinate[0]+1][aCoordinate[1]-1] == "○")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 10 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "○")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "┼")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "●")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]-j] = "●";

					break;
				}
				else
					break;
			}
		}
	}
	else			// black
	{
		aString[aCoordinate[0]][aCoordinate[1]] = "○";

		if(aCoordinate[0] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]] == "●")
		{
			for(int i = 1; i < aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]] == "●")
					continue;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "┼")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]] = "○";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aString[aCoordinate[0]+1][aCoordinate[1]] == "●")
		{
			for(int i = 1; i < 10-aCoordinate[0]; i++)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]] == "●")
					continue;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "┼")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]] = "○";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] > 0 && aString[aCoordinate[0]][aCoordinate[1]-1] == "●")
		{
			for(int i = 1; i < aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]-i] == "●")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "┼")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]-i] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]-j] = "○";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[1] < 10 && aString[aCoordinate[0]][aCoordinate[1]+1] == "●")
		{
			for(int i = 1; i < 10-aCoordinate[1]; i++)
			{
				if(aString[aCoordinate[0]][aCoordinate[1]+i] == "●")
					continue;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "┼")
					break;
				else if(aString[aCoordinate[0]][aCoordinate[1]+i] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]][aCoordinate[1]+j] = "○";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] > 0 && aString[aCoordinate[0]-1][aCoordinate[1]-1] == "●")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "●")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "┼")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]-i] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]-j] = "○";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aCoordinate[1] < 10 && aString[aCoordinate[0]+1][aCoordinate[1]+1] == "●")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 10 && aCoordinate[1]+i <= 10)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "●")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "┼")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]+i] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]+j] = "○";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] > 0 && aCoordinate[1] < 10 && aString[aCoordinate[0]-1][aCoordinate[1]+1] == "●")
		{
			int i = 2;
			while(aCoordinate[0]-i >= 0 && aCoordinate[1]+i <= 10)
			{
				if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "●")
					i++;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "┼")
					break;
				else if(aString[aCoordinate[0]-i][aCoordinate[1]+i] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]-j][aCoordinate[1]+j] = "○";

					break;
				}
				else
					break;
			}
		}

		if(aCoordinate[0] < 10 && aCoordinate[1] > 0 && aString[aCoordinate[0]+1][aCoordinate[1]-1] == "●")
		{
			int i = 2;
			while(aCoordinate[0]+i <= 10 && aCoordinate[1]-i >= 0)
			{
				if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "●")
					i++;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "┼")
					break;
				else if(aString[aCoordinate[0]+i][aCoordinate[1]-i] == "○")
				{
					for(int j = 0; j < i; j++)
						aString[aCoordinate[0]+j][aCoordinate[1]-j] = "○";

					break;
				}
				else
					break;
			}
		}
	}

	delete aCoordinate;
}

bool ClBoard::endGame()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(aString[i][j] == "┼")
				return false;

	return true;
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