/* Write a program that asks how many miles you have driven and how many gallons
* of gasoline you have used and then reports the miles per gallon your car has gotten.
* Or, if you prefer, the program can request distance in kilometers and petrol in liters
* and then report the result European style, in liters per 100 kilometers.
*/

#include <iostream>

using namespace std;

int main()
{
    double miles, gallon, output;
    cout << "How many miles have you driven?" << endl;
    cin >> miles;
    cout << "How many gallons of gasoline have you used?" << endl;
    cin >> gallon;

    output = miles / gallon;

    cout << "Your miles per gallon is: " << output << endl;
}
