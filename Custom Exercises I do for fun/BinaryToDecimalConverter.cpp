// Threw this together really quick for practice.

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void CopyStringToArray(string & input, int arr[], int size);
void BinaryToDecimal(int arr[], int size);

int main()
{
	string input;

	cout << "Enter binary numbers to convert from binary to decimal: ";
	getline(cin, input);

	int * arr = new int[input.size()];

	CopyStringToArray(input, arr, input.size());
	BinaryToDecimal(arr, input.size());
}

void BinaryToDecimal(int arr[], int size)
{
	int total = 0, temp = 0;

	for (int i = 1, j = size - 1; j >= 0; j--, i *= 2) // j starts at the end of the array because binary is read from right to left
	{
		temp = arr[j] * i;

		total += temp;
	}

	cout << "Decimal value: " << total << endl;
}

void CopyStringToArray(string & input, int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = input[i] - '0';
	}	
}
