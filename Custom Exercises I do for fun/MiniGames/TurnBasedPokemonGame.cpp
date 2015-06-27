/*#GOAL

Write a simple game that allows the user and the computer to take turns selecting moves to use against each other.
Both the computer and the player should start out at the same amount of health(such as 100), and should be able to choose between the three moves :
The first move should do moderate damage and has a small range(such as 18 - 25).
The second move should have a large range of damage and can deal high or low damage(such as 10 - 35).
The third move should heal whoever casts it a moderate amount, similar to the first move.
After each move, a message should be printed out that tells the user what just happened, and how much health the user and computer have.Once the user or the computer's health reaches 0, the game should end.

SUBGOALS
When someone is defeated, make sure the game prints out that their health has reached 0, and not a negative number.
When the computer's health reaches a set amount (such as 35%), increase it's chance to cast heal.
Give each move a name.

*/


#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const char options[] = "ABC";

class Game
{
private:
	char move;
	int Chealth;
	int health;
	int turn;

public:
	Game() : Chealth(100), health(100), turn(1) {}
	int GetChealth() const { return Chealth; }
	int GetHealth() const { return health; }
	int GetTurns() const { return turn; }
	char GetMove() const { return move; }
	int IncrementTurn() { return turn++; }
	void Attack(char move);
	void SetHealth(int health) { this->health = health; }
	void SetChealth(int Chealth) { this->Chealth = Chealth; }
	void SetMove(char move);
	void PrintStats();
	void PrintOptions();
	void MoveOne();
	void MoveTwo();
	void MoveThree();
	void PrintFinalStats();
};

int main()
{
	srand(time(NULL));
	Game g;
	cout << "A battle begins!" << endl << endl;

	while (g.GetChealth() > 0 && g.GetHealth() > 0)
	{
		g.PrintStats();
		g.PrintOptions();
		g.SetMove(g.GetMove());
		g.Attack(g.GetMove());
		g.IncrementTurn();

		if (g.GetChealth() <= 0)
		{
			g.SetChealth(0);
			cout << "You win!" << endl << endl;
			break;
		}

		g.SetMove(g.GetMove());
		g.Attack(g.GetMove());
		g.IncrementTurn();

		if (g.GetHealth() <= 0)
		{
			g.SetHealth(0);
			cout << "You lose!" << endl << endl;
			break;
		}
	}

	g.PrintFinalStats();
}

void Game::PrintStats()
{
	cout << "Player HP: " << health << ".  Computer HP: " << Chealth << "." << endl << endl;
}

void Game::Attack(char move)
{
	if (islower(move))
		move = toupper(move);

	switch (move)
	{
	case 'A':
		MoveOne();
		break;
	case 'B':
		MoveTwo();
		break;
	case 'C':
		MoveThree();
		break;
	default:
		cout << "None picked. Picked Moderate damage move" << endl;
		//cout << "COMPUTER PICKED: " << (int)move << endl;
		MoveOne();
		break;
	}
}


void Game::MoveOne()
{
	int damage = rand() % 7 + 18;

	if (turn % 2 != 0)
	{
		cout << "You hit CPU for " << damage << " damage! (Moderate Attack) " << endl;
		SetChealth(Chealth - damage);
	}

	else
	{
		cout << "CPU hits you for " << damage << " damage! (Moderate Attack)" << endl;
		SetHealth(health - damage);
	}

}

void Game::MoveTwo()
{
	int damage = rand() % 25 + 10;

	if (turn % 2 != 0)
	{
		cout << "You hit CPU for " << damage << " damage! (Light to Heavy Attack)" << endl;
		SetChealth(Chealth - damage);
	}

	else
	{
		cout << "CPU hits you for " << damage << " damage! (Light to Heavy Attack)" << endl;
		SetHealth(health - damage);
	}
}

void Game::MoveThree()
{
	int heal = rand() % 7 + 18;

	if (turn % 2 != 0)
	{
		if (health <= 35)
		{
			int crit = rand() % 5 + 10;
			cout << "You healed yourself for " << heal << " health + an extra " << crit << " health!" << endl;
			SetHealth(health += heal + crit);

			if (health > 100)
				SetHealth(100);
		}

		else
		{
			cout << "You healed yourself for " << heal << " health!" << endl;
			SetHealth(health += heal);

			if (health > 100)
				SetHealth(100);
		}
	}

	else
	{
		if (Chealth <= 35)
		{
			int crit = rand() % 5 + 10;
			cout << "CPU healed itself for " << heal << " health + an extra " << crit << " health!" << endl;
			SetChealth(Chealth += heal + crit);

			if (Chealth > 100)
				SetChealth(100);
		}

		else
		{
			cout << "CPU healed itself for " << heal << " health!" << endl;
			SetChealth(Chealth += heal);

			if (Chealth > 100)
				SetChealth(100);
		}
	}
}

void Game::PrintOptions()
{
	cout << "A. Moderate Damage " << endl;
	cout << "B. Light to Heavy Damage " << endl;
	cout << "C. Heal Self" << endl << endl;
}

void Game::SetMove(char move)
{
	if (turn % 2 != 0)
		cin >> this->move;
	else
		this->move = options[rand() % 3];
}

void Game::PrintFinalStats()
{
	cout << "Final stats: " << endl << endl;
	cout << "-----------------------------" << endl;
	cout << "Total turns: " << turn - 1 << endl; // - 1 because turn variable started at 1
	cout << "Your health: " << health << endl;
	cout << "CPU health: " << Chealth << endl;
}
