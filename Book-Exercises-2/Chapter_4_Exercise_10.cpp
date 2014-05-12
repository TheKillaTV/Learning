/* Write a program that requests the user to enter three times for the 40-yd dash (or 40-meter, if you prefer), and then displays
the times and the average. Use an array object to hold the data. (Use a built-in array if array is not available).
*/

#include <iostream>

using namespace std;

int main()
{
    int times[2];
    double average = 0.0;

    cout << "Enter the first time in seconds: ";
    cin >> times[0];
    cout << "Enter the second time in seconds: ";
    cin >> times[1];
    cout  << "Enter the third time in seconds: ";
    cin >> times[2];

    cout << "Times: " << endl << endl;

    cout << "First time: " << times[0] << "." << endl;
    cout << "Second time: " << times[1] << "." << endl;
    cout << "Third time: " << times[2] << "." << endl;

    average = (times[0] + times[1] + times[2]) / 3;

    cout << "The average is: " << average << "." << endl;
}
