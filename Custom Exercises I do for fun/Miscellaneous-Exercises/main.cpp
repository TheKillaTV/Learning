// Custom exercise to understand about overloading constructors

#include "stdafx.h"
#include <iostream>
#include "Tutorial.h"
#include <cstdlib>
#include <ctime>


int main()
{
	srand(time(NULL));

	Tutorial tut, tut1("Contructor1"), tut2("Constructor2", 69), tut3("Constructor3", 69, 1337.0), tut4("Constructor4", 69, 1337.0, 525.0);

	cout << "Default contructor with no parameters: " << endl << endl;
	cout << tut.toString() << endl;
	cout << endl << endl;
	cout << "Default contructor with 1 parameter: " << endl << endl;
	cout << tut1.toString() << endl;
	cout << endl << endl;
	cout << "Default constructor with 2 parameters:" << endl << endl;
	cout << tut2.toString() << endl;
	cout << endl << endl;
	cout << "Default contructor with 3 parameters: " << endl << endl;
	cout << tut3.toString() << endl;
	cout << endl << endl;
	cout << "Default contructor with 4 parameters: " << endl << endl;
	cout << tut4.toString() << endl;

	return 0;
}
