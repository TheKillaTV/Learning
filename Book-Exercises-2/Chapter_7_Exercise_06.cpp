/*

Write a program that uses the following functions:

Fill_array() takes as arguments the name of an array of double values and an
array size. It prompts the user to enter double values to be entered in the array. It
ceases taking input when the array is full or when the user enters non-numeric
input, and it returns the actual number of entries.

Show_array() takes as arguments the name of an array of double values and an
array size and displays the contents of the array.

Reverse_array() takes as arguments the name of an array of double values and an
array size and reverses the order of the values stored in the array.

The program should use these functions to fill an array, show the array, reverse the
array, show the array, reverse all but the first and last elements of the array, and then
show the array.

*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const int size = 5;

void Fill_array(double arr[], int size);
void Show_array(const double arr[], int size);
void Reverse_array(double arr[], int size);

int main()
{
    double array[size];

    Fill_array(array, size); // Takes user input.
    Show_array(array, size); // Shows the array.
    cout << "--------------------" << endl;
    Reverse_array(array, size); // Reverse array.
    Show_array(array, size); // Show reversed array.
    cout << "--------------------" << endl;
    Reverse_array(array + 1, size - 2); // Reverse all but the first and last elements of the array
    Show_array(array, size); // Show array yet again.
    cout << "--------------------" << endl;

}

void Fill_array(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value for value number " << i + 1 << "." << endl;
        cin >> arr[i];
    }
}

void Show_array(const double arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << "Value for " << i + 1 << " is: " << arr[i] << endl;
}

void Reverse_array(double arr[], int size)
{
    double temp;

    for (int i = 0; i <= size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
