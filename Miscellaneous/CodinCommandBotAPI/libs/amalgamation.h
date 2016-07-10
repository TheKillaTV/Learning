#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <TlHelp32.h>
#endif

// Note to self: Look up these two macros.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define DEBUG_BOT

#ifdef __linux
#ifndef NULL
#define NULL 0
#endif
#endif

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <fstream>
#include <sqlite3.h>


/*

Not gonna bother with GUI for now.

#ifndef CODINBOTGUI_H
#define CODINBOTGUI_H

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class CodinBotGUI
{
public:
	CodinBotGUI(HINSTANCE hInstance, int nCmdSHow);
	~CodinBotGUI();
	void CreateCodinBotWindow(const std::string & WindowName, int x, int y);
	void CreateCodinBotWindow(const std::string & WindowName);
	WPARAM Run();
	HWND Createbutton(int x, int y, int nWidth, int nHeight) const;
	void AllocateConsole(const std::string & ConsoleName);
	void ShowMessageBox_Error(HWND hWnd, const std::string & Text) const;
	void ShowMessageBox_Error(const std::string & Text) const;
	void ShowMessageBox_Warning(const std::string & Text) const;
	void ShowMessageBox_Warning(HWND hWnd, const std::string & Text) const;

private:
	void FillWNDCLASSEX();
	HINSTANCE m_hInstance;
	const std::string m_WindowName;
	const std::string m_ClassName = "SweatsClass";
	HWND m_Window;
	MSG m_msg;
	int m_nCmdShow;
	DWORD m_Error;
};
#endif
*/


// A small wrapper class for sqlite3 specifically for the kik bot . Will make future kik bot projects easier.

#ifndef SQLITE3CPP_H
#define SQLITE3CPP_H

class Sqlite3CPP
{
public:
	Sqlite3CPP();
	~Sqlite3CPP();
	bool Open(const std::string & Filename);
	bool Query(const std::string & Query);
	bool Step();
	void PrintLastError() const;
	std::string GetColumnText(int x) const;


private:
	bool m_IsOpen;
	sqlite3 * m_db;
	sqlite3_stmt * m_statement;
	std::string m_ErrorMessage;
	int m_ErrorCode;

};

#endif

#ifndef KEYBOARD_H
#define KEYBOARD_H

#define VK_V 0x56

class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void Type_Message_v1(const std::string & Message, const unsigned int Delay) const;
	void Simulate_Left_Click() const;
	void Simulate_Right_Click() const;
	void Simulate_Enter_Key() const;
	void Simulate_Ctrl_V() const;
	void Move_Cursor(int x, int y) const;

private:
	bool IsSpecialLetter(const char Letter) const;

};
#endif

// A very simple, easy to use class to manipulate the text on the Windows Clipboard.

#ifndef CLIPBOARD_H
#define CLIPBOARD_H

class Clipboard
{
public:
	Clipboard(HWND Owner);
	Clipboard();
	~Clipboard();
	bool Open();
	std::string GetText();
	void PrintLastError() const;
	void SetText(const std::string & ClipboardText);

private:
	DWORD m_ErrorCode;
	bool m_IsOpen;
	HANDLE m_Clipboard;
	HWND m_Owner;
	std::string m_ClipboardText;

};

#endif
