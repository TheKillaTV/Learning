#include "WrapperFunctions.h"

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

CodinBot::CodinBot() : m_Error(0)
{
}


CodinBot::~CodinBot()
{

}

#ifdef _WIN32
void CodinBot::CopyStringToClipboard(const std::string & Message) const
{
	Clipboard Clip;

	if (Clip.Open())
	{
		Clip.SetText(Message);
	}

	else
	{
		Clip.PrintLastError();
	}
}

std::string CodinBot::GrabStringFromClipboard()
{
	Clipboard Clip;

	if (Clip.Open())
	{
		m_ClipboardText = Clip.GetText();
	}

	else
	{
		Clip.PrintLastError();
	}

	return m_ClipboardText;
}

void CodinBot::BotSleep(const unsigned int Delay) const
{
	Sleep(Delay);
}

// If you're using bluestacks, this function can be used at the beginning of your program. You can have the program exit automatically if bluestacks isn't running.
bool CodinBot::SearchForBlueStacks()
{
	const std::string Bluestacks = "BlueStacks.exe";
	bool Found = false;

	HANDLE Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Snapshot)
	{
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(Snapshot, &pe32))
		{
			while (Process32Next(Snapshot, &pe32))
			{
				if (!strcmp(pe32.szExeFile, Bluestacks.c_str()))
				{
					m_ProcessID = pe32.th32ProcessID;
					Found = true;
					m_IsUsingBluestacks = Found;
					break;
				}
			}
		}
	}

	CloseHandle(Snapshot);
	return Found;

}

void CodinBot::TypeMessageToChat(const std::string & Message, const unsigned int Delay) const
{
	Keyboard Key;
	Key.Type_Message_v1(Message, Delay);
}

void CodinBot::SendMessageToChat() const
{
	Keyboard Key;
	Key.Simulate_Enter_Key();
}

void CodinBot::SwitchToBluestacks_v1()
{
	m_Bluestacks = FindWindow(NULL, "Bluestacks App Player");

	if (!m_Bluestacks)
	{
		m_Error = 3;
		MessageBox(NULL, "Bluestacks not found!", NULL, MB_OK);
		return;
	}

	SwitchToThisWindow(m_Bluestacks, TRUE);

	// TO DO: Find window via process ID. May have to use this EnumWindow() function: https://msdn.microsoft.com/en-us/library/windows/desktop/ms633497(v=vs.85).aspx
}

void CodinBot::Paste() const
{
	Keyboard Key;
	Key.Simulate_Ctrl_V();
}

#endif

bool CodinBot::IsSpecialLetter(const char Letter) const
{
	const std::string ImportantLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+{}:<>?~";

	for (int i = 0; i < ImportantLetters.length(); i++)
	{
		if (Letter == ImportantLetters.at(i))
		{
			return true;
		}
	}

	return false;
}

// TO DO. Find a better way than using system(). Lazy solution for now.
// You will need to find the kik package name yourself. The database file we need is located in /data/data/<package.name>/databases/kikDatabase.db
void CodinBot::ADBpull() const
{
	const std::string AdbPullCommand = "adb pull /data/data/kik.android/databases/kikDatabase.db";
	system(AdbPullCommand.c_str());
}

void CodinBot::LoadCommandsFromFile(const std::string & FileName)
{
	std::fstream fin;
	std::string Command;

	fin.open(FileName.c_str());

	if (fin.is_open())
	{
		while (std::getline(fin, Command))
		{
			if (Command.at(0) == '#')
			{
				Command.erase(0, 1);
				m_CommandsList.push_back(Command);
			}

			else if (Command.at(0) == '-')
			{
				Command.erase(0, 1);
				m_CommandsDescription.push_back(Command);
			}
		}
	}

	else
	{
		m_Error = 1;
	}

	fin.close();
}

std::string CodinBot::GetLatestMessage()
{
	ADBpull();
	Sqlite3CPP sqlite3;

	if (sqlite3.Open("kikDatabase.db"))
	{
		if (sqlite3.Query("SELECT * FROM messagesTable ORDER BY _id DESC LIMIT 1"))
		{
			if (sqlite3.Step())
			{
				std::string msg = sqlite3.GetColumnText(18);
				std::string isbot = sqlite3.GetColumnText(16);

				if (!msg.empty())
				{
					m_Message = msg;
				}

				if (!isbot.empty() && isbot == "1")
				{
					m_IsCodinBotsMessage = true;
				}
			}
		}
	}

	return m_Message;
}


std::string CodinBot::GetCurrentDate() const
{
	std::time_t CurrentTime = std::time(NULL);
	const std::string Date = std::ctime(&CurrentTime);
	return Date;
}

// 1 = Failed to open .txt file
// 2 = Failed to open Databasefile
// 3 = Failed to find Bluestacks
unsigned int CodinBot::GetLastCodinBotError() const
{
	return m_Error;
}

void CodinBot::PrintError(const unsigned int Error)
{
	switch (Error)
	{
	case 1:
		std::cout << "Failed to open Filename in function: LoadCommandsFromFile(const std::string & Filename)" << std::endl;
		break;
	case 2:
		std::cout << "Failed to open sqlite3 database file in function: std::string GetLatestMessage()" << std::endl;
		break;
	case 3:
		std::cout << "Failed to find Bluestacks in function: void SwitchToBluestacks_v1()" << std::endl;
		break;
	default:
		break;
	}
}

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
