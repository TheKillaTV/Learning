// Pointer practice

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const char Letters [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

class String
{
private:
	string Word;
	int LetterCount;
	int UpperCaseCount;
	int LowerCaseCount;
	int MiscCharacters;
	int SpaceCount;
	char Choice;

public:
	String() : Word("Sweats"), LetterCount(0), UpperCaseCount(0), LowerCaseCount(0), MiscCharacters(0), SpaceCount(0) {}
	string GetWord() const { return  Word; }
	int GetLetterCount() const { return LetterCount; }
	int GetUpperCaseCount() const { return UpperCaseCount; }
	int GetLowerCaseCount() const { return LowerCaseCount; }
	int GetMiscCharactersCount() const { return MiscCharacters; }
	int GetSpaceCount() const { return SpaceCount; }
	char GetChoice() const { return Choice; }

	void SetChoice(char Choice) { this->Choice = Choice; }
	void SetWord(string Word) { this->Word = Word; }
	void ChangeWord(string & word);
	void SortWordZtoA(string & word);
	void SortWordAtoZ(string & word);
	void ReverseWord(string & word);
	void CountLetters(string & word);
	void ChangeAllLettersToUpperCase(string & word);
	void ChangeAllLettersToLowerCase(string & word);
	void GenerateRandomString(string & word, int size);

	bool IsUpper(char letter);
	bool IsLower(char letter);

	char ToLower(char letter) { letter += 32; return letter; }
	char ToUpper(char letter) { letter -= 32; return letter; }
};

int main()
{
	srand(time(NULL));
	String * t = new String();

	char * temp = new char;
	cout << "Enter a string which you would like to modify. Or, generate one randomly: " << endl;
	cout << "A. Enter a string: " << endl;
	cout << "B. Generate a string " << endl;
	cin >> *temp;
	cin.ignore(); // Crashes without this because cin leaves a newline in the input buffer

	if (t->IsUpper(*temp))
		*temp = t->ToLower(*temp);

	if (*temp == 'a')
	{
		string * word = new string;

		cout << "Enter the string: ";

		getline(cin, *word);
		t->SetWord(*word);

		cout << "Original string: " << t->GetWord() << endl;

		t->ReverseWord(t->GetWord());
		t->ChangeAllLettersToLowerCase(t->GetWord());
		t->ChangeAllLettersToUpperCase(t->GetWord());
		t->CountLetters(t->GetWord());
		t->SortWordZtoA(t->GetWord());
		t->SortWordAtoZ(t->GetWord());

		cout << "Total Letters: " << t->GetLetterCount() << endl;
		cout << "Total Spaces: " << t->GetSpaceCount() << endl;
		cout << "Total LowerCase Letters: " << t->GetLowerCaseCount() << endl;
		cout << "Total Uppercase Letters: " << t->GetUpperCaseCount() << endl;
		cout << "Total Miscellaneous characters: " << t->GetMiscCharactersCount() << endl;

		delete word;
	}

	else if (*temp == 'b')
	{
		string * r = new string;
		int * size = new int;

		cout << "Enter the size of the string: " << endl;
		cin >> *size;

		t->GenerateRandomString(*r, *size);
		t->SetWord(*r);
		cout << "Generated Original String: " << t->GetWord() << endl;
		t->ReverseWord(t->GetWord());
		t->SortWordAtoZ(t->GetWord());
		t->SortWordZtoA(t->GetWord());
		t->ChangeAllLettersToLowerCase(t->GetWord());
		t->ChangeAllLettersToUpperCase(t->GetWord());
		t->CountLetters(t->GetWord());

		cout << "Total Letters: " << t->GetLetterCount() << endl;
		cout << "Total Spaces: " << t->GetSpaceCount() << endl;
		cout << "Total LowerCase Letters: " << t->GetLowerCaseCount() << endl;
		cout << "Total Uppercase Letters: " << t->GetUpperCaseCount() << endl;
		cout << "Total Miscellaneous characters: " << t->GetMiscCharactersCount() << endl;
		
		delete r, size;
	}
	else
		return 0;

	delete t, temp;
}

void String::ReverseWord(string & word)
{
	char * a = new char;

	for (unsigned int i = 0, j = word.length() - 1; i <= j; i++, j--)
	{
		*a = word[i];
		word[i] = word[j];
		word[j] = *a;
	}

	delete a;

	cout << "Reversed word:" << word << endl;
}

void String::CountLetters(string & word)
{
	for (unsigned int i = 0; i < word.length(); i++)
	{
		if (word[i] == ' ')
		{
			SpaceCount++;
		}

		else if (IsUpper(word[i]))
		{
			UpperCaseCount++;
			LetterCount++;
		}

		else if (IsLower(word[i]))
		{
			LowerCaseCount++;
			LetterCount++;
		}

		else
			MiscCharacters++;
	}
}

void String::SortWordZtoA(string & word)
{
	char * a = new char;

	for (unsigned int i = 0; i < word.length(); i++)
	{
		for (unsigned int j = 0; j < (word.length() - 1); j++)
		{
			if ((int)word[j] < (int)word[j + 1])
			{
				*a = word[j];
				word[j] = word[j + 1];
				word[j + 1] = *a;
			}
		}
	}

	cout << "Sorted string Z to A (Lowercase letters are sorted then uppercase) " << word << endl;
	delete a;
}

void String::SortWordAtoZ(string & word)
{
	char * a = new char;

	for (unsigned int i = 0; i < word.length(); i++)
	{
		for (unsigned int j = 0; j < (word.length() - 1); j++)
		{
			if ((int)word[j] > (int)word[j + 1]) // Swap individual characters.
			{
				*a = word[j];
				word[j] = word[j + 1];
				word[j + 1] = *a;
			}
		}
	}

	cout << "Sorted string A to Z (Uppercase letters are sorted then lowercase: " << word << endl;
	delete a;
}


void String::ChangeAllLettersToLowerCase(string & word)
{
	for (unsigned int i = 0; i < word.length(); i++)
	{
		if (IsUpper(word[i]))
		{
			word[i] = ToLower(word[i]);
		}
		
	}

	cout << "All letters changed to lowercase: " << word << endl;
}

void String::ChangeAllLettersToUpperCase(string & word)
{
	for (unsigned int i = 0; i < word.length(); i++)
	{
		if (IsLower(word[i]))
		{
			word[i] = ToUpper(word[i]);
		}
	}
	
	cout << "All letters changed to uppercase: " << word << endl;
}

void String::GenerateRandomString(string & word, int size)
{
	for (unsigned int i = 0; i < size - 1; i++)
	{
		word += Letters[rand() % sizeof(Letters)];
	}
}

bool String::IsUpper(char letter) // 65 - 90 on the ASCII table
{
	if ((int)letter >= 65 && (int)letter <= 90)
		return true;
	else
		return false;
}

bool String::IsLower(char letter) // 97 - 122 on the ASCII table
{
	if ((int)letter >= 97 && (int)letter <= 122)
		return true;
	else
		return false;
}
