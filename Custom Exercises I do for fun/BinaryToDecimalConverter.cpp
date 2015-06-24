// Threw this together really quick for practice.

#include "stdafx.h"
#include <iostream>

using namespace std;

void SetValuesToZero(int arr[], int size);
void GetUserInput(int arr[], int size);
void BinaryToDecimal(int arr[], int size);

int main()
{
	int size = 0;
	cout << "How many 1 or 0's? ";
	cin >> size;

	int * t = new int[size];

	SetValuesToZero(t, size);
	GetUserInput(t, size);
	BinaryToDecimal(t, size);

	delete t;
}

void SetValuesToZero(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

void GetUserInput(int arr[], int size)
{
	cout << "Enter a 1 or 0, then hit enter. Repeat until size is filled ";

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "Binary value: ";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}

	cout << endl;
}

void BinaryToDecimal(int arr[], int size)
{
	int total = 0, temp = 0;

	for (int i = 1, j = size - 1; j >= 0; j--, i *= 2)
	{
		temp = arr[j] * i;

		total += temp;
	}

	cout << "Decimal value: " << total << endl;
}
