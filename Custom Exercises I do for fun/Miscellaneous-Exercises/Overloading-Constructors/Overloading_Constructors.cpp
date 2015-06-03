#include "stdafx.h"
#include <iostream>
#include "Tutorial.h"
#include <string>
#include <sstream>

Tutorial::Tutorial()
{
	m_name = "Contructor0";
	m_var = rand() % 10 + 1;
	m_var2 = rand() % 20 + 10.0;
	m_var3 = rand() % 30 + 20.0;

}

Tutorial::Tutorial(string name)
{
	m_name = name;
	m_var = rand() % 10 + 1;
	m_var2 = rand() % 20 + 10.0;
	m_var3 = rand() % 30 + 20.0;
}

Tutorial::Tutorial(string name, int var)
{
	m_name = name;
	m_var = var;
	m_var2 = rand() % 20 + 10.0;
	m_var3 = rand() % 30 + 20.0;
}

Tutorial::Tutorial(string name, int var, double var2)
{
	m_name = name;
	m_var = var;
	m_var2 = var2;
	m_var3 = rand() % 30 + 20.0;
}

Tutorial::Tutorial(string name, int var, double var2, float var3)
{
	m_name = name;
	m_var = var;
	m_var2 = var2;
	m_var3 = var3;
}

Tutorial::~Tutorial()
{
	cout << "Destructor called!" << endl;
}

string Tutorial::toString()
{
	stringstream ss;

	ss << "Name: " << m_name << endl;
	ss << "Int value: " << m_var << endl;
	ss << "Double value: " << m_var2 << endl;
	ss << "Float value: " << m_var3 << endl;

	return ss.str();
}
