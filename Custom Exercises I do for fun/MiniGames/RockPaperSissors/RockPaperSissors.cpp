#include "stdafx.h"
#include "RockPaperSissors.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


void RockPaperSissors::PlayerTurn(int & m_pPick)
{
	cout << "Which one do you pick?" << endl;
	cout << "1. Rock" << endl;
	cout << "2. Paper" << endl;
	cout << "3. Sissors" << endl;
	cin >> m_Ppick;

	while (m_pPick < 1 || m_pPick > 3)
	{
		cout << "Pick one of the options: " << endl;
		cin >> m_pPick;
	}
}

void RockPaperSissors::ComputerTurn(int & m_cPick)
{
	m_cPick = rand() % 3 + 0;

	// 0 = Rock
	// 1 = Paper
	// 2 = Sissors
}


void RockPaperSissors::DetermineWinner(int & m_pPick, int & m_cPick)
{
	if (m_pPick == 1 && m_cPick == 2)
		cout << "You win! Your Rock crushes the Computers Sissors!" << endl;
	else if (m_pPick == 3 && m_cPick == 0)
		cout << "You lose! The Computers Rock crushes your Sissors!" << endl;
	else if (m_pPick == 2 && m_cPick == 0)
		cout << "You win! Your Paper smothers the Computers Rock" << endl;
	else if (m_pPick == 1 && m_cPick == 1)
		cout << "You lose! The Computers Paper smothers your Rock!" << endl;
	else if (m_pPick == 3 && m_cPick == 1)
		cout << "You win! Your Sissors cuts the Computers Paper!" << endl;
	else if (m_pPick == 2 && m_cPick == 2)
		cout << "You lose! The Computers Sissors cut your Paper!" << endl;
	else if (m_Ppick == 1 && m_cPick == 0)
		cout << "Tie! Both you and the Computer played Rock!" << endl;
	else if (m_Ppick == 2 && m_cPick == 1)
		cout << "Tie! Both you and the Computer played Paper!" << endl;
	else if (m_Ppick == 3 && m_cPick == 2)
		cout << "Tie! Both you and the Computer played Sissors!" << endl;
	else
	{
		cout << "Your choice: " << m_pPick << endl;
		cout << "------------------------" << endl;
		cout << "Computers choice: " << m_cPick << endl;
	}

	//cout << "DEBUG: Computer played " << m_cPick << endl;

		
}
bool RockPaperSissors::AskToPlayAgain(bool & m_Play, int & m_Pchoice)
{
	cout << "Play again? " << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> m_Pchoice;

	if (m_Pchoice == 1)
		return true;
	else
		return false;
}
