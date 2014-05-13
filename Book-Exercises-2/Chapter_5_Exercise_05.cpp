/*
You sell the book C++ for Fools.Write a program that has you enter a year’s worth
of monthly sales (in terms of number of books, not of money).The program should
use a loop to prompt you by month, using an array of char * (or an array of
string objects, if you prefer) initialized to the month strings and storing the input
data in an array of int. Then, the program should find the sum of the array contents
and report the total sales for the year.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int months[11];
    string monthsname[11] = {"Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "November", "December"};
    int total = 0;

    for(int i = 0; i < 11; i++)
    {
        months[i] = i + 1;
        cout << "Enter the # of sales for " << monthsname[i] << " " << endl;
        cin >> months[i];
        cout << endl;
        total += months[i];
        cout << "Books sold in " << monthsname[i] << ": " << months[i] << "." << endl;
        monthsname[i] = monthsname[i + 1];
        cout << endl;
    }

    cout << "The total sales for the year equals " << total << endl << endl << endl;
}
