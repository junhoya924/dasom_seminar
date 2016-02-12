#include "Game.h"

ClGame::ClGame()
{
}

ClGame::~ClGame()
{
}

ClGame* ClGame::getInstance()
{
	static ClGame Cl_game;
	return &Cl_game;
}

void ClGame::gameProceed()
{
	while(1)
	{
		system("cls");

		int nPerson;
		cout << endl << "FucKHU Reversi" << endl << endl;
		cout << "1. 1P" << endl;
		cout << "2. 2P" << endl << endl;
		cout << "Start: ";
		cin >> nPerson;
	
		if(nPerson == 1)
		{
			system("cls");

			pPlayer[0] = new ClPlayer;
			pPlayer[1] = new ClComputer;

			string Cl_name;
			cout << endl << "Your Name: ";
			cin >> Cl_name;

			pPlayer[0]->setName(Cl_name);
			pPlayer[1]->setName("Computer");

			break;
		}
		else if(nPerson == 2)
		{
			system("cls");

			pPlayer[0] = new ClPlayer;
			pPlayer[1] = new ClPlayer;

			string Cl_player1, Cl_player2;
			cout << endl << "Player1's Name: ";
			cin >> Cl_player1;
			cout << "Player2's Name: ";
			cin >> Cl_player2;

			pPlayer[0]->setName(Cl_player1);
			pPlayer[1]->setName(Cl_player2);

			break;
		}
		else
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}

			cout << endl << "Wrong!" << endl;
			system("pause");
		}
	}

	while(1)
	{
		for(int i = 0; i < 2; i++)
		{
			Cl_board.print();
			Cl_board.changeBoard(i, pPlayer[i]->play(Cl_board.checkBoard(i)));
			Cl_board.cleanBoard();
			
			if(Cl_board.endGame() == true)
			{
				Cl_board.print();

				int* aScore = Cl_board.countGame();

				if(aScore[0] > aScore[1])
				{
					cout << endl << pPlayer[0]->getName() << " Wins! (" << aScore[0] << ")" << endl;
					cout << pPlayer[1]->getName() << " Loses! (" << aScore[1] << ")" << endl << endl;
				}
				else if(aScore[0] < aScore[1])
				{
					cout << endl << pPlayer[0]->getName() << " Loses! (" << aScore[0] << ")" << endl;
					cout << pPlayer[1]->getName() << " Wins! (" << aScore[1] << ")" << endl << endl;
				}
				else
				{
					cout << endl << "Draw!" << endl << endl;
				}

				delete[] aScore;

				system("pause");

				return;
			}
		}
	}
}