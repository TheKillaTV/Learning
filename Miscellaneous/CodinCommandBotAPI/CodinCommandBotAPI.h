#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstring>
#include <sqlite3.h>
#include <ctime>

#define WIN32_LEAN_AND_MEAN

#ifndef CODINBOT_H
#define CODINBOT_H

class CodinBot
{
public:
	CodinBot();
	~CodinBot();
	void TypeMessageToChat(const std::string & Message, const unsigned int Delay) const;
	void CopyStringToClipboard(const std::string & Message) const;
	void BotSleep(const unsigned int Delay) const;
	bool SearchForBlueStacks();
	void MaximizeBlueStacks() const;
	void SendMessageToChat();
	std::string GetLatestMessage();
	std::string GrabStringFromClipboard();
	std::string GetCurrentDate();

private:
	bool IsSpecialLetter(const char Letter) const;
	void ADBpull() const;
	unsigned int Delay;
	bool IsUsingBluestacks;
	bool IsCodinBotsMessage;
	std::string Message;
	std::string ClipboardText;
	std::vector<std::string> CommandsList;
	DWORD ProcessID;
	sqlite3 * db; // For database handling
	sqlite3_stmt * statement;

};

#endif

