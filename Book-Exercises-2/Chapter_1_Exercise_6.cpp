/* Write a program that has main() call a user-defined function that takes a distance
in light years as an argument and then returns the distance in astronomical units.
The program should request the light year value as input from the user and display
the result, as shown in the following code:

Enter the number of light years: 4.2
4.2 light years = 265608 astronomical units.
*/

#include <iostream>

using namespace std;

void LightYearsToAstronomicalUnits();

int main()
{
   double lightyears, units;
   LightYearsToAstronomicalUnits();
}

void LightYearsToAstronomicalUnits()
{
    double lightyears, units;

    cout << "Enter the amount of light years." << endl;
    cin >> lightyears;

    units = lightyears * 63239.7263;

    cout << lightyears << " light years = " << units << " astronomical units." << endl;
}
