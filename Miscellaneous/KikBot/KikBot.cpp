#include "KikBot.h"

KikBot::KikBot()
{
	MessageToSend = "[Automated Message] : Hello, and welcome to Coding! Due to unforseen circumstances, this group is no longer active :-[ . Please join #codin instead. After joining the group, please leave this group so I can forward new-comers to #codin. Thanks! Note: This message is repeated often so you may want to leave anyway : -] . ";
	WindowName = "BlueStacks App Player";
	Window = NULL;
	Sweats = "Bot created by Sweats.";
	MessageCountInfo = "[Message Count] : ";
	MessageCount = 1;
	MessageCountFinal = MessageCountInfo + MessageCountString;
	Date = CreateDate();
}

KikBot::~KikBot()
{

}

HWND KikBot::CheckifWindowIsOpen()
{
	HWND BlueStacksWindow = FindWindow(NULL, WindowName);

	if (!BlueStacksWindow)
	{
		return FALSE;
	}

	else
	{
		return BlueStacksWindow;
	}
}

void KikBot::TypeoutMessage(std::string Message, unsigned int Delay)
{
	if (Delay <= 0)
		Delay = 1;

	for (int i = 0; i < Message.length(); i++)
	{
		if (IsSpecialLetter(Message[i]))
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

void KikBot::SendMessageToChat()
{
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
}

void KikBot::DoubleNewLine()
{
	keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_RETURN, MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);

}
	
bool KikBot::IsSpecialLetter(const char Letter)
{
	const char ImportantLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+{}:<>?~";

	for (int i = 0; i < sizeof(ImportantLetters) - 1; i++)
	{
		if (Letter == ImportantLetters[i])
		{
			return true;
		}
	}

	return false;
}


std::string KikBot::ConvertNumberToString(unsigned int MessageCount)
{
	if (MessageCount < 1000)
	{
		MessageCountString = std::to_string(MessageCount);
	}

	else if (MessageCount >= 1000 && MessageCount <= 9999)
	{
		MessageCountString = std::to_string(MessageCount);
		MessageCountString.insert(1, ",");
	}

	else if (MessageCount >= 10000 && MessageCount <= 99999)
	{
		MessageCountString = std::to_string(MessageCount);
		MessageCountString.insert(2, ",");
	}

	else if (MessageCount >= 100000 && MessageCount <= 999999)
	{
		MessageCountString = std::to_string(MessageCount);
		MessageCountString.insert(3, ",");
	}

	return MessageCountString;
}

std::string KikBot::CreateDate()
{
	SYSTEMTIME Info;
	GetLocalTime(&Info);
	std::string Suffix;

	Info.wHour = 23;

	if (Info.wHour > 12)
	{
		Info.wHour -= 12;
		Suffix = "P.M. EST";
	}

	else if (Info.wHour == 12)
	{
		Suffix = "P.M. EST";
	}

	else
	{
		Suffix = "A.M. EST";
	}

	std::string Day = std::to_string(Info.wDayOfWeek);
	std::string Month = std::to_string(Info.wMonth);
	std::string DayNumber = std::to_string(Info.wDay);
	std::string Hour = std::to_string(Info.wHour);
	std::string Year = std::to_string(Info.wYear);
	std::string Minute = std::to_string(Info.wMinute);
	std::string Second = std::to_string(Info.wSecond);

	ConvertStrings(Day, Month, Minute);

	return "[Bot last Started] : " + Day + ", " + Month + " " + DayNumber + ", " + Year + " at " + Hour + ":" + Minute + " " + Suffix + ".";
}

void KikBot::ConvertStrings(std::string & DayOfWeek, std::string & Month, std::string & Minute)
{
	if (DayOfWeek == "0")
		DayOfWeek = "Sunday";
	else if (DayOfWeek == "1")
		DayOfWeek = "Monday";
	else if (DayOfWeek == "2")
		DayOfWeek = "Tuesday";
	else if (DayOfWeek == "3")
		DayOfWeek = "Wednesday";
	else if (DayOfWeek == "4")
		DayOfWeek = "Thursday";
	else if (DayOfWeek == "5")
		DayOfWeek = "Friday";
	else if (DayOfWeek == "6")
		DayOfWeek = "Saturday";

	if (Month == "1")
		Month = "January";
	else if (Month == "2")
		Month = "Feburary";
	else if (Month == "3")
		Month = "March";
	else if (Month == "4")
		Month = "April";
	else if (Month == "5")
		Month = "May";
	else if (Month == "6")
		Month = "June";
	else if (Month == "7")
		Month = "July";
	else if (Month == "8")
		Month = "August";
	else if (Month == "9")
		Month = "September";
	else if (Month == "10")
		Month = "October";
	else if (Month == "11")
		Month = "November";
	else if (Month == "12")
		Month = "December";

	if (Minute == "1")
		Minute = "0" + Minute;
	else if (Minute == "2")
		Minute = "0" + Minute;
	else if (Minute == "3")
		Minute = "0" + Minute;
	else if (Minute == "4")
		Minute = "0" + Minute;
	else if (Minute == "5")
		Minute = "0" + Minute;
	else if (Minute == "6")
		Minute = "0" + Minute;
	else if (Minute == "7")
		Minute = "0" + Minute;
	else if (Minute == "8")
		Minute = "0" + Minute;
	else if (Minute == "9")
		Minute = "0" + Minute;
}

void KikBot::SwitchToBlueStacks(HWND BlueStacks)
{ 
	SwitchToThisWindow(BlueStacks, TRUE);
}

HWND KikBot::GetWindowHandle() const
{
	return Window;
}

std::string KikBot::GetMessageCountString() const
{
	return MessageCountFinal;
}

std::string KikBot::GetMessageString() const
{
	return MessageToSend;
}
std::string KikBot::GetDateString() const
{
	return Date;
}

std::string KikBot::GetMessageCountInfo() const
{
	return MessageCountInfo;
}

std::string KikBot::GetAuthorString() const
{
	return Sweats;
}

unsigned int KikBot::GetMessageCount() const
{
	return MessageCount;
}

unsigned int KikBot::GetMessageDelay() const
{
	return Delay;
}

void KikBot::SetMessageString(std::string m_Message)
{
	MessageToSend = m_Message;
}

void KikBot::SetMessageCount(unsigned int m_Count)
{
	MessageCount = m_Count;
}

void KikBot::SetDelay(unsigned int m_Delay)
{
	Delay = m_Delay;
}

HWND KikBot::SetWindowHandle()
{
	return this->Window = FindWindow(NULL, WindowName);
}
