#pragma once

#include "Global.h"

#ifndef CODINBOTGUI_H
#define CODINBOTGUI_H

#ifdef _WIN32

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class CodinBotGUI
{
public:
	CodinBotGUI(HINSTANCE hInstance, int nCmdSHow);
	~CodinBotGUI();
	void CreateCodinBotWindow(const std::string & WindowName, int x, int y);
	void CreateCodinBotWindow(const std::string & WindowName);
	WPARAM Run();
	HWND Createbutton(int x, int y, int nWidth, int nHeight) const;
	void AllocateConsole(const std::string & ConsoleName);
	void ShowMessageBox_Error(HWND hWnd, const std::string & Text) const;
	void ShowMessageBox_Error(const std::string & Text) const;
	void ShowMessageBox_Warning(const std::string & Text) const;
	void ShowMessageBox_Warning(HWND hWnd, const std::string & Text) const;

private:
	void FillWNDCLASSEX();
	HINSTANCE m_hInstance;
	const std::string m_WindowName;
	const std::string m_ClassName = "SweatsClass";
	HWND m_Window;
	MSG m_msg;
	int m_nCmdShow;
	DWORD m_Error;
};
#endif
#endif
