#pragma once

#ifndef CONNECT4_H
#define CONNECT4_H

const int Row = 7, Column = 8;

class Connect4
{
private:
	char p1;
	char p2;
	char space;
	char arr[Row][Column];
	//char Answer;
	int TurnCount;
	int p1Column;
	int p2Column;
	int p1x, p1y;
	int p2x, p2y;

	int WinCount;

	bool CheckIfMoveIsAllowed(int Column);
	void WinnerAlgorithm(int x, int y);
	//void ShowWinner();

public:
	Connect4();
	void PrintBoard();
	int GetTurnCount() const { return TurnCount; }
	int IncrementTurnCount() { return TurnCount++; }
	int GetWinCount() const { return WinCount; }
	char Getp1Column();
	char Getp2Column();
	//char GetAnswer();
	void ModifyBoard(int Column);
	void ScanBoard();
	

};

#endif

