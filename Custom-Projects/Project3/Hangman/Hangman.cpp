#include "stdafx.h"
#include "Hangman.h"
#include <iostream>

using namespace std;

void Hangman::BlankWord(string CopyWord)
{
	for (int i = 0; i < CopyWord.length(); i++)
	{
		this->CopyWord[i] = '_';
		Letters++;
	}
}

char Hangman::GetLetter()
{
	cout << "Enter a letter to guess: ";
	cin >> Guess;
	return Guess;
}

void Hangman::FillinWord(char Guess)
{
	Found = false;
	for (int i = 0, j = 0; i < OriginalWord.length(); i++, j++)
	{
		if (OriginalWord[i] == Guess)
		{
			Found = true;
			CopyWord[j] = OriginalWord[i];
		}
	}

	if (!Found)
	{
		cout << "The letter that you guessed was not found in the word :( " << endl;
		Incorrect++;
		DrawHangMan(Incorrect);

	}
}

bool Hangman::CheckIfEqual(string OriginalWord, string CopyWord)
{
	if (OriginalWord == CopyWord)
		return true;
	else
		return false;
}

void Hangman::DrawHangMan(int Incorrect)
{
	switch (Incorrect)
	{
	case 1:
		PrintHangManOne();
		break;
	case 2:
		PrintHangManTwo();
		break;
	case 3:
		PrintHangManThree();
		break;
	case 4:
		PrintHangManFour();
		break;
	case 5:
		PrintHangManFive();
		break;
	default:
		PrintHangManSix();
		break;
	}
}

void Hangman::PrintHangManOne()
{
		cout << endl << endl
		<< "   +----+  " << endl
		<< "   |    |  " << endl
		<< "   |       " << endl
		<< "   |       " << endl
		<< "   |       " << endl
		<< "   |       " << endl
		<< "  =============" << endl << endl;
}

void Hangman::PrintHangManTwo()
{
		cout << endl << endl
		<< "   +----+  " << endl
		<< "   |    |  " << endl
		<< "   |    O  " << endl
		<< "   |    |  " << endl
		<< "   |       " << endl
		<< "   |       " << endl
		<< "  =============" << endl << endl;
}

void Hangman::PrintHangManThree()
{
		cout << endl << endl
		<< "   +----+  " << endl
		<< "   |    |  " << endl
		<< "   |    O  " << endl
		<< "   |   /|  " << endl
		<< "   |       " << endl
		<< "   |       " << endl
		<< "  =============" << endl << endl;
}

void Hangman::PrintHangManFour()
{
		cout << endl << endl
		<< "   +----+  " << endl
		<< "   |    |  " << endl
		<< "   |    O  " << endl
		<< "   |   /|\\ " << endl
		<< "   |       " << endl
		<< "   |       " << endl
		<< "  =============" << endl << endl;
}

void Hangman::PrintHangManFive()
{
		cout << endl << endl
		<< "   +----+  " << endl
		<< "   |    |  " << endl
		<< "   |    O  " << endl
		<< "   |   /|\\ " << endl
		<< "   |     \\ " << endl
		<< "   |       " << endl
		<< "  ============" << endl << endl;
}

void Hangman::PrintHangManSix()
{
		cout << endl << endl
		<< "   +----+     " << endl
		<< "   |    |     " << endl
		<< "   |    O     " << endl
		<< "   |   /|\\   " << endl
		<< "   |   / \\   " << endl
		<< "   |Your Dead " << endl
		<< "  ============" << endl << endl;
}
