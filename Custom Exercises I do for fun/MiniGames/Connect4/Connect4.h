#pragma once

#ifndef CONNECT4_H
#define CONNECT4_H

const int Row = 7;
const int Column = 8;
const int Size = 10;

class Connect4
{
public:
	Connect4();
	static int x;
	static int y;
	static int Pieces;
	static bool PlayerPiece;
	static int Winner;
	void PrintBoard();
	void ScanBoard();
	void PlayerOneTurn();
	void PlayerTwoTurn();
	void PutPlayerOnePiece();
	void PutPlayerTwoPiece();
	void WinnerAlgorithm();

private:
	char arr[Row][Column];
	char p1 = 'X';
	char p2 = 'O';
	char Space = '_';
	char choice;
	int p1turn;
	int p2turn;
	
};

#endif
