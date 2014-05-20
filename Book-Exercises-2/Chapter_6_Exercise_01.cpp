/* Write a program that reads keyboard input to the @ symbol and that echoes the input except for digits,
converting each uppercase character to lowercase, and vice versa. (Don't forget the cctype family).
*/

#include <iostream>
#include <cctype>

using namespace std;


int main()
{
    char input;

    cout << "Enter a letter: ";
    cin.get(input);

    while(input != '@')
    {
        if(islower(input))
        {
            input = toupper(input);
            cout << input << " is now uppercase." << endl;
            break;
        }
        else if(isupper(input))
        {
            input = tolower(input);
            cout << input << " is now lowercase." << endl;
            break;
        }
        else if(input >= 0 || input <= 0)
        {
            cout << "Don't enter a digit" << endl;
            return 0;
        }
    }
}
