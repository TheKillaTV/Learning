/* Write a small calculator that takes as input one of the four arithmetic operations, the two arguments to those operations, and then prints out the result */

#include <iostream>
#include <string>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

int main()
{
    string option;

    cout << "Welcome to the Sweats calculator. Type out one of the options, then hit enter to proceed." << endl;
    cout << " " << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;

    cin >> option;

    int x;
    int y;

        if(option == "addition")
        {
            cout << "Pick two numbers to add." << endl;
            cin >> x;
            cin >> y;
            cout << "The answer is: " << add(x, y) << endl;
        }
        else if(option == "subtraction")
        {
            cout << "Pick two numbers to subtract." << endl;
            cin >> x;
            cin >> y;
            cout << "The answer is: " << subtract(x, y) << endl;
        }
        else if(option  == "multiply")
        {
            cout << "Pick two numbers to multiply." << endl;
            cin >> x;
            cin >> y;
            cout << "The answer is: " << multiply(x, y) << endl;
        }
        else if(option == "divide")
        {
            cout << "Pick two numbers (no decimals) to divide" << endl;
            cin >> x;
            cin >> y;
            cout << "The answer is: " << divide(x, y) << endl;
        }
        else
        {
            cout << option << " is not one of the choices. Try again next time." << endl;
            return 0;
        }
}
