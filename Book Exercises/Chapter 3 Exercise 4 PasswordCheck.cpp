/* Expand the password checking program from earlier in this chapter and make it take multiple usernames, each with their own password, and ensure that the right username is used for the right password.
Provide the ability to prompt user's again if the first login attempt failed.
Think about how easy (or hard) it is to do this for a lot of usernames and passwords. */

// My thought: A loop is a lot better!

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string username;
    string username2;
    string password;
    string password2;


    cout << "Please enter one of the four usernames and passwords." << endl;
    cin >> username;

    if (username == "sweats" || username == "sweats2" || username == "sweats3" || username == "sweats4")
    {

        cout << "Good! Now enter one of the passwords" << endl;
        cin >> password;

        if (password == "password" || password == "password2" || password == "password3" || password == "password4")
        {
            cout << "Congratulations! You have completed this program!" << endl;
        }

        else
        {
            cout << "Try again. You only get 1 try!" << endl;
            cin >> password2;

            if(password2 == "password" || password2 == "password2" || password2 == "password3" || password2 == "password4")
            {
                cout << "You made it with only 1 mistake!" << endl;
            }
            else
            {
                cout << "Tries used. Exiting..." << endl;
                return 0;
            }
        }
    }
    else
    {

        cout << "Try again. You only get 1 try!" << endl;
        cin >> username2;

        if(username2 == "sweats" || username2 == "sweats2" || username2 == "sweats3" || username2 == "sweats4")
        {

            cout << "K. You got it this time. Now for password." << endl;
            cin >> password2;

            if(password2 == "password" || password2 == "password2" || password2 == "password3" || password2 == "password4")
            {
                cout << "You made it with only 1 mistake!" << endl;
            }
            else
            {
                cout << "Tries used. Exiting..." << endl;
                return 0;
            }

        }
        else
        {
            cout << "Tries used. Exiting..." << endl;
            return 0;
        }
    }

}
