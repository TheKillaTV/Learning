#include "stdafx.h"
#include "Connect4.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool Connect4::PlayerPiece = 0;
int Connect4::x = 0;
int Connect4::y = 0;
int Connect4::Winner = 0; 
int Connect4::Pieces = 0;

Connect4::Connect4()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			arr[i][j] = Space;
		}
	}
}

void Connect4::PrintBoard()
{
	cout << "  0 " << "  1 " << "  2 " << "  3 " << "  4 " << "  5 " << "  6 " << endl << endl << endl;
	cout << "| " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << " | " << arr[0][3] << " | " << arr[0][4] << " | " << arr[0][5] << " | " << arr[0][6] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "| " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << " | " << arr[1][3] << " | " << arr[1][4] << " | " << arr[1][5] << " | " << arr[1][6] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "| " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << " | " << arr[2][3] << " | " << arr[2][4] << " | " << arr[2][5] << " | " << arr[2][6] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "| " << arr[3][0] << " | " << arr[3][1] << " | " << arr[3][2] << " | " << arr[3][3] << " | " << arr[3][4] << " | " << arr[3][5] << " | " << arr[3][6] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "| " << arr[4][0] << " | " << arr[4][1] << " | " << arr[4][2] << " | " << arr[4][3] << " | " << arr[4][4] << " | " << arr[4][5] << " | " << arr[4][6] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "| " << arr[5][0] << " | " << arr[5][1] << " | " << arr[5][2] << " | " << arr[5][3] << " | " << arr[5][4] << " | " << arr[5][5] << " | " << arr[5][6] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "| " << arr[6][0] << " | " << arr[6][1] << " | " << arr[6][2] << " | " << arr[6][3] << " | " << arr[6][4] << " | " << arr[6][5] << " | " << arr[6][6] << " | " << endl;
	cout << "----------------------------" << endl;
}

void Connect4::PlayerOneTurn()
{
	cout << "Enter 1, 2, 3, 4, 5, or 6 ";
	cin >> p1turn;

	while (p1turn > 6 || p1turn < 0)
	{
		cout << endl;
		cout << "Column does not exist. Please try again: ";
		cin >> p1turn;
	}
}

void Connect4::PutPlayerOnePiece()
{
	for (int i = 6; i >= 0; i--)
	{
		//cout << "I = " << i << endl;
		if (arr[0][p1turn] == p1 || arr[0][p1turn] == p2)
		{
			cout << "This columnn is full. Pick a new one: ";
			cin >> p1turn;
			i++;

			while (p1turn > 6 || p1turn < 0)
			{
				cout << endl;
				cout << "Column does not exist. Please try again: ";
				cin >> p1turn;
			}

		}

		else if (arr[i][p1turn] == p2 || arr[i][p1turn] == p1)
			continue;
		else
		{
			arr[i][p1turn] = p1;
			break;
		}
	}
}

void Connect4::PlayerTwoTurn()
{
	p2turn = rand() % 6 + 0;

	for (int i = 6; i >= 0; i--)
	{
		if (arr[0][p2turn] == p1 || arr[0][p2turn] == p2)
		{
			//cout << "Computer selected a filled column. Picking a new one " << endl;
			p2turn = rand() % 6 + 0;
			i++;
		}
		else if (arr[i][p2turn] == p1 || arr[i][p2turn] == p2)
			continue;
		else
		{
			arr[i][p2turn] = p2;
			break;
		}
	}
}

void Connect4::ScanBoard()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (arr[i][j] == p1)
			{
				PlayerPiece = 0;
				x = i;
				y = j;
				//cout << "Found Player 1 piece at [" << x << "][" << y << "]" << endl;
			}

			else if (arr[i][j] == p2)
			{
				PlayerPiece = 1;
				x = i;
				y = j;
				//cout << "Found Player 2 piece at [" << x << "][" << y << "]" << endl;
			}

			else if (arr[i][j] == Space)
				continue;

			WinnerAlgorithm();
		}
	}
}

void Connect4::WinnerAlgorithm()
{
	if (!PlayerPiece)
	{
		// Up Down Left Right

		if (arr[x][y] == p1 && arr[x - 1][y] == p1 && arr[x - 2][y] == p1 && arr[x - 3][y] == p1 || arr[x][y] == p1 && arr[x][y + 1] == p1 && arr[x][y + 2] == p1
			&& arr[x][y + 3] == p1 || arr[x][y] == p1 && arr[x][y - 1] == p1 && arr[x][y - 2] == p1 && arr[x][y - 3] == p1)
		{
			//cout << "Player 1 Wins!" << endl;
			Winner += 100;
		}

		// Diagonal check in all directions

		else if (arr[x][y] == p1 && arr[x - 1][y + 1] == p1	&& arr[x - 2][y + 2] == p1 && arr[x - 3][y + 3] == p1 || arr[x][y] == p1 
			&& arr[x + 1][y + 1] == p1 && arr[x + 2][y + 2] == p1 && arr[x + 3][y + 3] == p1)
		{
			//cout << "Player 1 Wins! (DIAGONALLY)" << endl;
			Winner += 100;
		}
	}

	else if (PlayerPiece)
	{
		// Up Down Left Right

		if (arr[x][y] == p2 && arr[x - 1][y] == p2 && arr[x - 2][y] == p2 && arr[x - 3][y] == p2 || arr[x][y] == p2 && arr[x][y + 1] == p2 && arr[x][y + 2] == p2
			&& arr[x][y + 3] == p2 || arr[x][y] == p2 && arr[x][y - 1] == p2 && arr[x][y - 2] == p2 && arr[x][y - 3] == p2)
		{
			//cout << "Player 2 Wins!" << endl;
			Winner++;
		}

		// Diagonal check in all directions

		else if (arr[x][y] == p2 && arr[x - 1][y + 1] == p2	&& arr[x - 2][y + 2] == p2 && arr[x - 3][y + 3] == p2 || arr[x][y] == p2 
				&& arr[x + 1][y + 1] == p2 && arr[x + 2][y + 2] == p2 && arr[x + 3][y + 3] == p2)
		{
			//cout << "Player 2 Wins! (DIAGONALLY)" << endl;
			Winner++;
		}
	}
}
