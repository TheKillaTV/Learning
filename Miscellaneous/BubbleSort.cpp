
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void SortArrayAscending(int arr[], int size);
void SortArrayDescending(int arr[], int size);
void SetRandomValues(int arr[], int size);
void PrintArray(int arr[], int size);
bool AskWayToSort();

int main()
{
	srand(time(NULL));
	int input = 0;
	cout << "How many random numbers do you want to be generated in the array? " << endl;
	cin >> input;
	cout << "---------" << endl;

	int * numbers = new int[input];

	bool Sort = AskWayToSort();

	SetRandomValues(numbers, input);
	cout << "* Unsorted numbers * " << endl;
	PrintArray(numbers, input);
	
	if (Sort)
		SortArrayAscending(numbers, input);
	else
		SortArrayDescending(numbers, input);

	cout << "----------" << endl;
	cout << "* Sorted numbers * " << endl;
	PrintArray(numbers, input);

	delete[] numbers;
}

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void SetRandomValues(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 0;
	}
}

void SortArrayAscending(int arr[], int size) // Bubble sort
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SortArrayDescending(int arr[], int size) // Bubble sort
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - 1); j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


bool AskWayToSort()
{
	char answer;
	cout << "Sort from smallest to largest or largest to smallest?" << endl;
	cout << "Y. Smallest to largest" << endl;
	cout << "N. largest to smallest" << endl;
	cin >> answer;
	cout << "--------" << endl;

	if (answer == 'Y' || answer == 'y')
		return true;
	else
		return false;
}
