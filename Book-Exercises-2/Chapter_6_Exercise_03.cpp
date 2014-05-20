/* 

Write a precursor to a menu-driven program.The program should display a menu
offering four choices, each labeled with a letter. If the user responds with a letter
other than one of the four valid choices, the program should prompt the user to
enter a valid response until the user complies.Then the program should use a
switch to select a simple action based on the user’s selection.A program run could
look something like this:

Please enter one of the following choices:

c) carnivore 
p) pianist
t) tree 
g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.

*/


#include <iostream>

using namespace std;

int main()
{
    char choice;

    cout << "Please enter one of the following choices (Enter the letter not the number): " << endl << endl;
    cout << "A) One" << endl;
    cout << "B) Two" << endl;
    cout << "C) Three" << endl;
    cout << "D) Four" << endl;

    cin >> choice;

    if (choice != 'a' && choice != 'A' && choice != 'b' && choice != 'B' && choice != 'c' && choice != 'C' && choice != 'c' && choice != 'D' && choice != 'd')
    {
        do
        {
            cout << "Please enter A, B, C, or D: ";
            cin >> choice;

        } while (choice != 'a' && choice != 'A' && choice != 'b' && choice != 'B' && choice != 'c' && choice != 'C' && choice != 'c' && choice != 'D' && choice != 'd');
    }
    
    switch(choice)
    {
    case 'A':
        cout << "You picked number one!" << endl;
        break;
    case 'B':
        cout << "You picked number two!" << endl;
        break;
    case 'C':
        cout << "You picked number three!" << endl;
        break;
    case 'D':
        cout << "You picked number four!" << endl;
        break;
    case 'a':
        cout << "You picked number one!" << endl;
        break;
    case 'b':
        cout << "You picked number two!" << endl;
        break;
    case 'c':
        cout << "You picked number three!" << endl;
        break;
    case 'd':
        cout << "You picked number four!" << endl;
        break;
    }
}
