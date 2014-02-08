/* Write a password prompt that gives a user only a certain number of password entry attempts— 
so that the user cannot easily write a password cracker. */

#include <iostream>

using namespace std;

int main()
{
    string password;
    cout << "Enter the password. You only have 5 tries." << endl;
    cin >> password;

    if(password == "sweats")
    {
        cout << "You did it!" << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i < 6; i++)
        {
            cout << i << " tries used." << endl;
            cin >> password;

            if(i == 5)
            {
                cout << "All 5 tries were already used. Program terminating..." << endl;
                return 0;
            }
        }
    }
}
