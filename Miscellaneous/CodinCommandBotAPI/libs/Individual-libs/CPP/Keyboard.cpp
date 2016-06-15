#include "Keyboard.h"


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


