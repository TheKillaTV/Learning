/* Write a program that reads in two numbers and adds them together. */

#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    cout << "You will enter two numbers to add them together. Enter the first number." << endl;
    cin >> x;
    cout << "You've entered: " << x << ". Now enter the second number." << endl;
    cin >> y;
    cout << "You've entered: " << y << ". Now they add" << endl;
    cout << " " << endl;
    cout << "The answer is: " << x + y << endl;
}
