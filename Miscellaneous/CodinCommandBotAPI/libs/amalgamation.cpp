#include "amalgamation.h"

#ifdef _WIN32
CodinBotGUI::CodinBotGUI(HINSTANCE hInstance, int nCmdShow) : m_hInstance(hInstance), m_nCmdShow(nCmdShow), m_Window(NULL), m_Error(0)
{
	AllocateConsole("Codin bot debug");
}

CodinBotGUI::~CodinBotGUI()
{
	UnregisterClass(m_ClassName.c_str(), m_hInstance);
}
void CodinBotGUI::FillWNDCLASSEX()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInstance;
	wcex.hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = m_WindowName.c_str();
	wcex.lpszClassName = m_ClassName.c_str();
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	RegisterClassEx(&wcex);
}

void CodinBotGUI::CreateCodinBotWindow(const std::string & WindowName, int x, int y)
{
	if (!m_Window)
	{
		FillWNDCLASSEX();
		m_Window = CreateWindow(m_ClassName.c_str(), WindowName.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, x, y, NULL, NULL, m_hInstance, NULL);

		if (!m_Window)
		{
			ShowMessageBox_Error("Failed to create Codinbot Window!");
			UnregisterClass(m_ClassName.c_str(), m_hInstance);
			return;
		}

		ShowWindow(m_Window, m_nCmdShow);
		UpdateWindow(m_Window);
	}

	else
	{
		std::cout << "Call to void CodinBotGUI::CreateCodinBotWindow failed because a window already exists!" << std::endl;
		return;
	}
}

void CodinBotGUI::CreateCodinBotWindow(const std::string & WindowName)
{
	if (!m_Window)
	{
		FillWNDCLASSEX();
		m_Window = CreateWindow(m_ClassName.c_str(), WindowName.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, m_hInstance, NULL);

		if (!m_Window)
		{
			ShowMessageBox_Error("Failed to create Codinbot Window!");
			UnregisterClass(m_ClassName.c_str(), m_hInstance);
			return;
		}

		ShowWindow(m_Window, m_nCmdShow);
		UpdateWindow(m_Window);
	}

	else
	{
		std::cout << "Call to void CodinBotGUI::CreateCodinBotWindow failed because a window already exists!" << std::endl;
		return;
	}
}

void CodinBotGUI::AllocateConsole(const std::string & ConsoleName)
{
	if (!AllocConsole())
	{
		m_Error = GetLastError();
		ShowMessageBox_Error("Call to AllocConsole() failed! Error code: " + std::to_string(m_Error));
		return;
	}

	SetConsoleTitle(ConsoleName.c_str());
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
}

WPARAM CodinBotGUI::Run()
{
	while (GetMessage(&m_msg, 0, 0, 0))
	{
		TranslateMessage(&m_msg);
		DispatchMessage(&m_msg);
	}

	return m_msg.wParam;
}

void CodinBotGUI::ShowMessageBox_Error(const std::string & Text) const
{
	MessageBox(NULL, Text.c_str(), NULL, MB_OK | MB_ICONERROR);
}

void CodinBotGUI::ShowMessageBox_Error(HWND hWnd, const std::string & Text) const
{
	MessageBox(hWnd, Text.c_str(), NULL, MB_OK | MB_ICONERROR);
}

void CodinBotGUI::ShowMessageBox_Warning(HWND hWnd, const std::string & Text) const
{
	MessageBox(hWnd, Text.c_str(), "Warning", MB_OK | MB_ICONWARNING);
}

void CodinBotGUI::ShowMessageBox_Warning(const std::string & Text) const
{
	MessageBox(NULL, Text.c_str(), "Warning", MB_OK | MB_ICONWARNING);
}

HWND CodinBotGUI::Createbutton(int x, int y, int nWidth, int nHeight) const
{
	return CreateWindow("BUTTON", "", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, x, y, nWidth, nHeight, m_Window, NULL, (HINSTANCE)GetWindowLongPtr(m_Window, GWLP_HINSTANCE), NULL);
}

#endif

#ifdef _WIN32
Keyboard::Keyboard()
{
}


Keyboard::~Keyboard()
{

}

