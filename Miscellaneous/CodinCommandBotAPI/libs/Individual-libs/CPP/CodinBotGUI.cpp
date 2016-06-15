#include "CodinBotGUI.h"

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
