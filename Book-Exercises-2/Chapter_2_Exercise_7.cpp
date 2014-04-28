/*
* Write a program that asks you to enter an automobile gasoline consumption figure
* in the European style (liters per 100 kilometers) and converts to the U.S. style of
* miles per gallon. Note that in addition to using different units of measurement, the
* U.S. approach (distance / fuel) is the inverse of the European approach (fuel / distance).
* Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters.Thus, 19
* mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km.
*
*    100 km = 62.14 mi.           1 gallon = 3.875 Liters.
*/

#include <iostream>

using namespace std;

int main()
{
    double liters, distance;
    double output, Gallons, Miles, MilesPerGallon;

    cout << "Enter the amount of liters you have used." << endl;
    cin >> liters;
    cout << "Enter the amount of distance you've traveled in km" << endl;
    cin >> distance;

    output = liters / distance;
    Gallons = liters / 3.875;
    Miles = distance * 0.621371;
    MilesPerGallon = Miles / Gallons;

    cout << "Your liters per 100 kilometers is: " << output << "." << endl;
    cout << endl;

    cout << "Your distance in miles is: " << Miles << "." << endl;
    cout << endl;

    cout << "Your fuel in gallons is: " << Gallons << "." << endl;
    cout << endl;

    cout << "Your miles per gallon is: " << MilesPerGallon << "." << endl;
}
