
#include "stdafx.h" // Microsoft Visual Studio
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "RockPaperSissors.h"

using namespace std;


int main()
{
	srand(time(NULL));
	RockPaperSissors Test;
	while (true)
	{
		Test.PlayerTurn(Test.m_Ppick);
		Test.ComputerTurn(Test.m_cPick);
		Test.DetermineWinner(Test.m_Ppick, Test.m_cPick);
		Test.m_Play = Test.AskToPlayAgain(Test.m_Play, Test.m_Pchoice);

		if (Test.m_Play)
			continue;
		else
			break;
	}

	cout << "Thanks for playing! " << endl;
	
	return 0;
}

