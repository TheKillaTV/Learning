#pragma once
#include <string>

using std::string;

#ifndef HANGMAN_H
#define HANGMAN_H

const string Words [] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

class Hangman
{
private:
	string OriginalWord;
	string CopyWord;
	int Letters;
	int WordCount;
	int Incorrect;
	char Guess;
	bool Found;

	void DrawHangMan(int Incorrect);
	void PrintHangManOne();
	void PrintHangManTwo();
	void PrintHangManThree();
	void PrintHangManFour();
	void PrintHangManFive();
	void PrintHangManSix();


public:
	Hangman() : Letters(0), WordCount(0), Incorrect(0), Found(false) {}
	void SetWord(string OriginalWord) { this->OriginalWord = OriginalWord; }
	void SetWordCopy(string CopyWord) { this->CopyWord = CopyWord; }
	int GetLetters() const { return Letters; }
	int GetWordCount() const { return WordCount; }
	int GetIncorrectCount() const { return Incorrect; }
	string GetWord() const  { return OriginalWord; }
	string GetWordCopy() const { return CopyWord; }
	string PickWord() { return Words[rand() % 10]; }
	void BlankWord(string CopyWord);
	void FillinWord(char Guess);
	char GetLetter();
	bool CheckIfEqual(string OriginalWord, string CopyWord);


};

#endif

