/* Write a menu program that lets the user select from a list of options,
   and if the input is not one of the options, reprint the list */

#include <iostream>

using namespace std;

void options()
{
    int option;

    cout << "Select one of the options below" << endl;
    cout << "1. Sweats" << endl;
    cout << "2. Joe momma" << endl;
    cout << "3. Exit" << endl;
}

int main()
{
    int option;
    options();
    cin >> option;

    do
    {

        if (option == 1)
        {
            cout << "Option Sweats selected. You are awesome! Program exits now." << endl;
            return 0;
        }
        else if (option == 2)
        {
            cout << "Joe momma was here! Program exits now." << endl;
            return 0;
        }
        else if (option == 3)
        {
            cout << "Exiting..." << endl;
            return 0;
        }
        else
        {
            options();
            cin >> option;
        }
    } while (option > 3 || option < 1);
}
