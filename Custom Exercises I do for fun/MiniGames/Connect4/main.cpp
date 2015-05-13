#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Connect4.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Connect4 Test;

	while (true)
	{
		Test.PrintBoard();
		Test.PlayerOneTurn();
		Test.PutPlayerOnePiece();
		Test.ScanBoard();

		if (Test.Pieces >= 49)
		{
			Test.PrintBoard();
			cout << "Draw!" << endl;
			break;
		}

		else if (Test.Winner >= 100) // Big number for p1 incase it detectes two connect 4's at once.
		{
			Test.PrintBoard();
			cout << "Player 1 wins! " << endl;
			break;
		}

		Test.PrintBoard();
		Test.PlayerTwoTurn();
		Test.ScanBoard();

		if (Test.Pieces >= 49)
		{
			Test.PrintBoard();
			cout << "Draw! " << endl;
			break;
		}

		else if (Test.Winner >= 1)
		{
			Test.PrintBoard();
			cout << "Player 2 wins! " << endl;
			break;
		}
	}
}
