#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Hangman.h"

// TO DO: Pick a random word from a text file filled with random words.

using namespace std;

int main()
{

	srand(time(NULL));
	Hangman * Test = new Hangman();

	Test->SetWord(Test->PickWord());
	Test->SetWordCopy(Test->GetWord());
	Test->BlankWord(Test->GetWordCopy());

	cout << "Guess the word! (Hint: the word is " << Test->GetLetters() << " letters long.) " << endl << endl;

	while (true)
	{
		Test->FillinWord(Test->GetLetter());

		if (Test->CheckIfEqual(Test->GetWord(), Test->GetWordCopy()))
		{
			cout << "Congratulations! You win! " << endl;

			cout << "The word was: " << Test->GetWord() << "." << endl;
			break;
		}

		else if (Test->GetIncorrectCount() >= 6)
		{
			cout << "You Lose! The word is: " << Test->GetWord() << "." << endl;
			break;
		}

		cout << "Word so far: " << Test->GetWordCopy() << endl;
	}


	delete Test;

	return 0;
}
