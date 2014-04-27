/* What's the point of this?  None other than to practice. Theres a lot of loops so the user can go back and forth in the program.
*
*    Couple of things to note:
*    1. If it asks you to enter 1, 2, or 3 for an option, don't enter a string or it will loop forever.
*    2. If it asks you to enter a string for an option, don't enter a number or it will loop forever.
*
*   *TO DO:*
*    - Make exit function work correctly (Doesn't work in some areas).
*    - Make code neater.
*    - Improve the spacing between cout statements in program.
*
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* ##########MATH FUNCTIONS########## */

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

double dividedecimal(double w, double z)
{
    return w / z;
}

int squareNum(int x)
{
    return x * x;
}

/* ####CUSTOM FUNCTIONS#### */

int ExitProgram()
{
    cout << "Exiting Program now..." << endl;
    return 0;
}

int numrange(int high, int low)
{
    return rand() % (high - low) + low;
}

void CompGuessNumAgain();
void MathSwitch();
void RandomNumberGame();
void RunningTotalAgain();


// Displays menu options, but needs other functions in order for the program to, "loop".
void DisplayMenuOptions()
{
    int option;
    cout << "Welcome to the most useless program ever. Which option below will you pick?" << endl;
    cout << endl;
    cout << "1. The almighty Calculator" << endl;
    cout << "2. Random number game!" << endl;
    cout << "3. Running total!" << endl;
    cout << "4. Computer guesses your number" << endl;
    cout << "5. Exit the epic program" << endl;
    cin >> option;

    switch(option)
    {
    case 1:
        MathSwitch();
        break;

    case 2:
        RandomNumberGame();
        break;

    case 3:
        RunningTotalAgain();
        break;


    case 4:
        CompGuessNumAgain();
        break;

    case 5:
        ExitProgram();
        break;

    default:

        do
        {
            cout << "Pick one" << endl;
            cin >> option;

            if(option == 1)
            {
                MathSwitch();
            }
            else if(option == 2)
            {
                RandomNumberGame();
            }
            else if(option == 3)
            {
                RunningTotalAgain();
            }
            else if(option == 4)
            {
                CompGuessNumAgain();
            }
            else if(option == 5)
            {
                ExitProgram();
            }
        } while (option >= 6 || option <= 0);

    }
}
// All Calculator stuff goes into this function.

