/* Make your calculator program perform computations in a separate function for each type of computation. */

#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply (int x, int y)
{
    return x * y;
}

int divide (int x, int y)
{
    return x / y;
}

void add()
{
    int x, y;
    cout << "Enter two numbers to add." << endl;
    cin >> x;
    cout << x << " entered." << endl;
    cin >> y;
    cout << y << " entered" << endl;
    cout << "The answer is: " << add(x, y) << "." << endl;
}

void subtract()
{
    int x, y;
    cout << "Enter two numbers to subtract." << endl;
    cin >> x;
    cout << x << " entered." << endl;
    cin >> y;
    cout << y << " entered" << endl;
    cout << "The answer is: " << subtract(x, y) << "." << endl;
}

void multiply()
{
    int x, y;
    cout << "Enter two numbers to multiply." << endl;
    cin >> x;
    cout << x << " entered." << endl;
    cin >> y;
    cout << y << " entered" << endl;
    cout << "The answer is: " << multiply(x, y) << "." << endl;
}

void divide()
{
    int x, y;
    cout << "Enter two numbers to divide. No decimals." << endl;
    cin >> x;
    cout << x << " entered." << endl;
    cin >> y;
    cout << y << " entered" << endl;
    cout << "The answer is: " << divide(x, y) << "." << endl;
}



int main()
{
    int option;
    cout << "Pick one of the options below." << endl;
    cout << " " << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cin >> option;

    switch ( option )
    {
    case 1:
        add();
        break;
    case 2:
        subtract();
        break;
    case 3:
        multiply();
        break;
    case 4:
        divide();
        break;
    default:
        cout << "None of the options were selected. Exiting..." << endl;
        return 0;
        break;
    }
}
