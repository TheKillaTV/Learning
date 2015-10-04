#pragma once

#ifndef KIKBOT_H
#define KIKBOT_H

#include <Windows.h>
#include <iostream>
#include <string>

class KikBot
{
public:
	KikBot();
	~KikBot();
	HWND CheckifWindowIsOpen();
	void TypeoutMessage(std::string Message, unsigned int Delay);
	void SendMessageToChat();
	void DoubleNewLine();
	HWND GetWindowHandle() const;
	HWND SetWindowHandle();
	void SwitchToBlueStacks(HWND Bluestacks);
	std::string GetMessageCountString() const;
	std::string GetMessageString() const;
	std::string KikBot::GetDateString() const;
	std::string ConvertNumberToString(unsigned int MessageCount);
	std::string GetMessageCountInfo() const;
	std::string GetAuthorString() const;
	unsigned int GetMessageCount() const;
	unsigned int GetMessageDelay() const;
	void SetMessageString(std::string m_Message);
	void SetMessageCount(unsigned int m_Count);
	void SetDelay(unsigned int Delay);

private:
	HWND Window;
	std::string MessageCountString;
	std::string MessageCountInfo;
	std::string MessageCountFinal;
	LPCSTR WindowName;
	std::string MessageToSend;
	std::string Sweats;
	std::string Date;
	bool IsSpecialLetter(const char Letter);
	void ConvertStrings(std::string & DayOfWeek, std::string & Month, std::string & Minute);
	unsigned int Delay;
	unsigned int MessageCount;
	std::string CreateDate();

};

#endif

