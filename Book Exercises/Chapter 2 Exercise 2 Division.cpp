/* Write a program that performs division of two numbers read from the user and prints out an exact result.
Make sure to test your program with both integer inputs and decimal inputs. */

#include <iostream>

using namespace std;

int main()
{
    int option;
    
    cout << "Would you like to divide..." << endl;
    cout <<  "1. Integers" << endl;
    cout << "2. Decimals" << endl;
    cout << "3. Enter any number that's not 1 or 2 to exit." << endl;
    cin >> option;


    if (option == 1)
    {
        int x;
        int y;

        cout << "You will divide two integers. Enter the first number." << endl;
        cin >> x;
        cout << "You've entered: " << x << ". Now enter the second number." << endl;
        cin >> y;
        cout << "You've entered: " << y << ". Now they divide." << endl;
        cout << " " << endl;
        cout << "The answer is: " << x / y << "." << endl;
    }

    else if (option == 2)
    {
        double a;
        double b;

        cout << "You will divide two decimals. Enter the first decimal." << endl;
        cin >> a;
        cout << "You've entered: " << a << ". Now enter the second decimal." << endl;
        cin >> b;
        cout << "You've entered: " << b << ". Now they divide." << endl;
        cout << " " << endl;
        cout << "The answer is: " << a / b << "." << endl;
    }

    else
    {
        cout << "Exiting." << endl;
        return 0;
    }
}
