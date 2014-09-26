/* Write a program that opens a text file, reads it character-by-character to the end of
the file, and reports the number of characters in the file.
*/

#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 60;

int main()
{
    char letter;
    int charcount = 0;
    ifstream File;
    char Filename[SIZE];
    cout << "Hello. Enter the Filename you would like to open: " << endl;
    cin.getline(Filename, SIZE);

    File.open(Filename);

    if (!File.is_open())
        cout << "Could not open the file!" << endl;

    File >> letter;

    while (File.good())
    {
        File >> letter;
        charcount++;

    }
    if (charcount == 0)
        cout << "No characters found!" << endl;

    cout << "Characters read: " << charcount << endl;

    File.close();
    return 0;
}
