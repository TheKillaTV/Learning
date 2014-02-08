/* Write a program that prints out the entire lyrics to a full rendition of "99 bottles of beer". */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ready;

    cout << "After you type in the word ready, the console will output the," << endl;
    cout << "'99 bottles of beer' song." << endl;
    cin >> ready;

    if(ready == "ready")
    {
        for (int i = 99; i  > 0; i--)
        {
            cout << i << " bottles of beer on the wall, " << i << " bottles of beer on the wall" << endl;
            cout << " " << endl;
            cout << "Take one down, pass it around, " << i - 1 << " bottles of beer on the wall..." << endl;
            cout << " " << endl;
        }
    }
    else
    {
        cout << "Re-launch program and try again." << endl;
        return 0;
    }
}