void AddAgain()
{
    int x, y;
    string again, choice;

    cout << "Adding picked again! Pick 2 numbers to add together!" << endl;
    cin >> x;
    cout << "You entered: " << x << ". Enter second number!" << endl;
    cin >> y;
    cout << "You entered: " << y << ". Let the magic happen!" << endl;
    cout << endl;
    cout << x << " + " << y << " = " << add(x, y) << "!" << endl;
    cout << "Want to pick two more numbers? Type in the option." << endl;
    cout << endl;
    cout << "Yes" << endl;
    cout << "No" << endl;
    cout << "Exit" << endl;
    cin >> choice;

    if(choice == "yes")
    {
        AddAgain();
    }
    else if(choice == "no")
    {
        cout << endl;
        cout << "Returned to main menu" << endl;
        cout << endl;
        DisplayMenuOptions();
    }
    else
    {
        do
        {
            cout << endl;
            cout << "Pick one." << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cout << endl;
            cin >> choice;

            if(choice == "yes")
            {
                AddAgain();
            }
            else if(choice == "no")
            {
                cout << endl;
                cout << "Returned to main menu" << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
        } while(choice != "yes" || choice != "no" || choice != "exit");
    }
}

void SubtractAgain()
{
    int x, y;
    string choice;

    cout << "Subtracting picked again! Enter 2 numbers to subtract." << endl;
    cin >> x;
    cout << "You entered: " << x << ". Enter second number" << endl;
    cin >> y;
    cout << "You entered: " << y << ". Let the magic happen!" << endl;
    cout << endl;
    cout << x << " - " << y << " = " << subtract(x, y) << "!" << endl;
    cout << endl;
    cout << "Want to pick two more numbers?" << endl;
    cout << endl;
    cout << "Yes" << endl;
    cout << "No" << endl;
    cout << "Exit" << endl;
    cin >> choice;

    if(choice == "yes")
    {
        SubtractAgain();
    }
    else if(choice == "no")
    {
        cout << endl;
        cout << "Returned to main menu" << endl;
        cout << endl;
        DisplayMenuOptions();
    }
    else if(choice == "exit")
    {
        ExitProgram();
    }
    else
    {
        do
        {
            cout << endl;
            cout << "Pick one" << endl;
            cout << endl;
            cout << "Yes." << endl;
            cout << "No." << endl;
            cout << "Yes." << endl;
            cin >> choice;

            if(choice == "yes")
            {
                SubtractAgain();
            }
            else if(choice == "no")
            {
                cout << endl;
                cout << "Returned to main menu." << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
        } while(choice != "yes" || choice != "no" || choice != "exit");
    }
}

void MultiplyAgain()
{
    int x, y;
    string choice;

    cout << "Multiplication picked again! Enter 2 numbers to multiply." << endl;
    cin >> x;
    cout << "You entered: " << x << ". Enter second number" << endl;
    cin >> y;
    cout << "You entered: " << y << ". Let the magic happen!" << endl;
    cout << endl;
    cout << x << " * " << y << " = " << multiply(x, y) << "!" << endl;
    cout << endl;
    cout << "Want to pick two more numbers?" << endl;
    cout << endl;
    cout << "Yes" << endl;
    cout << "No" << endl;
    cout << "Exit" << endl;
    cin >> choice;

    if(choice == "yes")
    {
        MultiplyAgain();
    }
    else if(choice == "no")
    {
        cout << endl;
        cout << "Returned to main menu" << endl;
        cout << endl;
        DisplayMenuOptions();
    }
    else if(choice == "exit")
    {
        ExitProgram();
    }
    else
    {
        do
        {
            cout << endl;
            cout << "Pick one." << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;

            if(choice == "yes")
            {
                MultiplyAgain();
            }
            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
        } while(choice != "yes" || choice != "no" || choice != "exit");

    }
}

void DivideAgain()
{
    int x, y;
    string choice;

    cout << "Division picked again. Enter 2 numbers to divide" << endl;
    cin >> x;
    cout << "You entered: " << x << ". Enter the second number." << endl;
    cin >> y;
    cout << "You entered: " << y << ". Let the magic happen!" << endl;
    cout << " " << endl;
    cout << x << " ÷ " << y << " = " << divide(x, y) << "!" << endl;
    cout << endl;
    cout << "Want to pick two more numbers?" << endl;
    cout << endl;
    cout << "Yes" << endl;
    cout << "No" << endl;
    cout << "Exit" << endl;
    cin >> choice;

    if(choice == "yes")
    {
        DivideAgain();
    }
    else if(choice == "no")
    {
        cout << "Returned to main menu." << endl;
        DisplayMenuOptions();
    }
    else if(choice == "exit")
    {
        ExitProgram();
    }
    else
    {
        do
        {
            cout << "Pick one" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> choice;

            if(choice == "yes")
            {
                DivideAgain();
            }
            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
        } while (choice != "yes" || choice != "no" || choice != "exit");
    }
}

void DivideDecimalAgain()
{
    string choice;
    double z, w;

    cout << "Division with decimals picked again. Enter two decimals to divide" << endl;
    cin >> w;
    cout << "You entered: " << w << ". Now enter second number" << endl;
    cin >> z;
    cout << "You entered: " << z << ". Now let the magic happen!" << endl;
    cout << " " << endl;
    cout << w << " ÷ " << z << " = " << dividedecimal(w, z) << "!" << endl;
    cout << endl;
    cout << "Want to pick two more numbers?" << endl;
    cout << endl;
    cout << "Yes" << endl;
    cout << "No" << endl;
    cout << "Exit" << endl;
    cin >> choice;

    if(choice == "yes")
    {
        DivideDecimalAgain();
    }
    else if(choice == "no")
    {
        cout << "Returned to main menu." << endl;
        cout << endl;
        DisplayMenuOptions();
    }
    else if(choice == "exit")
    {
        ExitProgram();
    }
    else
    {
        do
        {
            cout << endl;
            cout << "Pick one." << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> choice;

            if(choice == "yes")
            {
                DivideDecimalAgain();
            }
            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                cout << endl;
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
        } while (choice != "yes" || choice != "no" || choice != "exit");
    }
}

void SquareNumAgain()
{
    int x;
    string choice;

    cout << "Square number picked again. Enter a number to square" << endl;
    cin >> x;
    cout << "You entered: " << x << endl;
    cout << "The square of " << x << " = " << squareNum(x) << "!" << endl;
    cout << endl;
    cout << "Want to pick another number?" << endl;
    cout << endl;
    cout << "Yes" << endl;
    cout << "No" << endl;
    cout << "Exit" << endl;
    cin >> choice;

    if(choice == "yes")
    {
        SquareNumAgain();
    }
    else if(choice == "no")
    {
        cout << "Returned to main menu." << endl;
        DisplayMenuOptions();
    }
    else if(choice == "exit")
    {
        ExitProgram();
    }
    else
    {
        do
        {
            cout << endl;
            cout << "Pick one" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> choice;

            if(choice == "yes")
            {
                SquareNumAgain();
            }
            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
        } while(choice != "yes" || choice != "no" || choice != "exit");
    }
}
void MathSwitch()
{
        int option2;
        cout << "Welcome to the epic Calculator! What do you want to do?" << endl;
        cout << "1. Add!" << endl;
        cout << "2. Subtract!" << endl;
        cout << "3. Multiply!" << endl;
        cout << "4. Divide!" << endl;
        cout << "5. Divide Decimals!" << endl;
        cout << "6. Square number!" << endl;
        cin >> option2;

        int x, y;
        string again, choice;
        double w, z; //double is used for floating numbers.


        switch(option2)
        {
            case 1:

                cout << "Adding picked! Pick 2 numbers to add together!" << endl;
                cin >> x;
                cout << "You entered: " << x << ". Enter second number!" << endl;
                cin >> y;
                cout << "You entered: " << y << ". Let the magic happen!" << endl;
                cout << endl;
                cout << x << " + " << y << " = " << add(x, y) << "!" << endl;
                cout << "Want to pick two more numbers? Type in the option." << endl;
                cout << endl;
                cout << "Yes" << endl;
                cout << "No" << endl;
                cout << "Exit" << endl;
                cin >> choice;

                if(choice == "yes")
                {
                    AddAgain();
                }

                else if(choice == "no")
                {
                    cout << endl;
                    cout << "Returned to main menu." << endl;
                    cout << endl;
                    DisplayMenuOptions();
                }
                else if(choice == "exit")
                {
                    ExitProgram();
                }
                else
                {
                    do
                    {
                        cout << "Pick one" << endl;
                        cout << endl;
                        cout << "1. Yes" << endl;
                        cout << "2. No" << endl;
                        cout << "3. Exit" << endl;
                        cin >> choice;

                        if(choice == "yes")
                        {
                            AddAgain();
                        }
                        else if(choice == "no")
                        {
                            cout << endl;
                            cout << "Returned to main menu" << endl;
                            cout << endl;
                            DisplayMenuOptions();
                        }
                        else if(choice == "exit")
                        {
                            ExitProgram();
                        }
                    } while (choice != "yes" || choice != "no" || choice != "exit");
                }
        break;

            case 2:

                cout << "Subtracting picked! Enter 2 numbers to subtract." << endl;
                cin >> x;
                cout << "You entered: " << x << ". Enter second number" << endl;
                cin >> y;
                cout << "You entered: " << y << ". Let the magic happen!" << endl;
                cout << endl;
                cout << x << " - " << y << " = " << subtract(x, y) << "!" << endl;
                cout << endl;
                cout << "Want to pick two more numbers?" << endl;
                cout << endl;
                cout << "Yes" << endl;
                cout << "No" << endl;
                cout << "Exit" << endl;
                cin >> choice;

                if(choice == "yes")
                {
                    SubtractAgain();
                }
                else if(choice == "no")
                {
                    cout << "Returned to main menu." << endl;
                    DisplayMenuOptions();
                }
                else if (choice == "exit")
                {
                    ExitProgram();
                }

                else
                {
                    do
                    {
                        cout << "Pick one" << endl;
                        cout << endl;
                        cout << "Yes" << endl;
                        cout << "No" << endl;
                        cout << "Exit" << endl;
                        cin >> choice;

                        if(choice == "yes")
                        {
                            SubtractAgain();
                        }
                        else if(choice == "no")
                        {
                            cout << endl;
                            cout << "Returned to main menu" << endl;
                            cout << endl;
                            DisplayMenuOptions();
                        }
                        else if(choice == "exit")
                        {
                            ExitProgram();
                        }
                    } while (choice != "yes" || choice != "no" || choice != "exit");
                }
        break;

        case 3:

            cout << "Multiplication picked! Enter 2 numbers to multiply." << endl;
            cin >> x;
            cout << "You entered: " << x << ". Enter second number" << endl;
            cin >> y;
            cout << "You entered: " << y << ". Let the magic happen!" << endl;
            cout << endl;
            cout << x << " * " << y << " = " << multiply(x, y) << "!" << endl;
            cout << endl;
            cout << "Want to pick two more numbers?" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> choice;

            if(choice == "yes")
            {
                MultiplyAgain();
            }
            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }

            else
            {
                do
                {
                    cout << "Pick one" << endl;
                    cout << endl;
                    cout << "Yes" << endl;
                    cout << "No" << endl;
                    cout << "Exit" << endl;
                    cin >> choice;

                    if(choice == "yes")
                    {
                        MultiplyAgain();
                    }
                    else if(choice == "no")
                    {
                        cout << "Returned to main menu." << endl;
                        cout << endl;
                        DisplayMenuOptions();
                    }
                    else if(choice == "exit")
                    {
                        ExitProgram();
                    }
                } while (choice != "yes" || choice != "no" || choice != "exit");
            }

        break;

        case 4:

            cout << "Division picked. Enter 2 numbers to divide" << endl;
            cin >> x;
            cout << "You entered: " << x << ". Enter the second number." << endl;
            cin >> y;
            cout << "You entered: " << y << ". Let the magic happen!" << endl;
            cout << endl;
            cout << x << " ÷ " << y << " = " << divide(x, y) << "!" << endl;
            cout << endl;
            cout << "Want to pick two more numbers?" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> choice;

            if(choice == "yes")
            {
                DivideAgain();
            }
            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
            else
            {
                do
                {
                    cout << "Pick one" << endl;
                    cout << endl;
                    cout << "Yes" << endl;
                    cout << "No" << endl;
                    cout << "Exit" << endl;
                    cin >> choice;

                    if(choice == "yes")
                    {
                        DivideAgain();
                    }
                    else if(choice == "no")
                    {
                        cout << "Returned to main menu" << endl;
                        cout << endl;
                        DisplayMenuOptions();
                    }
                    else if(choice == "exit")
                    {
                        ExitProgram();
                    }
                } while (choice != "yes" || choice != "no" || choice != "exit");
            }
        break;

        case 5:

            cout << "Division with decimals picked. Enter two decimals to divide" << endl;
            cin >> w;
            cout << "You entered: " << w << ". Now enter second number" << endl;
            cin >> z;
            cout << "You entered: " << z << ". Now let the magic happen!" << endl;
            cout << endl;
            cout << w << " ÷ " << z << " = " << dividedecimal(w, z) << "!" << endl;
            cout << endl;
            cout << "Want to pick two more numbers?" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> choice;

            if(choice == "yes")
            {
                DivideDecimalAgain();
            }

            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
            else
            {
                do
                {
                    cout << "Pick one" << endl;
                    cout << endl;
                    cout << "Yes" << endl;
                    cout << "No" << endl;
                    cout << "Exit" << endl;
                    cin >> choice;

                    if(choice == "yes")
                    {
                        DivideDecimalAgain();
                    }
                    else if(choice == "no")
                    {
                        cout << "Returned to main menu." << endl;
                        cout << endl;
                        DisplayMenuOptions();
                    }
                    else if(choice == "exit")
                    {
                        ExitProgram();
                    }

                } while (choice != "yes" || choice != "no" || choice != "exit");
            }
        break;

        case 6:

            cout << "Square number picked. Enter a number to square" << endl;
            cin >> x;
            cout << "You entered: " << x << endl;
            cout << "The square of " << x << " = " << squareNum(x) << "!" << endl;
            cout << endl;
            cout << "Want to pick another number?" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> choice;

            if(choice == "yes")
            {
                SquareNumAgain();
            }
            else if(choice == "no")
            {
                cout << "Returned to main menu." << endl;
                DisplayMenuOptions();
            }
            else if(choice == "exit")
            {
                ExitProgram();
            }
            else
            {
                do
                {
                    cout << "Pick one." << endl;
                    cout << endl;
                    cout << "Yes" << endl;
                    cout << "No" << endl;
                    cout << "Exit" << endl;
                    cin >> choice;

                    if(choice == "yes")
                    {
                        SquareNumAgain();
                    }
                    else if(choice == "no")
                    {
                        cout << "Returned to main menu." << endl;
                        cout << endl;
                    }
                    else if(choice == "exit")
                    {
                        ExitProgram();
                    }
                } while (choice != "yes" || choice != "no" || choice != "exit");
            }
            break;

        default:

                do
                {
                    cout << "Pick one of the options" << endl;
                    cin >> option2;
                } while (option2 > 6 || option2 < 1);

        break;
    }

}

void CompGuessNumAgain()
{
    int choice2;
    int yournum, compnum, compnumtries = 0, one, yournum2;

    cout << "Computer will guess your new number. It has unlimited tries. Enter any number between 0 and 1000" << endl;
    cin >> yournum2;

    if(yournum2 >= 0 && yournum2 <= 1000)
    {
        cout << "Your new number is " << yournum2 << ". Enter 1 to have the computer guess your new number or enter 2 to exit. If neither are selected, then this will start over." << endl;
        cin >> one;

        if(one == 1)
        {
            for(int i = 0; ; i++) // Computer has unlimited tries to get your number.
            {
                compnumtries = compnumtries + 1;
                int compnum = numrange(1000, 1);

                if(compnum == yournum2)
                {
                    cout << "Computer guessed your new number which is: " << yournum2 << endl;
                    cout << endl;
                    cout << "It took the computer " << compnumtries << " tries to guess your number" << endl;
                    cout << "Again?" << endl;
                    cout << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No" << endl;
                    cout << "3. Exit" << endl;
                    cin >> choice2;

                    if(choice2 == 1)
                    {
                        int yournum2;
                        CompGuessNumAgain();
                    }
                    else if(choice2 == 2)
                    {
                        cout << "Returned to main menu." << endl;
                        cout << endl;
                        DisplayMenuOptions();
                    }
                    else if (choice2 == 3)
                    {
                        ExitProgram();
                    }
                    else
                    {
                        while (choice2 != 1 || choice2 != 2 || choice2 != 3)
                        {
                            int choice2;
                            cout << endl;
                            cout << "Pick one" << endl;
                            cout << endl;
                            cout << "1. Yes" << endl;
                            cout << "2. No" << endl;
                            cout << "3. Exit" << endl;
                            cin >> choice2;

                            if(choice2 == 1)
                            {
                                int yournum2;
                                CompGuessNumAgain();
                            }
                            else if(choice2 == 2)
                            {
                                cout << "Returned to main menu" << endl;
                                cout << endl;
                                DisplayMenuOptions();
                            }
                            else if(choice2 == 3)
                            {
                                ExitProgram();
                            }
                        }

                    }
                }
                else if(compnum != yournum2)
                {
                    cout << "Computer guessed: " << compnum << "." << endl;
                    cout << endl;
                    cout << "Computer used " << compnumtries << " tries so far." << endl;
                    cout << endl;
                }
            }
        }
        else if(one == 2)
        {
            cout << "Returned to main menu." << endl;
            cout << endl;
            DisplayMenuOptions();
        }
        else
        {
            do
            {
                cout << "Enter 1 or 2" << endl;
                cout << endl;
                cin >> one;

                if(one == 1)
                {
                    cout << "Restarting..." << endl;
                    CompGuessNumAgain();
                }
                else if(one == 2)
                {
                    ExitProgram();
                }
            } while (one != 1 && one != 2);
        }
    }
    else
    {
        do
        {   cout << endl;
            cout << "Restarting because you didn't follow the directions" << endl;
            cout << endl;
            CompGuessNumAgain();
        } while (yournum2 > 1000 || yournum2 < 0);
    }
}

void RandomNumberGame()
{
    int num, cnum = numrange(11, 1), tries = 0;
    string again;

    cout << "Random number game selected again. Guess the new number that's between 1 and 10" << endl;
    cin >> num;

    for(int i = 0; ; i++)
    {
        tries = tries + 1;

        if(num == cnum)
        {
            cout << "Congratulations! You guessed the new correct number with " << tries << " tries!" << endl;
            cout << endl;
            cout << "Again?" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> again;

            if(again == "yes")
            {
                RandomNumberGame();
            }
            else if(again == "no")
            {
                cout << "Returned to main menu" << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(again == "exit")
            {
                ExitProgram();
            }
            else
            {
                do
                {
                    cout << "Pick one." << endl;
                    cout << endl;
                    cout << "Yes" << endl;
                    cout << "No" << endl;
                    cout << "Exit" << endl;
                    cin >> again;

                    if(again == "yes")
                    {
                        RandomNumberGame();
                    }
                    else if(again == "no")
                    {
                        cout << "Returned to main menu" << endl;
                        cout << endl;
                        DisplayMenuOptions();
                    }
                    else if(again == "exit")
                    {
                        ExitProgram();
                    }
                } while(again != "yes" || again != "no" || again != "exit");
            }
        }
        else if(num > cnum)
        {
            cout << "Guess lower!" << endl;
            cin >> num;
            cout << endl;
        }
        else if (num < cnum)
        {
            cout << "Guess higher!" << endl;
            cin >> num;
            cout << endl;
        }
    }
}

void RunningTotalAgain()
{
    int x, total = 0;
    string again;

    cout << "Running total game selected again. Enter a new number to start adding up." << endl;

    for(int i = 0; ; i++)
    {
        cout << "Enter another number to continue the adding." << endl;
        cin >> x;
        cout << endl;
        total = total + x;
        cout << "Your total so far is: " << total << "." << endl;

        if(total >= 1000)
        {
            cout << "Limit reached!" << endl;
            cout << endl;
            cout << "Again?" << endl;
            cout << endl;
            cout << "Yes" << endl;
            cout << "No" << endl;
            cout << "Exit" << endl;
            cin >> again;

            if(again == "yes")
            {
                RunningTotalAgain();
            }
            else if(again == "no")
            {
                cout << "Returned to main menu" << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else if(again == "exit")
            {
                ExitProgram();
            }
            else
            {
                do
                {
                    cout << "Pick one." << endl;
                    cout << endl;
                    cout << "Yes" << endl;
                    cout << "No" << endl;
                    cout << "Exit" << endl;
                    cin >> again;

                    if(again == "yes")
                    {
                        RunningTotalAgain();
                    }
                    else if(again == "no")
                    {
                        cout << "Returned to main menu" << endl;
                        cout << endl;
                        DisplayMenuOptions();
                    }
                    else if(again == "exit")
                    {
                        ExitProgram();
                    }

                } while (again != "yes" || again != "no" || again != "exit");
            }
        }
    }
}

int main()
{
    srand( time ( NULL ) );

    int option;
    cout << "Welcome to the most useless program ever. Which option below will you pick?" << endl;
    cout << endl;
    cout << "1. The almighty Calculator" << endl;
    cout << "2. Random number game!" << endl;
    cout << "3. Running total!" << endl;
    cout << "4. Computer guesses your number" << endl;
    cout << "5. Exit the epic program" << endl;
    cin >> option;

/* INITIALIZERS TO USE WITH SWITCH STATEMENTS */
    string again, going, menu;
    int choice;
    int x, y, num, tries = 0, runningtotal, total = 0, total2, numsentered = 2, cnum = numrange(11, 1), yournum, compnum, compnumtries = 0, one;
    double w, z;

    switch(option)
    {
    case 1:
        MathSwitch();
        break;

    case 2: // Random Number Game

        cout << "Random number game selected. Guess the number." << endl;
        cin >> num;
        cout << endl;

        for(int i = 0; ; i++)
        {
            tries = tries + 1;

            if(num == cnum)
            {
                cout << "Congratulations! You guessed the correct number with " << tries << " tries!" << endl;
                cout << endl;
                cout << "Again?" << endl;
                cout << endl;
                cout << "Yes" << endl;
                cout << "No" << endl;
                cout << "Exit" << endl;
                cin >> again;

                if(again == "yes")
                {
                    RandomNumberGame();
                }
                else if(again == "no")
                {
                    cout << "Returned to main menu" << endl;
                    cout << endl;
                    DisplayMenuOptions();
                }
                else if(again == "exit")
                {
                    ExitProgram();
                }
                else
                {
                    do
                    {
                        cout << "Pick one." << endl;
                        cout << endl;
                        cout << "Yes" << endl;
                        cout << "No" << endl;
                        cout << "Exit" << endl;
                        cout << endl;
                        cin >> again;

                        if(again == "yes")
                        {
                            RandomNumberGame();
                        }
                        else if(again == "no")
                        {
                            cout << "Returned to main menu" << endl;
                            cout << endl;
                            DisplayMenuOptions();
                        }
                        else if(again == "exit")
                        {
                            ExitProgram();
                        }
                    } while(again != "yes" || again != "no" || again != "exit");
                }
            }
            else if(num > cnum)
            {
                cout << "Guess lower!" << endl;
                cin >> num;
                cout << endl;
            }
            else if (num < cnum)
            {
                cout << "Guess higher!" << endl;
                cin >> num;
                cout << endl;
            }
        }
  break;

    case 3: // Running total.
            cout << "Welcome to the running total game." << endl;
            cout << endl;

            for(int i = 0; ; i++)
            {
                cout << "Enter a new number to continue the adding." << endl;
                cin >> x;
                cout << endl;
                total = total + x;
                cout << "Your total so far is: " << total << "." << endl;

                if(total >= 1000)
                {
                    cout << "Limit reached!" << endl;
                    cout << endl;
                    cout << "Again?" << endl;
                    cout << endl;
                    cout << "Yes" << endl;
                    cout << "No" << endl;
                    cout << "Exit" << endl;
                    cin >> again;

                    if(again == "yes")
                    {
                        RunningTotalAgain();
                    }
                    else if(again == "no")
                    {
                        cout << "Returned to main menu" << endl;
                        cout << endl;
                        DisplayMenuOptions();
                    }
                    else if(again == "exit")
                    {
                        ExitProgram();
                    }
                    else
                    {
                        do
                        {
                            cout << "Pick one." << endl;
                            cout << endl;
                            cout << "Yes" << endl;
                            cout << "No" << endl;
                            cout << "Exit" << endl;
                            cin >> again;

                            if(again == "yes")
                            {
                                RunningTotalAgain();
                            }
                            else if(again == "no")
                            {
                                cout << "Returned to main menu" << endl;
                                cout << endl;
                                DisplayMenuOptions();
                            }
                            else if(again == "exit")
                            {
                                ExitProgram();
                            }

                        } while (again != "yes" || again != "no" || again != "exit");
                    }
                }
            }
    break;

    case 4: //Computer guesses your number.

        cout << "Computer guess your number game selected. It has unlimited tries. Enter any number between 0 and 1000" << endl;
        cin >> yournum;

        if(yournum <= 1000 && yournum >= 0)
        {
            cout << "Number " << yournum << " selected. Enter 1 to have the computer start guessing your number or 2 to exit. If neither are selected, then you'll have to restart." << endl;
            cin >> one;

            if(one == 1)
            {
                for(int i = 0; ; i++) //computer has unlimited attempts to guess your number
                {
                    compnumtries = compnumtries + 1;
                    int compnum = numrange(1000, 1);

                    if(compnum == yournum)
                    {
                        cout << "Computer has guessed your number which is: " << yournum << "." << endl;
                        cout << endl;
                        cout << "It took the computer " << compnumtries << " tries to guess your number." << endl;
                        cout << endl;
                        cout << endl;
                        cout << "Again?" << endl;
                        cout << endl;
                        cout << "1. Yes" << endl;
                        cout << "2. No" << endl;
                        cout << "3. Exit" << endl;
                        cin >> choice;

                        if(choice == 1)
                        {
                            int yournum2;
                            CompGuessNumAgain();
                        }
                        else if(choice == 2)
                        {
                            cout << "Returned to main menu." << endl;
                            cout << endl;
                            DisplayMenuOptions();
                        }
                        else if(choice == 3)
                        {
                            ExitProgram();
                        }
                        else
                        {
                            do
                            {
                                cout << endl;
                                cout << "Pick one" << endl;
                                cout << endl;
                                cout << "1. Yes" << endl;
                                cout << "2. No" << endl;
                                cout << "3. Exit" << endl;
                                cin >> choice;

                                if(choice == 1)
                                {
                                    cout << endl;
                                    CompGuessNumAgain();
                                }
                                else if(choice == 2)
                                {
                                    cout << "Returned to main menu." << endl;
                                    cout << endl;
                                    DisplayMenuOptions();
                                }
                                else if(choice == 3)
                                {
                                    ExitProgram();
                                }
                            } while(choice != 1 || choice != 2 || choice != 3);
                        }
                    }
                    else if(compnum != yournum)
                    {
                        cout << "Computer guessed " << compnum << "." << endl;
                        cout << endl;
                        cout << compnumtries << " tries so far" << endl;
                        cout << endl;
                    }
                }
            }
            else if(one == 2)
            {
                cout << endl;
                cout << "Returned to main menu" << endl;
                cout << endl;
                DisplayMenuOptions();
            }
            else
            {
                do
                {
                    cout << endl;
                    cout << "Enter 1 to restart or 2 to exit." << endl;
                    cin >> one;

                    if(one == 1)
                    {
                        cout << endl;
                        cout << "Restarting..." << endl;
                        cout << endl;
                        CompGuessNumAgain();
                    }
                    else if(one == 2)
                    {
                        ExitProgram();
                    }
                } while (one != 1 && one != 2);
            }
        }
        else
        {
            do
            {
                cout << endl;
                cout << "Restarting because you didn't follow the directions" << endl;
                cout << endl;
                CompGuessNumAgain();
            } while(yournum > 100 || yournum < 0);
        }

    break;
  }
}
