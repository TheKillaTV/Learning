#include "stdafx.h" // Microsoft Visual Studio
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Hangman.h"

using namespace std;

int main()
{
	Hangman Hang;
	srand(time(NULL));
	Hang.word = Hang.SelectWordFromList(Hang, Hang.word);
	Hang.wordcopy = Hang.word;
	Hang.wordcopy = Hang.BlankCopy(Hang, Hang.wordcopy);

	cout << "Welcome to the Hangman game. A word has been generated for you. " << endl;
	cout << "Blank word:  ";
	Hang.DisplayWord(Hang, Hang.wordcopy);

	Hang.CountSpaces(Hang, Hang.word, Hang.Spaces);

	while (Hang.word != Hang.wordcopy && Hang.Tries > 0)
	{
		cout << "Guess a letter:  ";
		cin.get(Hang.letter);
		cin.ignore();
		Hang.letter = Hang.CheckIfUpperCase(Hang, Hang.letter);
		Hang.GuessLetter(Hang, Hang.letter, Hang.word, Hang.found);
		cout << "Word so far:  ";
		Hang.DisplayWord(Hang, Hang.wordcopy);
		Hang.Win = Hang.CheckWin(Hang, Hang.word, Hang.wordcopy);

		if (Hang.Win)
		{
			cout << "Congratulations! You won :)" << endl;
			break;
		}

		else if (Hang.Incorrect == 6)
			return 0;
	}
}
