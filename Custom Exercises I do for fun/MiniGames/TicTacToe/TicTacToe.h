#pragma once

#ifndef TICTACTOE_H
#define TICTACTOE_H

const int size = 3;
const char Blank = ' ';

class TicTacToe
{
public:
	char X = 'X';
	char O = 'O';
	char Board[size][size];
	static int p1Row;
	static int p1Column;
	static int p2Row;
	static int p2Column;
	static int pWinner;
	int row;
	int column;

	static int Turns;


	void PrintBoard(char arr[][size]);
	void SetBoard(char arr[][size]);
	void ModifiyBoard(char  arr[][size], int & row, int & column, char & move);
	void PlayerOneTurn(int & p1Row, int & p1Column);
	void PlayerTwoTurn(int & p2Row, int & p2Column);
	void ClearScreen();
	int CheckWinner(char arr[][size], int & pWinner);

};

#endif

