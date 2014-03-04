/* Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)

Write a program that presents the user w/ a choice of your 5 favorite beverages (Coke, Water, Sprite, ... , Whatever).
Then allow the user to choose a beverage by entering a number 1-5.
Output which beverage they chose.

★ If you program uses if statements instead of a switch statement, modify it to use a switch statement.
If instead your program uses a switch statement, modify it to use if/else-if statements.

★★ Modify the program so that if the user enters a choice other than 1-5 then it will output "Error. choice was not valid, here is your money back."
*/

#include <iostream>

using namespace std;


int main()
{
    int beverage;
    cout << "Pick one of the beverages" << endl;
    cout << endl;
    cout << "1. Coke" << endl;
    cout << "2. Water" << endl;
    cout << "3. Sprite" << endl;
    cout << "4. Dr. Pepper" << endl;
    cout << "5. Milk" << endl;
    cin >> beverage;

    switch(beverage)
    {
    case 1:

        cout << "Coke selected" << endl;
        break;

    case 2:

        cout << "Water selected" << endl;
        break;

    case 3:

        cout << "Sprite selected" << endl;
        break;

    case 4:

        cout << "Dr. Pepper selected" << endl;
        break;

    case 5:

        cout << "Milk selected" << endl;
        break;

    default:
        cout << "Error. choice was not valid, here is your money back." << endl;
        break;
    }
}
