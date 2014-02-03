/* Write a program that simulates a coin flip. Run it many times. Do the results look random to you? */


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


int randrange(int high, int low)
{
    return rand() % (high - low) + low;
}

int main()
{
    int random;
    int i;
    srand( time ( NULL) );
    for (i = 0; i < 1; ++i)
    {
        int random = randrange(3, 1);
        cout << random << endl;

        if(random == 1)
        {
            cout << "Heads!" << endl;
        }
        else
        {
            cout << "Tails!" << endl;
        }
    }
}
