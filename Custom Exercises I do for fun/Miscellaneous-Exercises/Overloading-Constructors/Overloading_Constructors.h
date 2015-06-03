#pragma once

#include <string>

#ifndef TUTORIAL_H
#define TUTORIAL_H

using namespace std;

class Tutorial
{
public:
	Tutorial();
	Tutorial(string name);
	Tutorial(string name, int var);
	Tutorial(string name, int var, double var2);
	Tutorial(string name, int var, double var2, float var3);
	~Tutorial();
	string toString();

private:
	string m_name;
	int m_var;
	double m_var2;
	float m_var3;


};

#endif
