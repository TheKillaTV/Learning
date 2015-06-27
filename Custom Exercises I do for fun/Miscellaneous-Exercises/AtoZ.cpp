// Exercise: Using classes, allocate 26 different objects and assign a to [1], b to [2], etc

#include "stdafx.h"
#include <iostream>

using namespace std;

const int Letters = 26;

class Exercise
{
private:
	char name;

public:
	void SetName(char name) { this->name = name; }
	void DisplayName() const { cout << name << " "; }
};

int main()
{
	Exercise * p = new Exercise[Letters]();

	for (char i = 'a'; i < 'z'; i++)
	{
		p[i].SetName(i);
		p[i].DisplayName();
	}
	
	cout << endl << endl;

	delete p;
}
