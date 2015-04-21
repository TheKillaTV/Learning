/*Requires:
variables, data types, and numerical operators
basic input / output
logic(if statements, switch statements)
loops(for, while, do - while)
arrays

Make a program that outputs a simple grid based gameboard to the screen using either numbers or characters.
i.e.

. . . . . . . . . .
.G . . . . . . . .
. . . . ..T . . .
. . . . . . . . . .
. . ..T . . . . .
. . . . ..T . . .
. . . . . . . ..X


or

0 0 0 0 0 0 0 0 0 0
0 5 0 0 6 0 0 0 0 0
0 0 0 0 0 0 7 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 7 0 0 0 0 0 0
0 0 0 0 0 0 7 0 0 0
0 0 0 0 0 0 0 0 0 4


Allow the user(marked by G in the example) to move either up, down, left, or right each turn.If the player steps on a trap then they lose.If the make it to the treasure 'X' then they win.

★★ Add enemies that move randomly in any direction once per turn. (enemies just like traps cause the player to lose if touched)

HINT: Don't let the player move off the gameboard! Your program will crash if they move off the top or bottom of the board!
	  (the same holds true for enemies)
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

const int Row = 9, Column = 6;

class Board
{
public:

	int WinStatus = 0;
	int Direction = 0;
	int xCord = 0;
	int yCord = 0;
	int xECord = 0;
	int yECord = 0;
	char board[Row][Column];
	char Movement;
	char Player = 'G', Trap = 'T', Treasure = 'X', Space = '.', Enemy = 'Z';

	void SetBoard(char board[][Column]);
	void SetEnemiesAndTraps(char board[][Column]);
	void DisplayBoard(char board[][Column]);
	void MovePlayer(char board[][Column], char & Movement, int & WinStatus, int & xCord, int & yCord);
	void PromptPlayer(char & Movement);
	void MoveEnemy(char board[][Column], int & Direction, int & Winstatus, int & xECord, int & yECord);
	void FindPlayer(char board[][Column], int & xCord, int & yCord);

};

void Board::SetBoard(char board[][Column])
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			board[i][j] = Space;
		}
	}

	board[1][1] = Player;
	board[7][4] = Treasure;
}


void Board::SetEnemiesAndTraps(char board[][Column])
{
	for (int i = 0; i < 6; i++)
	{
		int x = rand() % 8 + 1;
		int y = rand() % 5 + 1;

		while (board[x][y] == Player || board[x][y] == Treasure || board[x][y] == Enemy || board[x][y] == Trap)
		{
			cout << "Can't randomly put enemy at CORDS [" << x << "][" << y << "] because an enemy, treasure, or player is already there! Generating a new spot..." << endl;
			x = rand() % 8 + 1;
			y = rand() & 5 + 1;
			//continue; This is not neccessary
		}
		
		if (i < 3)
			board[x][y] = Enemy;
		else
			board[x][y] = Trap;
	}
}
void Board::DisplayBoard(char board[][Column])
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void Board::MovePlayer(char board[][Column], char & Movement, int & WinStatus, int & Xcord, int & yCord)
{
	if (Movement == 'W')
	{
		if (Xcord - 1 < 0)
			cout << "**Can't move there! (UP)**" << endl << endl;

		else if (board[Xcord - 1][yCord] == Trap)
		{
			WinStatus++;
			cout << "** YOU LOSE! YOU HIT A TRAP !!! ** " << endl << endl;

		}

		else if (board[Xcord - 1][yCord] == Enemy)
		{
			WinStatus++;
			cout << "** YOU LOSE! YOU HIT AN ENEMY !!! ** " << endl << endl;

		}
		else if (board[Xcord - 1][yCord] == Treasure)
		{
			WinStatus++;
			cout << "** YOU WIN! YOU FOUND THE TREASURE !!! ** " << endl << endl;
		}

		else
		{
			board[Xcord - 1][yCord] = Player;
			board[Xcord][yCord] = Space;
		}
	}

	else if (Movement == 'A')
	{
		if (yCord - 1 < 0)
			cout << "**Can't move there! (LEFT)**" << endl << endl;

		else if (board[Xcord][yCord - 1] == Trap)
		{
			WinStatus++;
			cout << "** YOU LOSE! YOU HIT A TRAP !!! ** " << endl << endl;
		}

		else if (board[Xcord][yCord - 1] == Enemy)
		{
			WinStatus++;
			cout << "** YOU LOSE! YOU HIT AN ENEMY !!! ** " << endl << endl;
		}

		else if (board[Xcord][yCord - 1] == Treasure)
		{
			WinStatus++;
			cout << "** YOU WIN! YOU FOUND THE TREASURE !!! ** " << endl << endl;
		}

		else
		{
			board[Xcord][yCord - 1] = Player;
			board[xCord][yCord] = Space;
		}
	}

	else if (Movement == 'S')
	{
		if (Xcord + 1 >= Row)
			cout << "**Can't move there! (DOWN)**" << endl << endl;

		else if (board[Xcord + 1][yCord] == Trap)
		{
			WinStatus++;
			cout << "** YOU LOSE! YOU HIT A TRAP !!! ** " << endl << endl;
		}

		else if (board[Xcord + 1][yCord] == Enemy)
		{
			WinStatus++;
			cout << "YOU LOSE! YOU HIT AN ENEMY !!! ** " << endl << endl;

		}
		else if (board[Xcord + 1][yCord] == Treasure)
		{
			cout << "** YOU WIN! YOU FOUND THE TREASURE !!! ** " << endl << endl;
		}

		else
		{
			board[Xcord + 1][yCord] = Player;
			board[Xcord][yCord] = Space;
		}
	}

	else if (Movement == 'D')
	{
		if (yCord + 1 >= Column)
			cout << "**Can't move there! (RIGHT)**" << endl << endl;
		

		else if (board[Xcord][yCord + 1] == Trap)
		{
			WinStatus++;
			cout << "** YOU LOSE! YOU HIT A TRAP !!! ** " << endl << endl;

		}

		else if (board[Xcord][yCord + 1] == Enemy)
		{
			WinStatus++;
			cout << "YOU LOSE! YOU HIT AN ENEMY !!! ** " << endl << endl;
		}
		else if (board[Xcord][yCord + 1] == Treasure)
		{
			WinStatus++;
			cout << "** YOU WIN! YOU FOUND THE TREASURE !!! ** " << endl << endl;
		}

		else
		{
			board[Xcord][yCord + 1] = Player;
			board[Xcord][yCord] = Space;
		}
	}
}

void Board::MoveEnemy(char board[][Column], int & Direction, int & WinStatus, int & xECord, int & yECord)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (board[i][j] == Enemy)
			{
				xECord = i;
				yECord = j;

				Direction = rand() % 4 + 1;

				if (Direction == 1) // W
				{
					if (xECord - 1 < 0)
					{
						//cout << "DEBUG. ENEMY CAN'T MOVE UP!" << endl;
						continue;
					}

					else if (board[xECord - 1][yECord] == Enemy || board[xECord - 1][yECord] == Trap || board[xECord - 1][yECord] == Treasure)
					{
						//cout << "DEBUG: ENEMY CAN'T MOVE UP BECAUSE A TRAP, TREASURE, OR ANOTHER ENEMY IS THERE" << endl;
						continue;
					}

					else if (board[xECord - 1][yECord] == Player)
					{
						WinStatus++;
						cout << "** GAME OVER !!! AN ENEMY HAS HIT YOU !!! ** " << endl;
						break;
					}

					else
					{
						board[xECord - 1][yECord] = Enemy;
						board[xECord][yECord] = Space;
						continue;
					}
				}
				else if (Direction == 2) // A
				{
					if (yECord - 1 < 0)
					{
						//cout << "DEBUG. ENEMY CAN'T MOVE LEFT!" << endl;
						continue;
					}

					else if (board[xECord][yECord - 1] == Enemy || board[xECord][yECord - 1] == Trap || board[xECord][yECord - 1] == Treasure)
					{
						//cout << "DEBUG: ENEMY CAN'T MOVE LEFT BECAUSE OF A TRAP, TREASURE, OR ANOTHER ENEMY IS THERE" << endl;
						continue;
					}

					else if (board[xECord][yECord - 1] == Player)
					{
						WinStatus++;
						cout << "** GAME OVER !!! AN ENEMY HAS HIT YOU !!! ** " << endl;
						break;
					}

					else
					{
						board[xECord][yECord - 1] = Enemy;
						board[xECord][yECord] = Space;
						continue;
					}
				}
				else if (Direction == 3) // S
				{
					if (xECord + 1 >= Row)
					{
						//cout << "DEBUG: ENEMY CAN'T MOVE DOWN!" << endl;
						continue;
					}

					else if (board[xECord + 1][yECord] == Enemy || board[xECord + 1][yECord] == Trap || board[xECord + 1][yECord] == Treasure)
					{
						//cout << "DEBUG: ENEMY CAN'T MOVE DOWN BECAUSE OF A TRAP, TREASURE, OR ANOTHER ENEMY IS THERE" << endl;
						continue;
					}

					else if (board[xECord + 1][yECord] == Player)
					{
						WinStatus++;
						cout << "** GAME OVER !!! AN ENEMY HAS HIT YOU !!! ** " << endl;
						break;
					}

					else
					{
						board[xECord + 1][yECord] = Enemy;
						board[xECord][yECord] = Space;
						continue;
					}
				}

				else if (Direction == 4) // D
				{
					if (yECord + 1 >= Column)
					{
						//cout << "DEBUG! ENEMY CAN'T MOVE RIGHT!" << endl;
						continue;
					}

					else if (board[xECord][yECord + 1] == Enemy || board[xECord][yECord + 1] == Trap || board[xECord][yECord + 1] == Treasure)
					{
						//cout << "DEBUG: ENEMY CAN'T MOVE RIGHT BECAUSE OF A TRAP, TREASURE, OR ANOTHER ENEMY IS THERE" << endl;
						continue;
					}

					else if (board[xECord][yECord + 1] == Player)
					{
						WinStatus++;
						cout << "** GAME OVER !!! AN ENEMY HAS HIT YOU !!! ** " << endl;
						break;
					}

					else
					{
						board[xECord][yECord + 1] = Enemy;
						board[xECord][yECord] = Space;
						continue;
					}
				}
			}
			else
			{
				xECord = 0;
				yECord = 0;
				continue;
			}
		}
		continue;
	}
}

void Board::FindPlayer(char board[][Column], int & xCord, int & yCord)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (board[i][j] == Player)
			{
				xCord = i;
				yCord = j;
				cout << "FOUND PLAYER AT: [" << xCord << "][" << yCord << "]" << endl;
				break;
			}
			else
				continue;
		}
		continue;
	}
}

void Board::PromptPlayer(char & Movement)
{
	cout << "W = UP" << endl;
	cout << "A = LEFT" << endl;
	cout << "S = DOWN" << endl;
	cout << "D = RIGHT" << endl;

	cout << "Enter your move: ";
	cin >> Movement;

	if (islower(Movement))
		Movement = toupper(Movement);

	while (Movement != 'W' && Movement != 'A' && Movement != 'S' && Movement != 'D')
	{
		cout << "Invalid move. Try again: ";
		cin >> Movement;

		if (islower(Movement))
			Movement = toupper(Movement);
	}
}

int main()
{
	Board Test;
	srand(time(NULL));
	Test.SetBoard(Test.board);
	Test.SetEnemiesAndTraps(Test.board);
	Test.DisplayBoard(Test.board);

	while (true)
	{
		//cout << "DEBUG: WIN STATUS = " << Test.WinStatus << "!" << endl;
		Test.FindPlayer(Test.board, Test.xCord, Test.yCord);
		Test.PromptPlayer(Test.Movement);
		Test.MovePlayer(Test.board, Test.Movement, Test.WinStatus, Test.xCord, Test.yCord);
		Test.MoveEnemy(Test.board, Test.Direction, Test.WinStatus, Test.xECord, Test.yECord);
		Test.DisplayBoard(Test.board);
		//cout << "DIRECTION: " << Test.Direction << endl;

		if (Test.WinStatus >= 1)
			break;
	}
}
