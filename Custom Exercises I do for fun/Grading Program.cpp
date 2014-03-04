/* Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)

Write a program that allows the user to enter the grade scored in a programming class (0-100).
If the user scored a 100 then notify the user that they got a perfect score.

★ Modify the program so that if the user scored a 90-100 it informs the user that they scored an A

★★ Modify the program so that it will notify the user of their letter grade
0-59 F 60-69 D 70-79 C 80-89 B 90-100 A */

#include <iostream>

using namespace std;

int main()
{
    int grade;
    cout << "Enter your grade for the programming class" << endl;
    cin >> grade;

    if(grade == 100)
    {
        cout << "Perfect score!" << endl;
    }
    else if(grade <= 99 && grade >= 90)
    {
        cout << "You got an A!" << endl;
    }
    else if(grade <= 89 && grade >= 80)
    {
        cout << "You got a B!" << endl;
    }
    else if(grade <= 79 && grade >= 70)
    {
        cout << "You got a C!" << endl;
    }
    else if(grade <= 69 && grade >= 60)
    {
        cout << "You got a D!" << endl;
    }
    else if(grade >= 59)
    {
        cout << "You got an E :(" << endl;
    }
}
