/* Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)
loops (for, while, do-while)
functions
strings & string functions


Write a program that asks for a user first name and last name separately.
The program must then store the users full name inside a single string and out put it to the string.
i.e.
Input:
John
Smith
Output:
John Smith

★ Modify the program so that it then replaces every a, e, i , o, u w/ the letter z.
i.e.
John Smith -> Jzhn Smzth

★★ Modify the Program so that it reverses the users name
i.e.
John Smith -> htimS nhoJ

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string firstname, lastname, finalstring, space = " ", modifiedstring, reversestring;
    cout << "What is your first name? ";
    getline(cin, firstname);
    cout << endl;
    cout << "What is your last name? ";
    getline(cin, lastname);
    cout << endl;

    finalstring = firstname + space + lastname;

    cout << "Your full name is: " << finalstring << "." << endl << endl;

    modifiedstring = finalstring;
    reversestring = finalstring;

    replace(modifiedstring.begin(), modifiedstring.end(), 'a', 'z' );
    replace(modifiedstring.begin(), modifiedstring.end(), 'e', 'z' );
    replace(modifiedstring.begin(), modifiedstring.end(), 'i', 'z' );
    replace(modifiedstring.begin(), modifiedstring.end(), 'o', 'z' );
    replace(modifiedstring.begin(), modifiedstring.end(), 'u', 'z' );

    reverse(reversestring.begin(), reversestring.end());

    cout << "Your full name containing the letters a, e, i, o, u that is replaced by the letter z is: " << modifiedstring << "." << endl << endl;
    cout << "Your full name reversed is: " << reversestring << "." << endl;
}
