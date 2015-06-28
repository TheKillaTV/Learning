#include "stdafx.h"
#include "RockPaperSissors.h"
#include <iostream>

using namespace std;

const char Options[] = "ABC";

char RockPaperSissors::Get_C_Choice()
{
	c_choice = Options[rand() % 3];

	switch (c_choice)
	{
	case 'A':
		SetCText("Rock");
		break;
	case 'B':
		SetCText("Paper");
		break;
	case 'C':
		SetCText("Sissors");
		break;
	default:
		cout << "This should never be printed. If so, fix it " << endl;
		break;
	}

	return c_choice;
}

char RockPaperSissors::Get_P_Choice()
{
	cout << "Which option do you want to pick? " << endl;
	cout << "A. Rock " << endl;
	cout << "B. Paper " << endl;
	cout << "C. Sissors " << endl;
	cin >> p_choice;

	if (islower(p_choice))
		p_choice = toupper(p_choice);

	switch (p_choice)
	{
	case 'A':
		SetPText("Rock");
		break;
	case 'B':
		SetPText("Paper");
		break;
	case 'C':
		SetPText("Sissors");
		break;
	default:
		while (p_choice != 'A' && p_choice != 'B' && p_choice != 'C')
		{
			cout << "Pick one of the choices: " << endl;
			cin >> p_choice;

			if (islower(p_choice))
				p_choice = toupper(p_choice);

			if (p_choice == 'A')
				SetPText("Rock");

			else if (p_choice == 'B')
				SetPText("Paper");

			else if (p_choice == 'C')
				SetPText("Sissors");
		}

		break;
	}

	return p_choice;
}

void RockPaperSissors::DetermineWinner()
{
	// Tie checks. A = Rock, B = Paper, C = Sissors.

	cout << "Your choice: " << P_text << "." << endl << endl;
	cout << "Computers choice: " << C_text << "." << endl << endl;

	if (p_choice == 'A' && c_choice == 'A' || p_choice == 'B' && c_choice == 'B' || p_choice == 'C' && c_choice == 'C')
	{
		cout << "Tie! Both you and the CPU picked " << P_text << "!" << endl;
		IncrementRounds();
		IncrementTies();
	}

	// Player Win Checks

	else if (p_choice == 'A' && c_choice == 'C' || p_choice == 'B' && c_choice == 'A' || p_choice == 'C' && c_choice == 'B')
	{
		cout << "You Win! You picked " << P_text << " while the CPU picked " << C_text << "." << endl;
		IncrementRounds();
		Incrementp1Win();
	}

	else if (c_choice == 'A' && p_choice == 'C' || c_choice == 'B' && p_choice == 'A' || c_choice == 'C' && p_choice == 'B')
	{
		cout << "You Lose! You picked " << P_text << " while the CPU picked " << C_text << "." << endl;
		IncrementRounds();
		IncrementCPUWin();
	}

	else
	{
		cout << " ********* Ok you have something to debug ********** " << endl;
	}
}

void RockPaperSissors::DisplayStats()
{
	cout << "Total Rounds: " << GetRounds() << endl;
	cout << "Total Ties: " << GetTies() << endl;
	cout << "Total Wins by Player: " << Getp1Win() << endl;
	cout << "Total Wins by CPU: " << GetCPUWin() << endl << endl;

}

bool RockPaperSissors::GetQuit()
{
	char * temp = new char;
	cout << "Keep playing? " << endl;
	cout << "A. Yes" << endl;
	cout << "Not A: No" << endl;
	cin >> *temp;

	if (islower(*temp))
		*temp = toupper(*temp);

	switch (*temp)
	{
	case 'A':
		return true;
	default:
		return false;
	}

	delete temp;
}

