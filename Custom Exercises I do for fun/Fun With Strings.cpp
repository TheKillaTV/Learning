// OOP practice

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const char Letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

class FunWithStrings
{
public:
    string  input, temp;
    string  ScrambleString(string);
    string  ReverseString(string);
    string  ReplaceString(string);
    string  ReplaceCharacters(string, char, char);
    int     CountLetters(string, unsigned int);
    int     CountWords(string, unsigned int);
    int     LetterCount = -1; // -1 because null character counts as one.
    int     WordCount = 1;
    char    letter1, letter2;
    void    PrintString(string);
};

void DisplayMenu(FunWithStrings myFun);
void ChoiceA(FunWithStrings myFun);
void ChoiceB(FunWithStrings myFun);
void ChoiceC(FunWithStrings myFun);
void ChoiceD(FunWithStrings myFun);
void ChoiceE(FunWithStrings myFun);
void ChoiceZ(FunWithStrings myFun);

int main()
{
    srand(time(NULL));
    FunWithStrings myFun;
    cout << "Enter a string: ";
    getline(cin, myFun.input);
    DisplayMenu(myFun);
}

string FunWithStrings::ScrambleString(string nWord)
{
    for (int i = 0; i < nWord.length(); i++)
    {
        unsigned int random = 0;
        random = rand() % 25 + 0;

        if (nWord[i] == ' ') // We don't want to scramble a space
           continue;
        nWord[i] = Letters[random];
    }

    return nWord;
}

void FunWithStrings::PrintString(string nWord)
{
    cout << "New string is: " << nWord << endl;
}

string FunWithStrings::ReverseString(string nWord)
{
    reverse(nWord.begin(), nWord.end());
    return nWord;
}

string FunWithStrings::ReplaceCharacters(string nWord, char c, char a)
{
    for (int i = 0; i < nWord.length(); i++)
    {
        if (nWord[i] == ' ' || nWord[i] == a)
            continue;
        else if (nWord[i] == c)
            nWord[i] = a;
    }

    return nWord;
}

int FunWithStrings::CountLetters(string nWord, unsigned int amount = -1)
{
    for (int i = 0; i < nWord.length(); i++)
    {
        if (nWord[i] == ' ')
            continue;
         amount++;
    }

    return amount;
}

int FunWithStrings::CountWords(string nWord, unsigned int amount = 1)
{
    for (int i = 0; i < nWord.length(); i++)
        if (nWord[i] == ' ')
            amount++;

    return amount;
}

void DisplayMenu(FunWithStrings myFun)
{
    char choice;
    cout << "What would you like to do with your string? " << endl;
    cout << "A. Scramble String" << endl;
    cout << "B. Reverse String" << endl;
    cout << "C. Replace letter(s) in the string with a letter" << endl;
    cout << "D. Count letters in the string" << endl;
    cout << "E. Count words in the string" << endl;
    cin >> choice;

    if (islower(choice))
        choice = toupper(choice);

    switch (choice)
    {
    case 'A':
        ChoiceA(myFun);
        break;
    case 'B':
        ChoiceB(myFun);
        break;
    case 'C':
        ChoiceC(myFun);
        break;
    case 'D':
        ChoiceD(myFun);
        break;
    case 'E':
        ChoiceE(myFun);
        break;
    default:
        ChoiceZ(myFun);
        break;
    }
}

void ChoiceA(FunWithStrings myFun)
{
    myFun.input = myFun.ScrambleString(myFun.input);
    myFun.PrintString(myFun.input);
}

void ChoiceB(FunWithStrings myFun)
{
    myFun.input = myFun.ReverseString(myFun.input);
    myFun.PrintString(myFun.input);
}

void ChoiceC(FunWithStrings myFun)
{
    cout << "Enter two letters. First letter is letter you want to replace. Second letter is letter you want to replace it with: ";
    cin >> myFun.letter1 >> myFun.letter2;
    myFun.input = myFun.ReplaceCharacters(myFun.input, myFun.letter1, myFun.letter2);
    myFun.PrintString(myFun.input);
}

void ChoiceD(FunWithStrings myFun)
{
    myFun.LetterCount = myFun.CountLetters(myFun.input, myFun.LetterCount);
    cout << myFun.LetterCount << " letters in your string." << endl;
}

void ChoiceE(FunWithStrings myFun)
{
    myFun.WordCount = myFun.CountWords(myFun.input, myFun.WordCount);
    cout << myFun.WordCount << " word(s) in your string." << endl;
}

void ChoiceZ(FunWithStrings myFun)
{
    cout << "Doing all of them! Scrambling string..." << endl;
    Sleep(3000);
    myFun.temp = myFun.input; // Storing original string so we can show it later.
    myFun.input = myFun.ScrambleString(myFun.input);

    cout << "Reversing string..." << endl;
    Sleep(3000);
    myFun.input = myFun.ReverseString(myFun.input);

    cout << "Replacing all letters E with Z..." << endl;
    Sleep(3000);
    myFun.input = myFun.ReplaceCharacters(myFun.input, 'e', 'z');

    cout << "Counting letters..." << endl;
    Sleep(3000);
    myFun.LetterCount = myFun.CountLetters(myFun.input);

    cout << "Counting words..." << endl;
    Sleep(3000);
    myFun.WordCount = myFun.CountWords(myFun.input);

    cout << "\n\nPutting all stats together...";
    Sleep(3000);
    cout << "\n\nStats: \n\n";
    cout << "Original string: " << myFun.temp << endl;
    cout << "Final string: " << myFun.input << endl;
    cout << "Letter count: " << myFun.LetterCount << endl;
    cout << "Word count: " << myFun.WordCount << endl;
}
