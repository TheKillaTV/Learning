#include "stdafx.h"
#include "Connect4.h"
#include <iostream>

using namespace std;

Connect4::Connect4()
{
	this->p1 = 'X';
	this->p2 = 'O';
	this->space = ' ';
	this->TurnCount = 0;
	this->p1Column = 0;
	this->p2Column = 0;
	this->p1x = 0, this->p1y = 0;
	this->p2x = 0, this->p2y = 0;
	this->WinCount = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			arr[i][j] = space;
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

char Connect4::Getp1Column()
{
	cout << "Enter a column ";
	cin >> p1Column;

	while (p1Column > 6 || p1Column < 0)
	{
		cout << "Input " << p1Column << " is not one of the columns. Please try again: ";
		cin >> p1Column;
		cout << endl;
	}

	while (CheckIfMoveIsAllowed(p1Column))
	{
		cout << "This column is full. Please pick another one: ";
		cin >> p1Column;
		cout << endl;
	}

	return p1Column;
}

char Connect4::Getp2Column()
{
	p2Column = rand() % 7 + 0;

	while (CheckIfMoveIsAllowed(p2Column))
	{
		//cout << "DEBUG: CPU tried to put a piece in a full column: " << p2Column << "." << endl;
		p2Column = rand() % 7 + 0;
		//cout << "DEBUG: New column: " << p2Column << "." << endl;
	}

	//cout << "p2 column is: " << p2Column << endl;
	return p2Column;
}

void Connect4::ModifyBoard(int Column)
{
	for (int i = 6; i >= 0; i--)
	{
		if (arr[i][Column] == p1 || arr[i][Column] == p2)
			continue;
		
		if (TurnCount % 2 == 0)
		{
			arr[i][Column] = p1;
			break;
		}

		else if (TurnCount % 2 != 0)
		{
			arr[i][Column] = p2;
			break;
		}
	}
}

bool Connect4::CheckIfMoveIsAllowed(int Column)
{
	if (arr[0][Column] == p1 || arr[0][Column] == p2)
		return true;
	else
		return false;
}

void Connect4::WinnerAlgorithm(int x, int y)
{
	if (TurnCount % 2 == 0)
	{
		if (arr[x][y] == p1 && arr[x - 1][y] == p1 && arr[x - 2][y] == p1 && arr[x - 3][y] == p1 || arr[x][y] == p1 && arr[x][y + 1] == p1 && arr[x][y + 2] == p1
			&& arr[x][y + 3] == p1 || arr[x][y] == p1 && arr[x][y - 1] == p1 && arr[x][y - 2] == p1 && arr[x][y - 3] == p1)
		{
			WinCount += 100;
		}

		else if (arr[x][y] == p1 && arr[x - 1][y + 1] == p1 && arr[x - 2][y + 2] == p1 && arr[x - 3][y + 3] == p1 || arr[x][y] == p1
			&& arr[x + 1][y + 1] == p1 && arr[x + 2][y + 2] == p1 && arr[x + 3][y + 3] == p1)
		{
			WinCount += 100;
		}
	}

	else
	{
		if (arr[x][y] == p2 && arr[x - 1][y] == p2 && arr[x - 2][y] == p2 && arr[x - 3][y] == p2 || arr[x][y] == p2 && arr[x][y + 1] == p2 && arr[x][y + 2] == p2
			&& arr[x][y + 3] == p2 || arr[x][y] == p2 && arr[x][y - 1] == p2 && arr[x][y - 2] == p2 && arr[x][y - 3] == p2)
		{
			WinCount++;
		}

		else if (arr[x][y] == p2 && arr[x - 1][y + 1] == p2 && arr[x - 2][y + 2] == p2 && arr[x - 3][y + 3] == p2 || arr[x][y] == p2
			&& arr[x + 1][y + 1] == p2 && arr[x + 2][y + 2] == p2 && arr[x + 3][y + 3] == p2)
		{
			WinCount++;
		}
	}
}

void Connect4::ScanBoard()
{
	if (TurnCount % 2 == 0)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				if (arr[i][j] == p1)
				{
					p1x = i;
					p1y = j;
					WinnerAlgorithm(p1x, p1y);
				}
				else
					continue;
			}
		}
	}

	else
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				if (arr[i][j] == p2)
				{
					p2x = i;
					p2y = j;
					WinnerAlgorithm(p2x, p2y);
				}
				else
					continue;
			}
		}
	}
}

/*void Connect4::ShowWinner()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			arr[i][j] = space;
		}
	}

	if (WinCount >= 100)
	{
		arr[p1x][p1y] = p1;
		arr[p1x]
	}
}
*/

/*char Connect4::GetAnswer()
{
	cout << "A. Yes" << endl;
	cout << "Not A. No" << endl;
	cin >> Answer;

	if (islower(Answer))
		Answer = toupper(Answer);

	switch (Answer)
	{
	case 'A':
		ShowWinner();
		break;
	default:
		break;
	}
}
*/
