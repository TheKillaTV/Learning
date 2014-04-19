/* Write a program that asks the user to enter his or her age. The program then should
display the age in months.
*/

#include <iostream>

using namespace std;

int main()
{
    int years, months;

    cout << "Enter your age to convert into months" << endl;
    cin >> years;

    months = years * 12;

    cout << "Your age in months is: " << months << "." << endl;
}
