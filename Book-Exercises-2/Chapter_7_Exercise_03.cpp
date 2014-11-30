/*

Here is a structure declaration:
struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};
a. Write a function that passes a box structure by value and that displays the
value of each member.
b. Write a function that passes the address of a box structure and that sets the
volume member to the product of the other three dimensions.
c. Write a simple program that uses these two functions.

*/

#include <iostream>

using namespace std;

struct box
{
    string maker; // Strings are better for names.
    float height;
    float width;
    float length;
    float volume;
};

void pass_by_value(box a);
void pass_by_address(box * b);

int main()
{
    box stats = {"Sweats", 1.37, 4.5, 6.9, 9.6};
    char input;
    cout << "Do you want to pass the box structure by value or address? " << endl;
    cout << "A. By value" << endl;
    cout << "B. By address" << endl;
    cin >> input;
    cin.ignore(); // Leaves newline character in the stream. Must use if next user input is getline otherwise the program will skip right over it.

    if (input == 'A' || input == 'a')
        pass_by_value(stats);
    else if (input == 'B' || input == 'b')
        pass_by_address(&stats);
    else
        cout << "Program exiting. Please pick one of the two options next time!" << endl;
}

void pass_by_value(box a)
{
    cout << "Name of the box: " << a.maker << endl << endl;
    cout << "Height of the box: " << a.height << endl << endl;
    cout << "Width of the box: " << a.width << endl << endl;
    cout << "Length of the box: " << a.length << endl << endl;
    cout << "Volume of the box: " << a.volume << endl << endl;
}

void pass_by_address(box * b) // -> is used because pointer.
{
    cout << "Name of the box: " << b->maker << endl << endl;
    cout << "Height of the box: " << b->height << endl << endl;
    cout << "Width of the box: " << b->width << endl << endl;
    cout << "Length of the box: " << b->length << endl << endl;
    cout << "Volume of the box: " << b->volume << endl << endl;
}
