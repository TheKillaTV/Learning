/* Implement a simple "password" system that takes a password in the form of a number.
Make it so that either of two numbers are valid, but use only one if statement to do the check. */

#include <iostream>

using namespace std;

int main()
{
    int password;
    cout << "Please enter the password." << endl;
    cin >> password;

    do
    {


        if(password == 1 || password == 2)
        {
            cout << "Success!" << endl;
            return 0;
        }
        else
        {
            cout << "Try again" << endl;
            cin >> password;
        }
    } while (password != 1 || password != 2);
}
