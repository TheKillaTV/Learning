#pragma once

#include "Global.h"

#ifndef KEYBOARD_H
#define KEYBOARD_H

#ifdef _WIN32

class Keyboard
{
public:
	//void Type_Message_v2(const std::string & Message);
	Keyboard();
	~Keyboard();
	void Type_Message_v1(const std::string & Message, const unsigned int Delay) const;
	void Simulate_Left_Click() const;
	void Simulate_Right_Click() const;
	void Simulate_Enter_Key() const;
	void Simulate_Ctrl_V() const;
	void Move_Cursor(int x, int y) const;

private:
	//std::vector<INPUT> Events;
	bool IsSpecialLetter(const char Letter) const;

};
#endif
#endif

