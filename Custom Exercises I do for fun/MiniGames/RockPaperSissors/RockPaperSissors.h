#pragma once

#ifndef ROCKPAPERSISSORS_H
#define ROCKPAPERSISSORS_H

class RockPaperSissors
{
public:
	int m_Ppick;
	int m_cPick;
	int m_Pchoice;
	bool m_Play;

	void PlayerTurn(int & m_pPick);
	void ComputerTurn(int & m_cPick);
	void DetermineWinner(int & m_pPick, int & m_cPick);
	bool AskToPlayAgain(bool & m_Play, int & m_Pchoice);



};

#endif
