#include <iostream>
#include <string>

std::string EncryptString(std::string UserInput);

int main()
{
	std::string UserInput;
	std::cout << "Enter a string to Encrypt: ";
	std::getline(std::cin, UserInput);

	UserInput = EncryptString(UserInput);

	std::cout << "Encrypted string: " << UserInput << std::endl;
}


std::string EncryptString(std::string UserInput)
{
	const char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < UserInput.length(); i++)
	{
		for (int c = 0; c < sizeof(Alphabet) - 1; c++)
		{
			if (UserInput[i] == Alphabet[c])
			{
				if (Alphabet[c - 3] < Alphabet[0])
				{
					c = sizeof(Alphabet) + c - 1;
				}

				UserInput[i] = Alphabet[c - 3];
			}
		}
	}

	return UserInput;
}
