#include "KikBot.h"

int main()
{ 
	KikBot Codin;

	/*
	*		--------- Default values are used if not set --------- 
	*
	* 		Codin.SetDelay(1); // Delay between each simulated keystroke in miliseconds. This has to be at least 1 milisecond.
	*
	*		Codin.SetMessageString(""); // The message that the program will type out
	*
	*		Codin.SetMessageCount(1); // The message count that the program will type out at the end. This increments by 1 after a message is sent.
	*/

	while (!Codin.CheckifWindowIsOpen())
	{
		system("CLS");
		std::cout << "Looking for BlueStacks App Player . . .";
		Sleep(1000);
	}

	Codin.SetWindowHandle();

	std::cout << "BlueStacks found. Open a Kik chat and make sure the bot can type. Enter 1 on the NumPad to exit at any time." << std::endl;
	std::cout << "Bot starting in: " << std::endl;

	for (int i = 10; i > 0; i--)
	{
		std::cout << i << ". . ." << std::endl;
		Sleep(1000);
	}

	unsigned int MessageCount = Codin.GetMessageCount();
	Codin.SwitchToBlueStacks(Codin.GetWindowHandle());

	while (true)
	{
		if (!Codin.CheckifWindowIsOpen())
			break;

		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
			break;

		Codin.TypeoutMessage(Codin.GetMessageString(), Codin.GetMessageDelay());
		Codin.DoubleNewLine();
		std::string MessageCountString = Codin.GetMessageCountInfo() + Codin.ConvertNumberToString(MessageCount);
		Codin.TypeoutMessage(MessageCountString, Codin.GetMessageDelay());
		Codin.DoubleNewLine();
		Codin.TypeoutMessage(Codin.GetDateString(), Codin.GetMessageDelay());
		Codin.DoubleNewLine();
		Codin.TypeoutMessage(Codin.GetAuthorString(), Codin.GetMessageDelay());
		Codin.SendMessageToChat();
		MessageCount++;
		
	}
}
