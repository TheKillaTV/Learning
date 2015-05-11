// Experimenting with private class members

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int Row = 10;
const int Column = 10;

class Board
{
private:
	char Array[Row][Column];
	char Player = 'P';
	char Food = 'F';
	char Space = '.';
	int FoodCount;
	char Movement;

public:
	Board();
	void PlaceNewFood();
	int GetQuitCount();
	int ModifiyQuitCount();
	int ModifyFoodCount();
	void DisplayFoodCount();
	void DisplayBoard();
	void FindPlayer();
	void PromptPlayer();
	void MovePlayer();
	static int xCord;
	static int yCord;
};

Board::Board()
{
	FoodCount = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			Array[i][j] = Space;
		}
	}

	Array[1][1] = Player;
	PlaceNewFood();
}

int Board::xCord = 0;
int Board::yCord = 0;

void Board::DisplayFoodCount()
{
	cout << "______" << endl << endl;
	cout << "Food: " << FoodCount << "." << endl;
	cout << "______" << endl << endl;
}

int Board::ModifyFoodCount()
{
	return FoodCount++;
}

void Board::PlaceNewFood()
{
	int x = rand() % 9 + 1;
	int y = rand() % 9 + 1;

	while (Array[x][y] == Player)
	{
		 x = rand() % 9 + 1;
		 y = rand() % 9 + 1;
	}

	Array[x][y] = Food;
}

void Board::DisplayBoard()
{
	cout << "Go get the food! " << endl;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			cout << Array[i][j] << " ";
		}
		cout << endl;
	}
}

void Board::FindPlayer()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (Array[i][j] == Player)
			{
				xCord = i;
				yCord = j;
				break;
			}
			else
				continue;
		}
	}

	cout << "Found player at: [" << xCord << "][" << yCord << "] " << endl;
}

void Board::PromptPlayer()
{
	cout << "W = UP " << endl;
	cout << "A = LEFT " << endl;
	cout << "S = DOWN " << endl;
	cout << "D = RIGHT " << endl << endl;
	cin >> Movement;

	if (islower(Movement))
		Movement = toupper(Movement);

	while (Movement != 'W' && Movement != 'A' && Movement != 'S' && Movement != 'D')
	{
		cout << "Invalid option: Try again: ";
		cin >> Movement;
		
		if (islower(Movement))
			Movement = toupper(Movement);
	}
}

void Board::MovePlayer()
{
	if (Movement == 'W')
	{
		if (xCord - 1 < 0)
			cout << "**Can't move there! (UP)**" << endl << endl;

		else if (Array[xCord - 1][yCord] == Food)
		{
			ModifyFoodCount();
			Array[xCord - 1][yCord] = Player;
			Array[xCord][yCord] = Space;
			PlaceNewFood();
		}

		else
		{
			Array[xCord - 1][yCord] = Player;
			Array[xCord][yCord] = Space;
		}
	}

	else if (Movement == 'A')
	{
		if (yCord - 1 < 0)
			cout << "**Can't move there! (LEFT)**" << endl << endl;

		else if (Array[xCord][yCord - 1] == Food)
		{
			ModifyFoodCount();
			Array[xCord][yCord - 1] = Player;
			Array[xCord][yCord] = Space;
			PlaceNewFood();
		}

		else
		{
			Array[xCord][yCord - 1] = Player;
			Array[xCord][yCord] = Space;
		}
	}

	else if (Movement == 'S')
	{
		if (xCord + 1 >= Row)
			cout << "**Can't move there! (DOWN)**" << endl << endl;

		else if (Array[xCord + 1][yCord] == Food)
		{
			ModifyFoodCount();
			Array[xCord + 1][yCord] = Player;
			Array[xCord][yCord] = Space;
			PlaceNewFood();
		}

		else
		{
			Array[xCord + 1][yCord] = Player;
			Array[xCord][yCord] = Space;
		}
	}

	else if (Movement == 'D')
	{
		if (yCord + 1 >= Column)
			cout << "**Can't move there! (RIGHT)**" << endl << endl;

		else if (Array[xCord][yCord + 1] == Food)
		{
			ModifyFoodCount();
			Array[xCord][yCord + 1] = Player;
			Array[xCord][yCord] = Space;
			PlaceNewFood();
		}

		else
		{
			Array[xCord][yCord + 1] = Player;
			Array[xCord][yCord] = Space;
		}
	}
}

int main()
{
	srand(time(NULL));
	Board Test;

	while (true)
	{
		Test.DisplayFoodCount();
		Test.DisplayBoard();
		Test.FindPlayer();
		Test.PromptPlayer();
		Test.MovePlayer();
	}
}
