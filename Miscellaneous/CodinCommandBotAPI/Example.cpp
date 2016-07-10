/*
#include "amalgamation.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdSHow)
{
	CodinBotGUI GUI(hInstance, nCmdSHow);
	GUI.CreateCodinBotWindow("Codin Bot");

	return GUI.Run();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:

		if (MessageBox(hWnd, "Are you sure you want to close Codin Bot?", "Warning", MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
		}

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
}
*/

#include "CodinCommandBotAPI.h"

void BotRoutine(const std::string & Message);

// This is all untested still.

CodinBot Bot;

int main()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_F1))
			break;

		if (Bot.GetLatestMessage() == "!test" && !Bot.IsCodinBotsMessage())
		{
			BotRoutine("This is a test string!");
		}
	}
}

void BotRoutine(const std::string & Message)
{
	Bot.CopyStringToClipboard(Message);
	Bot.BotSleep(500);
	Bot.Paste();
	Bot.SendMessageToChat();
}
