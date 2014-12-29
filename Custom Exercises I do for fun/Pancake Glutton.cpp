/*Requires:
variables, data types, and numerical operators
basic input / output
logic(if statements, switch statements)
loops(for, while, do - while)
arrays

Write a program that asks the user to enter the number of pancakes eaten for breakfast by 10 different people(Person 1, Person 2, ..., Person 10)
Once the data has been entered the program must analyze the data and output which person ate the most pancakes for breakfast.

★ Modify the program so that it also outputs which person ate the least number of pancakes for breakfast.

★★★★ Modify the program so that it outputs a list in order of number of pancakes eaten of all 10 people.
i.e.
Person 4: ate 10 pancakes
Person 3 : ate 7 pancakes
Person 8 : ate 4 pancakes
...
Person 5 : ate 0 pancakes
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int size = 11;

void InputArray(int arr[], int size);
void OutputArray(const int arr[], int size);

int main()
{
	int Pancakes[size] = { 0 };
	InputArray(Pancakes, size);
	OutputArray(Pancakes, size);
}

void InputArray(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		cout << "Enter number of pancakes eaten for person " << i << "." << endl;
		cin >> arr[i];
	}
}

void OutputArray(const int arr[], int size)
{
	int temp = 99999, temp2 = 0, most = 0, least = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < temp)
		{
			temp = arr[i];
			least = i;
		}
		else if (arr[i] > temp2)
		{
			temp2 = arr[i];
			most = i;
		}
		cout << "Person " << i << ": ate " << arr[i] << " pancakes." << endl;
	}
	cout << "Person " << most << " ate the most amount of pancakes (" << temp2 << ")" << endl;
	cout << "Person " << least << " ate the least amount of pancakes (" << temp << ")" << endl;
}
