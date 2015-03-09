#include "stdafx.h"
#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
	TicTacToe T;
	T.SetBoard(T.Board);
	T.PrintBoard(T.Board);

	while (true)
	{
		T.PlayerOneTurn(T.p1Row, T.p1Column);
		T.ModifiyBoard(T.Board, T.p1Row, T.p1Column, T.X);
		T.pWinner = T.CheckWinner(T.Board, T.pWinner);
		T.Turns++;
		if (T.Turns >= 9)
		{
			T.ClearScreen();
			T.PrintBoard(T.Board);
			cout << " * TIE! *" << endl;
			return 0;
		}

		if (T.pWinner == 1)
		{
			T.ClearScreen();
			T.PrintBoard(T.Board);
			cout << "Player 1 Wins!" << endl;
			return 0;
		}

		else if (T.pWinner == 2)
		{
			T.ClearScreen();
			T.PrintBoard(T.Board);
			cout << "Player 2 Wins!" << endl;
			return 0;
		}

		T.ClearScreen();
		T.PrintBoard(T.Board);
		T.PlayerTwoTurn(T.p2Row, T.p2Column);
		T.ModifiyBoard(T.Board, T.p2Row, T.p2Column, T.O);
		T.pWinner = T.CheckWinner(T.Board, T.pWinner);
		T.Turns++;
		if (T.Turns >= 9)
		{
			T.ClearScreen();
			T.PrintBoard(T.Board);
			cout << "* TIE *!" << endl;
			return 0;
		}

		if (T.pWinner == 1)
		{
			T.ClearScreen();
			T.PrintBoard(T.Board);
			cout << "Player 1 Wins!" << endl;
			return 0;
		}

		else if (T.pWinner == 2)
		{
			T.ClearScreen();
			T.PrintBoard(T.Board);
			cout << "Player 2 Wins!" << endl;
			return 0;
		}

		T.ClearScreen();
		T.PrintBoard(T.Board);
	}
}
