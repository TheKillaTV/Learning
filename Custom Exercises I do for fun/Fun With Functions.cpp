/* Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)
loops (for, while, do-while)
functions

Write a function titled say_hello() that outputs to the screen "Hello"

★ Modify the function so that it takes an integer argument and says hello a number of times equal to the value passed to it.

★★ Make another function that takes two integers arguments and then returns an integer that is the product of the two integers.
(i.e., integer1: 4, Integer2: 5 returns: 20)

★★★ Make a function called half() that takes an integer argument. The function must print the number it received to the screen,
then the program should divide that number by two to make a new number.
If the new number is greater than zero the function then calls the function half() passing it the new number as its argument.
If the number is zero or less than the function exits

Call the function half() with an argument of 100, the screen output should be
100
50
25
...
...
1.
*/

#include <iostream>

using namespace std;

void say_hello()
{
    int number;
    cout << "Enter a number for the amount of times hello is printed to the screen" << endl;
    cin >> number;


        for(int i = 0; i <= number; i++)
        {
            cout << "Hello!" << endl;
            cout << endl;

            if(i == number)
            {
                cout << "Hello printed to screen " << number << " times." << endl;
                break;
            }
        }
}

int multiply(int x, int y)
{
    cout << "Enter two numbers to multiply" << endl;
    cin >> x;
    cin >> y;

    return x * y;
}

void half()
{
    int number;
    cout << "Enter an amount" << endl;
    cin >> number;

    for(int i = 0; ; i++)
    {
        number = number / 2;
        cout << number << endl;

        if(number <= 0)
        {
            cout << "Done!" << endl;
            break;
        }
    }

}

int main()
{

int option, number, x, y;
cout << "Which option do you want to chose?" << endl;
cout << endl;
cout << "1. Say Hello" << endl;
cout << "2. Half" << endl;
cout << "3. Multiply" << endl;
cin >> option;

    switch(option)
    {
    case 1:
        say_hello();
        break;

    case 2:
        half();
        break;

    case 3:
        cout << "The answer is: " << multiply(x, y) << "!" << endl;
        break;

    default:
        cout << "Try again" << endl;
        return 0;
        break;
    }
}
