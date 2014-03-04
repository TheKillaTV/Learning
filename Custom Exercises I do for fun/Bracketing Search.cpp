/* Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)
loops (for, while, do-while)
psudo random numbers

Write a program that calculates a random number 1 through 100. The program then asks the user to guess the number.
If the user guesses too high or too low then the program should output "too high" or "too low" accordingly.
The program must let the user continue to guess until the user correctly guesses the number.

★ Modify the program to output how many guesses it took the user to correctly guess the right number.

★★ Modify the program so that instead of the user guessing a number the computer came up with, the computer guesses the number that the user has secretely decided.
The user must tell the computer whether it guesed too high or too low.

★★★★ Modify the program so that no matter what number the user thinks of (1-100) the computer can guess it in 7 or less guesses.
*/

// Not sure how i can do the 4 star one...yet! But it can guess the number. Ill have to come back to this at some point.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int range(int high, int low)
{
    return rand() % (high - low) + low;
}

void UserGuessNumber()
{
    int tries = 0, num, computernumber2 = range(100, 1);

    cout << "Guess the computer's number" << endl;
    cin >> num;

    for(int i = 0; ; i++)
    {
        tries = tries + 1;

        if(num == computernumber2)
        {
            cout << endl;
            cout << "You guessed the correct number with " << tries << " tries." << endl;
            break;
        }
        else if(num > computernumber2)
        {
            cout << "Guess lower" << endl;
            cin >> num;
        }
        else if(num < computernumber2)
        {
            cout << "Guess higher" << endl;
            cin >> num;
        }
    }
}


void ComputerGuessesUsersNumber()
{
    int tries = 0, num, computernumber;

    cout << "Enter a number for the computer to guess that's between 0 and 100." << endl;
    cin >> num;

    for(int i = 0; ; i++)
    {
        tries = tries + 1;
        computernumber = range(100, 1);

        if(computernumber == num)
        {
            cout << "Computer guessed your number with " << computernumber << "." << endl;
            cout << endl;
            cout << "It took " << tries << " tries for it to guess your number" << endl;
            break;
        }
        else if(computernumber != num)
        {
            cout << "Computer guessed: " << computernumber << "." << endl;
        }
    }
}

int main()
{
    srand( time ( NULL) );

    int tries = 0, num, computernumber = range(100, 1), choice;

    cout << "Welcome. Which one would you like to play?" << endl;
    cout << endl;
    cout << "1. User guesses number" << endl;
    cout << "2. Computer guesses users number" << endl;
    cin >> choice;

    if(choice == 1)
    {
        UserGuessNumber();
    }
    else if(choice == 2)
    {
        ComputerGuessesUsersNumber();
    }
   else
    {
        cout << "Try again" << endl;
        return 0;
    }
}
