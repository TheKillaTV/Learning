// How to dynamically allocate a 2D array.

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL)); // Seed
	int num1 = 0, num2 = 0;
	cout << "Enter a number: " << endl;
	cin >> num1;
	cout << "Enter another number: " << endl;
	cin >> num2;

	int** p = new int*[num1];

	for (int i = 0; i < num1; i++)
	{
		p[i] = new int[num2];
	}

	for (int i = 0; i < num1; i++) // Set values for the 2d array
	{
		for (int j = 0; j < num2; j++)
		{
			p[i][j] = rand() % 10 + 0;
		}
	}

	cout << "[" << num1 << "][" << num2 << "] 2d array allocated" << endl;

	for (int i = 0; i < num1; i++) // Display values and addresses
	{
		for (int j = 0; j < num2; j++)
		{
			cout << "Value: " << p[i][j] << endl;
			cout << "Address: " << &p[i][j] << endl;
		}
		cout << endl;
	}

	// Clean up array

	for (int i = 0; i < num2; i++)
		delete[] p[i];

	delete[] p;

	cout << "Dynamic array deleted" << endl;

	return 0;
}



