#include "CodinBot.h"
#include "Sqlite3CPP.h"
#include "Keyboard.h"
#include "Clipboard.h"
#include "CodinBotGUI.h"

CodinBot::CodinBot(): m_Error(0)
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

