// temp file. Only putting this here so i can test it by itself if needed.

#include "stdafx.h"
#include <iostream>
#include "RockPaperSissors.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	RockPaperSissors * Test = new RockPaperSissors();

	while (true)
	{
		Test->Set_P_Choice(Test->Get_P_Choice());
		Test->Set_C_Choice(Test->Get_C_Choice());
		Test->DetermineWinner();
		Test->DisplayStats();

		if (!Test->GetQuit())
			break;
	}

	delete Test;

}
