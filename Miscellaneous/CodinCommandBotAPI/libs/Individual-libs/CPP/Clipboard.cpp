#include "Clipboard.h"

#ifdef _WIN32

Clipboard::Clipboard() : m_IsOpen(false), m_Owner(NULL), m_Clipboard(INVALID_HANDLE_VALUE), m_ClipboardText("Constructor")
{

}

Clipboard::Clipboard(HWND Owner) : m_IsOpen(false), m_Owner(Owner), m_Clipboard(INVALID_HANDLE_VALUE), m_ClipboardText("Constructor")
{

}


Clipboard::~Clipboard()
{
	if (m_IsOpen)
	{
		m_IsOpen = false;
		CloseClipboard();
	}

}

bool Clipboard::Open()
{
	if (OpenClipboard(m_Owner))
	{
		m_IsOpen = true;
		return true;
	}

	else
	{
		m_ErrorCode = GetLastError();
		return false;
	}
}

std::string Clipboard::GetText()
{
	if (m_IsOpen)
	{
		m_Clipboard = GetClipboardData(CF_TEXT);

		const char * ClipText = (const char*)m_Clipboard;

		if (ClipText)
		{
			m_ClipboardText = ClipText;
		}

		else
		{
			std::cout << "Clipboard is empty!" << std::endl;
		}
	}

	else
	{
		std::cout << "Function std::string Clipboard::GetText() failed. Reason: Clipboard isn't open " << std::endl;
	}

	return m_ClipboardText;
}

void Clipboard::SetText(const std::string & ClipboardText)
{
	if (m_IsOpen)
	{
		HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, ClipboardText.length() + 1);

		if (!hg)
		{
			m_ErrorCode = GetLastError();
			return;
		}

		memcpy(GlobalLock(hg), ClipboardText.c_str(), ClipboardText.length() + 1);
		GlobalUnlock(hg);
		SetClipboardData(CF_TEXT, hg);
		GlobalFree(hg);
	}

	else
	{
		std::cout << "Function void Clipboard::SetText(const std::string & ClipboardText) failed. Reason: Clipboard isn't open." << std::endl;
	}
}

void Clipboard::PrintLastError() const
{
	std::cout << "GetLastError() returned: " << m_ErrorCode << std::endl;
	std::cout << "For more information, search GetLastError() on MSDN" << std::endl;
}

#endif
