#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
	string name;
	int age;
	double dValue;

public:
	Test() : name("Sweats"), age(1337), dValue(654.4) { cout << "Constructor created" << endl; }
	Test(const Test & other) : name(other.name), age(other.age), dValue(other.dValue) { cout << "Copy constructor created" << endl; }
	void PrintName() const { cout << "Name: " << name << endl; };
	void PrintAge() const { cout << "Age: " << age << endl; };
	void PrintdValue() const { cout << "dValue: " << dValue << endl; };
};

int main()
{
	Test t1;

	t1.PrintName();
	t1.PrintAge();
	t1.PrintdValue();
	
	cout << endl << endl;

	Test t2(t1);

	t2.PrintName();
	t2.PrintAge();
	t2.PrintdValue();



}
