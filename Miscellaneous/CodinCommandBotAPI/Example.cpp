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
