
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void ReverseString(string word);

int main()
{
	cout << "Enter a string to reverse" << endl;

	string word;

	getline(cin, word);

	cout << "Word you entered is: " << word << endl;
	cout << "Word length: " << word.length() << endl;

	ReverseString(word);
}

void ReverseString(string word)
{
	char a;

	for (int i = 0, j = word.length() - 1; i <= j; i++, j--)
	{
		a = word[i];
		word[i] = word[j];
		word[j] = a;
	}

	cout << "Reversed string is: " << word << endl;
}
