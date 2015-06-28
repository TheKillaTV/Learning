#pragma once
#include <string>

using namespace std;

#ifndef ROCKPAPERSISSORS_H
#define ROCKPAPERSISSORS_H

class RockPaperSissors
{
private:

	char c_choice;
	char p_choice;
	string P_text;
	string C_text;
	int p1win;
	int CPUwin;
	int ties;
	int rounds;
	bool quit;
	int IncrementRounds() { return rounds++; }
	int IncrementTies() { return ties++; }
	int Incrementp1Win() { return p1win++; }
	int IncrementCPUWin() { return CPUwin++; }
	void SetPText(string P_text) { this->P_text = P_text; }
	void SetCText(string C_text) { this->C_text = C_text; }
	int GetRounds() const { return rounds; }
	int GetTies() const { return ties; }
	int Getp1Win() const { return p1win; }
	int GetCPUWin() const { return CPUwin; }

public:
	RockPaperSissors() : p1win(0), CPUwin(0), rounds(0), ties(0) {}
	char Get_P_Choice();
	char Get_C_Choice();
	void Set_P_Choice(char p_choice) { this->p_choice = p_choice; }
	void Set_C_Choice(char c_choice) { this->c_choice = c_choice; }
	void DetermineWinner();
	void DisplayStats();
	bool GetQuit();

};

#endif 

