#include "stdafx.h"
#include "Hangman.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

int Hangman::Incorrect = 0;
int Hangman::found = 0;
int Hangman::Spaces = 0;
bool Hangman::Win = false;
int Hangman::Tries = 6;

string Hangman::SelectWordFromList(Hangman & Hang, string word)
{
	int random = rand() % 8 + 0;
	Hang.word = List[random];
	return Hang.word;
}

string Hangman::CopyWord(Hangman & Hang, string & wordcopy, string & word)
{
	Hang.wordcopy = Hang.word;
	return Hang.wordcopy;
}

void Hangman::GuessLetter(Hangman & Hang, char & letter, string & word, int found = 0)
{
	for (int i = 0; i < Hang.word.length(); i++)
	{
		if (Hang.letter == Hang.word[i])
		{
			found++;
			Hang.ReplaceLetters(Hang, Hang.letter, Hang.word, Hang.wordcopy);
			continue;
		}

		else
			continue;
	}

	if (found == 0)
	{
		Hang.Incorrect++;
		Hang.Tries--;
		cout << "No letters found :( " << endl << endl;
		cout << "You can only make " << Hang.Tries << " more wrong guessses." << endl;
		Hang.DrawHangMan(Hang, Incorrect);
	}
	else
		cout << "Nice! You guessed a correct letter :) " << endl << endl;
}

void Hangman::DrawHangMan(Hangman & Hang, int & Incorrect)
{
	switch (Incorrect)
	{
	case 1:
		Hang.DrawHangManOne(Hang);
		break;
	case 2:
		Hang.DrawHangManTwo(Hang);
		break;
	case 3:
		Hang.DrawHangManThree(Hang);
		break;
	case 4:
		Hang.DrawHangManFour(Hang);
		break;
	case 5:
		Hang.DrawHangManFive(Hang);
		break;
	default:
		Hang.DrawHangManSix(Hang);
		break;
	}
}

string Hangman::BlankCopy(Hangman & Hang, string & wordcopy)
{
	for (int i = 0; i < Hang.wordcopy.length(); i++)
		Hang.wordcopy[i] = '_';

	return Hang.wordcopy;
}

void Hangman::ReplaceLetters(Hangman & Hang, char & letter, string & word, string & wordcopy)
{
	for (int i = 0, j = 0;  i < Hang.word.length(); i++, j++)
	{
		if (Hang.letter == Hang.word[i])
		{
			Hang.wordcopy[i] = Hang.word[j];
			continue;
		}
		else
			continue;
	}
}

void Hangman::DisplayWord(Hangman & Hang, const string & wordcopy)
{
	for (int i = 0; i < Hang.wordcopy.length(); i++)
		cout << Hang.wordcopy[i];
	cout << endl;
}

char Hangman::CheckIfUpperCase(Hangman & Hang, char & letter)
{
	if (isupper(Hang.letter))
		Hang.letter = tolower(Hang.letter);
	return Hang.letter;
}

bool Hangman::CheckWin(Hangman & Hang, string & word, string & wordcopy)
{
	if (Hang.word == Hang.wordcopy)
		return true;
	else
		return false;
}

void Hangman::CountSpaces(Hangman & Hang, string & word, int Spaces)
{
	for (int i = 0; i < Hang.word.length(); i++)
		Hang.Spaces++;
	cout << endl << "*HINT*: The word is " << Hang.Spaces << " letters long." << endl; 
}

void Hangman::DrawHangManOne(Hangman & Hang)
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

void Hangman::DrawHangManTwo(Hangman & Hang)
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

void Hangman::DrawHangManThree(Hangman & Hang)
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

void Hangman::DrawHangManFour(Hangman & Hang)
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

void Hangman::DrawHangManFive(Hangman & Hang)
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

void Hangman::DrawHangManSix(Hangman & Hang)
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
