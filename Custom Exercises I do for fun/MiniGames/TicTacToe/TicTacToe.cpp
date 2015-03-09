#include "stdafx.h"
#include "TicTacToe.h"
#include <iostream>

using namespace std;

int TicTacToe::Turns = 0;
int TicTacToe::p1Column = 0;
int TicTacToe::p1Row = 0;
int TicTacToe::p2Column = 0;
int TicTacToe::p2Row = 0;
int TicTacToe::pWinner = 0;

void TicTacToe::PrintBoard(char arr[][size])
{
	cout << "---------------------" << endl << endl;
	cout << "     |     |     " << endl;
	cout << "  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << endl;
	cout << "     |     |     " << endl << endl;
	cout << "---------------------" << endl;
}


void TicTacToe::SetBoard(char arr[][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = Blank;
		}
	}

}

void TicTacToe::ModifiyBoard(char arr[][size], int & row, int & column, char & move)
{
	if (arr[row][column] == X || arr[row][column] == O)
	{
		cout << "This spot is already taken. Please try again: " << endl;
		cout << "Row: ";
		cin >> row;
		cin.ignore();

		while (row >= 3 || row < 0)
		{
			cout << "Please enter 0, 1, or 2" << endl;
			cin >> row;
			cin.ignore();
		}

		cout << endl;
		cout << "Column ";
		cin >> column;
		cin.ignore();

		while (column >= 3 || column < 0)
		{
			cout << "Please enter 0, 1, or 2" << endl;
			cin >> column;
			cin.ignore();
		}
		
		ModifiyBoard(Board, row, column, move);
	}
	arr[row][column] = move;
}

void TicTacToe::ClearScreen()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void TicTacToe::PlayerOneTurn(int & p1Row, int & p1Column)
{
	cout << "Player one: Enter the cordinates." << endl;
	cout << "Row:  ";
	cin >> p1Row;
	cin.ignore();

	while (p1Row >= 3 || p1Row < 0)
	{
		cout << "Please enter 0, 1, or 2" << endl;
		cin >> p1Row;
		cin.ignore();
	}

	cout << endl;
	cout << "Column: ";
	cin >> p1Column;
	cin.ignore();

	while (p1Column >= 3 || p1Column < 0)
	{
		cout << "Please enter 0, 1, or 2" << endl;
		cin >> p1Column;
		cin.ignore();
	}
}

int TicTacToe::CheckWinner(char arr[][size], int & pWinner)
{
	// Right, Down, Left, Up
	for (int i = 0, j = 2; i < size, j > 0; i++, j--)
	{
		if ((arr[i][0] == X && arr[i][1] == X && arr[i][2] == X) || (arr[0][i] == X && arr[1][i] == X && arr[2][i] == X))
			pWinner += 1;
		else if ((arr[i][0] == O && arr[i][1] == O && arr[i][2] == O) || (arr[0][i] == O && arr[1][i] == O && arr[2][i] == O))
			pWinner += 2;
		else if ((arr[j][2] == X && arr[j][1] == X && arr[j][0] == X) || (arr[2][j] == X && arr[1][j] == X && arr[0][j] == X))
			pWinner += 1;
		else if ((arr[j][2] == O && arr[j][1] == O && arr[j][0] == O) || (arr[2][j] == O && arr[1][j] == O && arr[0][j] == O))
			pWinner += 2;
	}

	// Diagonal

	if ((arr[0][0] == X && arr[1][1] == X && arr[2][2] == X) || (arr[0][2] == X && arr[1][1] == X && arr[2][0] == X))
		pWinner += 1;
	else if ((arr[0][0] == O && arr[1][1] == O && arr[2][2] == O) || (arr[0][2] == O && arr[1][1] == O && arr[2][0] == O))
		pWinner += 2;

	return pWinner;
}


void TicTacToe::PlayerTwoTurn(int & p2Row, int & p2Column)
{
	cout << "Player two: Enter the cordinates." << endl;
	cout << "Row:  ";
	cin >> p2Row;
	cin.ignore();

	while (p2Row >= 3 || p2Row < 0)
	{
		cout << "Please enter a value between 0 and 2" << endl;
		cin >> p2Row;
		cin.ignore();
	}

	cout << endl;
	cout << "Column: ";
	cin >> p2Column;
	cin.ignore();

	while (p2Column >= 3 || p2Column < 0)
	{
		cout << "Please enter a value between 0 and 3" << endl;
		cin >> p2Column;
		cin.ignore();
	}
}
