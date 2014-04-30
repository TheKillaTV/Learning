/* 
* Write a program that asks the user to type in numbers.After each entry, the program
* should report the cumulative sum of the entries to date.The program should
* terminate when the user enters 0.
*/


#include <iostream>

using namespace std;

int main()
{
    int number, total = 0;

    for(int i = 0; ; i++)
    {
        cout << "Enter a number for cumulative sum: ";
        cin >> number;
        total += number;
        cout << endl;
        cout << "Total so far is: " << total << endl;
        cout << endl;

        if(number == 0)
        {
            cout << "Exiting program... " << endl;
            return 0;
        }
    }
}
