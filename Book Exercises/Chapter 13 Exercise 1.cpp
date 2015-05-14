/* 

Write a function that prompts the user to enter his or her first name and last name, as two separate
values.This function should return both values to the caller via additional pointer(or reference)
parameters that are passed to the function.Try doing this first with pointers and then with references.
(Hint: the function signature will look be similar to the swap function from earlier!)

*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void pPrintName(const string  * first, const string * last);
void PrintName(const string & first, const string & last);


int main()
{
	string FirstName;
	string LastName;

	cout << "Enter First name: ";
	getline(cin, FirstName);
	cout << endl;
	cout << "Enter Last name: ";
	getline(cin, LastName);

	PrintName(FirstName, LastName);
	pPrintName(&FirstName, &LastName);


}

void pPrintName(const string * first , const string * last)
{
	cout << "Pass by pointer: " << endl; 
	cout << *first << " " << *last << endl << endl;
}

void PrintName(const string & first, const string & last)
{
	cout << "Pass by reference: " << endl;
	cout << first << " " << last << endl << endl;
}
