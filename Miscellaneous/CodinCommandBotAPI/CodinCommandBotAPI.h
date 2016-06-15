#pragma once

#ifndef CODINBOT_H
#define CODINBOT_H

class CodinBot
{
public:
	CodinBot();
	~CodinBot();
	void TypeMessageToChat(const std::string & Message, const unsigned int Delay) const;
	void CopyStringToClipboard(const std::string & Message) const;
	void BotSleep(const unsigned int Delay) const;
	bool SearchForBlueStacks();
	void SwitchToBluestacks_v1();
	void SendMessageToChat() const;
	void LoadCommandsFromFile(const std::string & FileName);
	void Paste() const;
	std::string GetLatestMessage();
	std::string GrabStringFromClipboard();
	std::string GetCurrentDate() const;
	unsigned int GetLastCodinBotError() const;
	void PrintError(const unsigned int Error);

private:
	bool IsSpecialLetter(const char Letter) const;
	void ADBpull() const;
	unsigned int m_Delay;
	bool m_IsUsingBluestacks;
	bool m_IsCodinBotsMessage;
	std::string m_Message;
	std::string m_ClipboardText;
	std::vector<std::string> m_CommandsList;
	std::vector<std::string> m_CommandsDescription;
	unsigned int m_Error;
	DWORD m_ProcessID;
	HWND m_Bluestacks;

};


#endif

