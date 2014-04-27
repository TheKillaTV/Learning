/*
* Write a short program that asks for your height in integer inches and then converts
* your height to feet and inches. Have the program use the underscore character to
* indicate where to type the response. Also use a const symbolic constant to represent
* the conversion factor.

        1 ft = 12 inches.
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int foot = 12;
    int height, feet, feetremainder;
    cout << "Enter your height in inches to convert to feet and inches" << endl;
    cin >> height;
    cout << "______" << endl;

    feet = height / foot;
    feetremainder = height % foot;

    cout << "Your height in feet and inches are: " << feet << " ft " << feetremainder << " in." << endl;
}
