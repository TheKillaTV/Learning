/* Write a program that asks the user to enter an hour value and a minute value.The
main() function should then pass these two values to a type void function that displays
the two values in the format shown in the following sample run:

Enter the number of hours: 9
Enter the number of minutes: 28
Time: 9:28
*/

#include <iostream>

using namespace std;

void SetTime();

int main()
{
    int hours, minutes;
    SetTime();
}

void SetTime()
{
    int hours, minutes;

    cout << "Enter the number of hours." << endl;
    cin >> hours;
    cout << "Enter the amount of minutes" << endl;
    cin >> minutes;
    cout << "\n";

    cout << "Time: " << hours << ":" << minutes << endl;
}
