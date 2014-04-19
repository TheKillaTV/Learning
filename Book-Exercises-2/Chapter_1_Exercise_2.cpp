/* Write a C++ program that asks for a distance in furlongs and converts it to yards.
(One furlong is 220 yards.)
*/

#include <iostream>

using namespace std;

int main()
{
    int convert;
    int yards;

    cout << "Enter a number to convert it from furlong to yards" << endl;
    cin >> convert;

    yards = convert * 220;

    cout << convert << " furlong(s) to yards is: " << yards << endl;
}
