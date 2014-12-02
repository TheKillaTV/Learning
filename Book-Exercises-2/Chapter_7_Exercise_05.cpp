/*

Define a recursive function that takes an integer argument and returns the factorial
of that argument. Recall that 3 factorial, written 3!, equals 3 × 2!, and so on, with 0!
defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!.Test your function
in a program that uses a loop to allow the user to enter various values for which the
program reports the factorial.

*/


#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Factorial(int n);

int main()
{
    int number;
    cout << "Enter a number to calculate its factorial ";
    cin >> number;
    Factorial(number);
}

void Factorial(int n)
{
    long int total = 1;

    for (int i = 1; i <= n; i++)
        total *= i;

    cout << "The factorial is " << total << endl;
    cout << "Enter new number: ";
    cin >> n;

    Factorial(n);
}