void Keyboard::Type_Message_v1(const std::string & Message, const unsigned int Delay) const
{
	for (int i = 0; i < Message.length(); i++)
	{
		if (IsSpecialLetter(Message.at(i)))
		{
			keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, MAPVK_VK_TO_VSC), NULL, NULL);
			keybd_event(VkKeyScan(Message[i]), MapVirtualKey(VkKeyScan(Message[i]), MAPVK_VK_TO_VSC), NULL, NULL);
			keybd_event(VkKeyScan(Message[i]), MapVirtualKey(VkKeyScan(Message[i]), MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
			keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
		}

		else
		{
			keybd_event(VkKeyScan(Message[i]), MapVirtualKey(VkKeyScan(Message[i]), MAPVK_VK_TO_VSC), NULL, NULL);
			keybd_event(VkKeyScan(Message[i]), MapVirtualKey(VkKeyScan(Message[i]), MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
		}

		Sleep(Delay);
	}

}

void Keyboard::Simulate_Left_Click() const
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
}

void Keyboard::Simulate_Right_Click() const
{
	mouse_event(MOUSEEVENTF_RIGHTDOWN, NULL, NULL, NULL, NULL);
	mouse_event(MOUSEEVENTF_RIGHTUP, NULL, NULL, NULL, NULL);
}

void Keyboard::Simulate_Enter_Key() const
{
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
}

void Keyboard::Move_Cursor(int x, int y) const
{
	mouse_event(MOUSEEVENTF_ABSOLUTE, x, y, NULL, NULL);
}

void Keyboard::Simulate_Ctrl_V() const
{
	keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_V, MapVirtualKey(VK_V, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_V, MapVirtualKey(VK_V, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
}

bool Keyboard::IsSpecialLetter(const char Letter) const
{
	const std::string SpecialCharacters = "QWERTYUIOP{}ASDFGHJKL:ZXCVBNM<>?!@#$%^&*()_+~";

	for (int i = 0; i < SpecialCharacters.length(); i++)
	{
		if (Letter == SpecialCharacters.at(i))
		{
			return true;
		}
	}

	return false;
}
#endif

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

Sqlite3CPP::Sqlite3CPP() : m_ErrorCode(0)
{

}


Sqlite3CPP::~Sqlite3CPP()
{
	sqlite3_finalize(m_statement);
	sqlite3_close(m_db);
}

bool Sqlite3CPP::Open(const std::string & Filename)
{
	if (sqlite3_open(Filename.c_str(), &m_db) == SQLITE_OK)
	{
		return true;
	}

	else
	{
		m_ErrorMessage = sqlite3_errmsg(m_db);
		m_ErrorCode = sqlite3_errcode(m_db);
		sqlite3_close(m_db);
		return false;
	}
}

void Sqlite3CPP::PrintLastError() const
{
	std::cout << "Sqlite3 Error Code: " << m_ErrorCode << std::endl;
	std::cout << "Sqlite3 Error Message: " << m_ErrorMessage << std::endl;
}

bool Sqlite3CPP::Query(const std::string & Query)
{
	if (sqlite3_prepare_v2(m_db, Query.c_str(), -1, &m_statement, NULL) == SQLITE_OK)
	{
		return true;
	}

	else
	{
		m_ErrorMessage = sqlite3_errmsg(m_db);
		m_ErrorCode = sqlite3_errcode(m_db);
	}

	return false;
}

bool Sqlite3CPP::Step()
{
	if (sqlite3_step(m_statement) == SQLITE_ROW)
	{
		return true;
	}

	else
	{
		m_ErrorMessage = sqlite3_errmsg(m_db);
		m_ErrorCode = sqlite3_errcode(m_db);
	}

	return false;
}

// standard kik. May have to edit this function for a modded kik
// x = 18 for message body.
// x = 16 for isuser
std::string Sqlite3CPP::GetColumnText(int x) const
{
	// An extremly hackish way to get the first column. Will improve this.
	return (const char*)(sqlite3_column_text(m_statement, (sqlite3_column_count(m_statement) - sqlite3_column_count(m_statement)) + x));
}
