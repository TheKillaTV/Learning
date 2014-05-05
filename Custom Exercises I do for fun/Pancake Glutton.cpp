/*

Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)
loops (for, while, do-while)
arrays

Write a program that asks the user to enter the number of pancakes eaten for breakfast by 10 different people (Person 1, Person 2, ..., Person 10)
Once the data has been entered the program must analyze the data and output which person ate the most pancakes for breakfast.

★ Modify the program so that it also outputs which person ate the least number of pancakes for breakfast.

★★★★ Modify the program so that it outputs a list in order of number of pancakes eaten of all 10 people.
i.e.
Person 4: ate 10 pancakes
Person 3: ate 7 pancakes
Person 8: ate 4 pancakes
...
Person 5: ate 0 pancakes

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int people[10] = {0};
    int pancakes[10] = {0};
    cout << "Enter the number of pancakes eaten for breakfast by 10 different people" << endl;

    for(int i  = 0; i < 10; i++)
    {
        cout << "Enter person number: ";
        cin >> people[i];
        cout << "How many pancakes did person: " << people[i] << " eat? ";
        cin >> pancakes[i];
    }

    cout << endl << endl;

    for(int j = 0; j < 10; j++)
    {
        cout << "Person: " << people[j] << " ate " << pancakes[j] << " pancakes." << endl;
    }
    cout << endl;

    sort(pancakes, pancakes + 10);

    cout << "SORTED NUMBERS:" << endl << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << "Person: " << people[i] << " ate " << pancakes[i] << " pancakes" << endl;
    }
}
