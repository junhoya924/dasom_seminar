#include "Game.h"

ClGame::ClGame()
{
	pPlayer[0] = new ClPlayer;
	// pPlayer[1] = new ClComputer;
	pPlayer[1] = new ClPlayer;
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
	/*
	string Cl_name;
	cout << "Your name: ";
	cin >> Cl_name;

	pPlayer[0]->setName(Cl_name);
	pPlayer[1]->setName("Computer");
	*/

	string Cl_player1, Cl_player2;
	cout << "Player1's Name: ";
	cin >> Cl_player1;
	cout << "Player2's Name: ";
	cin >> Cl_player2;

	pPlayer[0]->setName(Cl_player1);
	pPlayer[1]->setName(Cl_player2);

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
				cout << endl << pPlayer[i]->getName() << " Wins!" << endl;
				cout << pPlayer[1-i]->getName() << " Loses!" << endl;

				break;
			}
		}
	}
}