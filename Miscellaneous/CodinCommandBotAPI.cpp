#include "CodinBot.h"

CodinBot::CodinBot()
{

}


CodinBot::~CodinBot()
{

}

void CodinBot::CopyStringToClipboard(const std::string & Message) const
{
	if (OpenClipboard(NULL))
	{
		HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, Message.length());

		if (!hg)
		{
			return;
		}

		memcpy(GlobalLock(hg), Message.c_str(), Message.length());
		GlobalUnlock(hg);
		SetClipboardData(CF_TEXT, hg);
		CloseClipboard();
		GlobalFree(hg);
	}
}

std::string CodinBot::GrabStringFromClipboard()
{
	if (OpenClipboard(NULL))
	{
		HANDLE Clipboard = GetClipboardData(CF_TEXT);

		const char * Clip = (const char*)Clipboard;

		if (Clip)
		{
			ClipboardText = Clip;
		}
	}

	CloseClipboard();

	return ClipboardText;
}

std::string CodinBot::GetLatestMessage()
{
	ADBpull();
	const std::string kikDatabase = "kikDatabase.db";
	const std::string Query = "SELECT * FROM messagesTable ORDER BY _id DESC LIMIT 1";
	int rc = 0;

	rc = sqlite3_open(kikDatabase.c_str(), &db);

	if (rc)
	{
		return "Failed to open kikDatabase.db!";
	}

	if (sqlite3_prepare_v2(db, Query.c_str(), -1, &statement, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(statement) == SQLITE_ROW)
		{
			const char * msg = (const char*)sqlite3_column_text(statement, sqlite3_column_count(statement) - 18);
			const char * is_bot = (const char*)sqlite3_column_text(statement, sqlite3_column_count(statement) - 16);

			if (msg)
			{
				Message = msg;
			}

			if (*is_bot == '1')
			{
				IsCodinBotsMessage = true;
			}

			else
			{
				IsCodinBotsMessage = false;
			}
		}
	}

	sqlite3_finalize(statement);
	sqlite3_close(db);

	return Message;
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
					ProcessID = pe32.th32ProcessID;
					Found = true;
					IsUsingBluestacks = Found;
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
	}
	
	BotSleep(Delay);
}

void CodinBot::SendMessageToChat()
{
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
}

std::string CodinBot::GetCurrentDate()
{
	std::time_t CurrentTime = std::time(NULL);
	const std::string Date = std::ctime(&CurrentTime);
	return Date;
}

void CodinBot::MaximizeBlueStacks() const
{

	// TO DO: Find window via process ID. May have to use this EnumWindow() function: https://msdn.microsoft.com/en-us/library/windows/desktop/ms633497(v=vs.85).aspx

	if (IsUsingBluestacks)
	{
		std::cout << "This function is not finished" << std::endl;
	}
}

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
