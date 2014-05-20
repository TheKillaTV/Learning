/* Write a program that reads up to 10 donation values into an array of double. (Or, if you prefer, use an array template object).
The program should terminate input on non-numeric input. It should report the average of the numbers and also report how many numbers
in the array are larger than the average.
*/

#include <iostream>

using namespace std;

const int ArraySize = 10;

int main()
{

    int number = 0, total = 0, AboveAverage = 0;
    double value[ArraySize];
    double average = 0.0;

    for (int i = 0; i < 10; i++)
    {
        number += 1;
        cout << "Enter the donation value for number " << number << ". ";
        cin >> value[i];
        total += value[i];

        if (i == 9)
        {
            average = total / number;
            cout << "The total is: " << total << endl;
            cout << "The average is: " << average << endl;
        }
    }

    for (int j = 0; j < 10; j++)
    {
        if (value[j] > average)
            AboveAverage += 1;
    }

    cout << "Their are " << AboveAverage << " numbers that are greater than the average (" << average << ")." << endl;
}
