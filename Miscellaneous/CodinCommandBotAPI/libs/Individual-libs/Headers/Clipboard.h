#pragma once

// A very simple, easy to use class to manipulate the text on the Windows Clipboard.

#include "Global.h"

#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#ifdef _WIN32

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
#endif

