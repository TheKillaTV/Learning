/* Take the "menu program" you wrote earlier and break it out into a series of calls to functions for  each of the menu items.
Add the calculator and "100 bottles of beer" as two different functions that can be called. */

#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract (int x, int y)
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

double divideDecimal(double dec1, double dec2)
{
    return dec1 / dec2;
}

int square(int x)
{
    return x * x;
}

void DisplayCalculatorOptions()
{
    int calcoption;
    cout << "Pick one of the options below" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Division (Decimals)" << endl;
    cout << "6. Square Number" << endl;
    cin >> calcoption;

    int x, y;
    double decimal1, decimal2, dec1, dec2;

    switch ( calcoption )
    {
    case 1:
        cout << "Addition selected. Enter two numbers to add together" << endl;
        cin >> x;
        cout << "You've entered: " << x << ". Now input 2nd number." << endl;
        cin >> y;
        cout << "You've entered: " << y << "." << endl;
        cout << " " << endl;
        cout << "The answer is: " << add(x, y) << "!" << endl;
        break;
    case 2:
        cout << "Subtraction selected. Enter two numbers to subtract" << endl;
        cin >> x;
        cout << "You've entered: " << x << ". Now input 2nd number." << endl;
        cin >> y;
        cout << "You've entered: " << y << "." << endl;
        cout << " " << endl;
        cout << "The answer is: " << subtract(x, y) << "!" << endl;
        break;
    case 3:
        cout << "Multiplication selected. Enter two numbers to multiply." << endl;
        cin >> x;
        cout << "You've entered: " << x << ". Now enter 2nd number." << endl;
        cin >> y;
        cout << "You've entered: " << y << "." << endl;
        cout << " " << endl;
        cout << "The answer is: " << multiply(x, y) << "!" << endl;
        break;
    case 4:
        cout << "Division selected. Enter two whole numbers to divide" << endl;
        cin >> x;
        cout << "You've entered: " << x << ". Now enter 2nd number." << endl;
        cin >> y;
        cout << "You've entered: " << y << "." << endl;
        cout << " " << endl;
        cout << "The answer is: " << divide(x, y) << "!" << endl;
        break;
    case 5:
        cout << "Division with decimals selected. Enter two decimals to divide" << endl;
        cin >> decimal1;
        cout << "You've entered: " << decimal1 << ". Now enter 2nd decimal." << endl;
        cin >> decimal2;
        cout << "You've entered: " << decimal2 << "." << endl;
        cout << " " << endl;
        cout << "The answer is: " << divideDecimal(dec1, dec2) << "!" << endl;
        break;
    case 6:
        cout << "Enter a number to square." << endl;
        cin >> x;
        cout << "The answer is: " << square(x) << "!" << endl;
        break;
    default:
        cout << "None of the options were selected. Exiting..." << endl;
        break;
    }

}

void BottlesOfBeer()
{
    int go;
    cout << "Here, you will see the bottles of beer song print to console. Hit 1 to continue" << endl;
    cout << "If input is not 1, then the program will exit" << endl;
    cin >> go;

    if(go == 1)
    {
        for(int i = 99; i > 0; i--)
        {
            cout << i << " bottles of beer on the wall, " << i << " bottles of beer on the wall." << endl;
            cout << "Take one down, pass it around, " << i - 1 << " bottles of beer on the wall" << endl;
        }
    }
    else
    {
        cout << "Exiting..." << endl;
    }
}

int main()
{
    int option;
    cout << "Welcome to the Sweats menu. Pick one of the options below." << endl;
    cout << " " << endl;
    cout << "1. Calculator" << endl;
    cout << "2. 99 Bottles of Beer song" << endl;
    cout << "3. Exit" << endl;
    cin >> option;

    switch(option)
    {
    case 1:
        DisplayCalculatorOptions();
        break;
    case 2:
        BottlesOfBeer();
        break;
    case 3:
        cout << "Exiting..." << endl;
        return 0;
        break;
    default:
        cout << "No input selected. Exiting" << endl;
        return 0;
        break;
    }

}
