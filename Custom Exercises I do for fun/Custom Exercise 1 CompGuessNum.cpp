/* You pick a number that's between 1 and 10, and the, "computer" keeps
picking a number from 1 to 10. Once it guesses your number. it'll print
how many tries it took for the, "computer" to guess your number. */

#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

int rand(int high, int low)
{
    return rand() % (high - low) + low;
}

int main()
{
    srand( time ( NULL) );
    int num, cnum;

    cout << "Pick a number for the computer to guess. It has to be between 1 and 10" << endl;
    cout << "Computer will guess number after you enter the number" << endl;
    cin >> num;

    do
    {
        if(num > 10)
        {
            cout << "Number is higher than 10. Try again" << endl;
            cin >> num;
        }
        else if(num < 1)
        {
            cout << "Number is lower than 1. Try again." << endl;
            cin >> num;
        }
    } while(num > 10 || num < 1);

    cout << "Number picked. Computer guessing now" << endl;
    cout << " " << endl;

    int tries = 0;

    for(int i = 0; i < 100; i++)
    {
        cnum = rand(11, 1);
        tries = tries + 1;

        cout << "Computer guessed: " << cnum << endl;

        if(cnum > num)
        {
            cout << "Computer guessed higher than your number!" << endl;
            cout << " " << endl;
        }
        else if(cnum < num)
        {
            cout << "Computer has guessed lower than your number!" << endl;
            cout << " " << endl;
        }
        else if(cnum == num)
        {
            cout << "Computer has guessed your number!" << endl;
            cout << " " << endl;
            cout << "It took the computer " << tries << " tries to get your number!" << endl;
            cout << " " << endl;
            cout << "Program ending now..." << endl;
            return 0;
        }
    }
}
