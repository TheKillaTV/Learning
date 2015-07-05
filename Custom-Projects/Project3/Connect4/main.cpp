#include "stdafx.h"
#include <iostream>
#include "Connect4.h"
#include <ctime>
#include <cstdlib>

// TO DO. Add feature that shows where Player 1 or 2 won.


using namespace std;

int main()
{
	Connect4 * Test = new Connect4();

	while (true)
	{
		Test->PrintBoard();
		//cout << "TurnCount: " << Test->GetTurnCount() << endl;

		if (Test->GetTurnCount() >= 49)
		{
			//cout << "Draw! Nobody Wins! " << endl;
			break;
		}

		if (Test->GetTurnCount() % 2 == 0)
		{
			Test->ModifyBoard(Test->Getp1Column());
			Test->ScanBoard();

			if (Test->GetWinCount() >= 100)
			{
				Test->PrintBoard();
				cout << "Player 1 Wins! " << endl;
				//cout << "Show how Player 1 Won? " << endl;
				//Test->GetAnswer();
				break;
			}
		}

		else
		{
			Test->ModifyBoard(Test->Getp2Column());
			Test->ScanBoard();

			if (Test->GetWinCount() > 0 && Test->GetWinCount() < 100)
			{
				Test->PrintBoard();
				cout << "Player 2 Wins! " << endl;
				break;
			}
		}
		
		Test->IncrementTurnCount();
	}

	delete Test;
}
