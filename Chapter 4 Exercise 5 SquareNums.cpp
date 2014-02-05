/* Write a program that displays the first 20 square numbers. */

#include <iostream>

using namespace std;

int main()
{
    int i;

    cout << "This program will print the first 20 square numbers. Enter 1 to begin" << endl;
    cin >> i;

        if( i== 1)
        {
            for(i = 0; i <= 20; i++)
            {
                cout << " The square of " << i  << " equals " << i * i << endl;
            }
        }
        else
        {
          cout << "You fail." << endl;
        }
}
