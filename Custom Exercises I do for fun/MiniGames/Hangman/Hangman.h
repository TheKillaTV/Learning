#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

#ifndef HANGMAN_H
#define HANGMAN_H

const int size = 8;
const string List[size] = { "sweats", "happy", "hello", "cplusplus", "programming", "coding", "learning", "something" };

class Hangman
{
public:
	string word;
	string wordcopy;
	char letter;
	static int found;
	static int Incorrect;
	static int Spaces;
	static int Tries;
	static bool Win;

	string SelectWordFromList(Hangman & Hang, string word);
	string CopyWord(Hangman & Hang, string & wordcopy, string & word);
	string BlankCopy(Hangman & Hang, string & wordcopy);
	char CheckIfUpperCase(Hangman & Hang, char & letter);
	void DisplayWord(Hangman & Hang, const string & wordcopy);
	void DrawHangMan(Hangman & Hang, int & Incorrect);
	void GuessLetter(Hangman & Hang, char & letter, string & word, int found);
	void ReplaceLetters(Hangman & Hang, char & letter, string & word, string & wordcopy);
	void CountSpaces(Hangman & Hang, string & word, int Spaces);
	bool CheckWin(Hangman & Hang, string & word, string & wordcopy);
	void DrawHangManOne(Hangman & Hang);
	void DrawHangManTwo(Hangman & Hang);
	void DrawHangManThree(Hangman & Hang);
	void DrawHangManFour(Hangman & Hang);
	void DrawHangManFive(Hangman & Hang);
	void DrawHangManSix(Hangman & Hang);
	//bool CheckIfUsedLetter(Hangman & Hang, char Letters[], char & letter);


};

#endif
