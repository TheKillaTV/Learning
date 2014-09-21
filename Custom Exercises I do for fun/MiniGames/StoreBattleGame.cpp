// A simple game I made for practice. Made by Sweats.

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

int lives = 100, EXP = 0, gold = 0, PlayerHp = 100;
int MonsterHp = 10;
bool HasGodMode = false;

void MainMenu();
void StoreLoop();
void BattleLoop();
void MonsterFight();

int GenerateRandomDamage(int number)
{
    return rand() % 10 + 1;
}

int ExitPrgram()
{
    cout << "Exiting Program...";
    return 0;
}

int main(int argc, char const *argv[])
{
    srand (time (NULL) );
    bool IsStoreOpen = false;
    bool IsBattleOpen = false;
    MainMenu();
}
void StoreLoop()
{
    char choice, StoreChoice, StoreChoiceCheck;
    bool IsStoreOpen = true;

    if (gold <= 0)
    {
        bool IsStoreOpen = false;
        cout << "---------------------------" << endl;
        cout << "Sorry! You either have to fight some more monsters to earn atleast 10 gold first or you ran out of gold after shopping. Returning to Main Menu..." << endl; 
        cout << "---------------------------" << endl << endl << endl;
        MainMenu();
        cout << endl << endl << endl;
    }
    else
    {
        while (IsStoreOpen)
        {
            cout << "Welcome to the Store! Which upgrade would you like to buy?" << endl << endl;
            cout << "A. Godmode (10g) " << setw(5) << " B. Exit Store " << endl;
            cin >> choice;

            if (choice == 'A' || choice == 'a' && gold >= 10)
            {
                if (!HasGodMode)
                {
                    HasGodMode = true;
                    cout << "You bought Godmode for 10 gold! Want to buy anything else?" << endl;
                    gold -= 10;
                    cout << "A. Yes " << setw(5) << " B. No " << endl;
                    cin >> StoreChoiceCheck;

                    if (StoreChoiceCheck == 'A' || 'a')
                        StoreLoop();

                    else if (StoreChoiceCheck == 'B' || 'b')
                    {
                        IsStoreOpen = false;
                        cout << "Returned to Main Menu..." << endl << endl << endl;
                        MainMenu();
                    }
                    else
                    {
                        do
                        {
                            cout << "Pick one of the options!" << endl;
                            cin >> StoreChoiceCheck;

                            if (StoreChoiceCheck == 'A' || StoreChoiceCheck == 'a')
                                StoreLoop();

                            else if (StoreChoiceCheck == 'B' || StoreChoiceCheck == 'b')
                            {
                                IsStoreOpen = false;
                                cout << "Returned to Main Menu..." << endl << endl << endl;
                                MainMenu();
                            }
                            else
                            {
                                cout << "Pick one of the options!" << endl;
                                cin >> StoreChoiceCheck;
                            }

                        } while (StoreChoiceCheck != 'A' || StoreChoiceCheck != 'a' || StoreChoiceCheck != 'B' || StoreChoiceCheck != 'b');
                    }
                }
                else
                {
                    cout << endl << endl;
                    cout << "You already have Godmode! Returning to Main Menu...." << endl << endl << endl;
                    MainMenu();
                }
            }
            else if (choice == 'B' || choice == 'b')
            {
                IsStoreOpen = false;
                cout << "Returned to Main Menu..." << endl << endl << endl;
                MainMenu();
            }
            else
            {
                do
                {
                    cout << "Pick one of the options!" << endl;
                    cin >> StoreChoiceCheck;

                    if (StoreChoiceCheck == 'A' || StoreChoiceCheck == 'a')
                        StoreLoop();

                    else if (StoreChoiceCheck == 'B' || StoreChoiceCheck == 'b')
                    {
                        IsStoreOpen = false;
                        cout << "Returned to Main Menu..." << endl;
                        MainMenu();
                    }
                    else
                    {
                        cout << "Pick one of the options!" << endl;
                        cin >> StoreChoiceCheck;
                    }

                } while (StoreChoiceCheck != 'A' || StoreChoiceCheck != 'a' || StoreChoiceCheck != 'B' || StoreChoiceCheck != 'b');

            }
        }
    }
}

void BattleLoop()
{
    bool IsBattleOpen = true;
    char choice;

    while (IsBattleOpen)
    {
        cout << "Battle Mode Entered. Enter A to begin";
        cin >> choice;

        while (choice == 'A' || choice == 'a')
            MonsterFight();

        if (choice != 'A')
        {
            IsBattleOpen = false;
            cout << "Returned to Main Menu..." << endl << endl << endl;
            MainMenu();
        }
    }
}

void MainMenu()
{
    char choice;

    cout << "Welcome to the Store Battle Game! Pick one of the options below." << endl;
    cout << "A. Store " << setw(5) << " B. Battle " << setw(5) << " C. Exit" << endl << endl << endl << endl;
    cout << "Stats: " << endl << endl;
    cout << "Lives: " << lives << endl;
    cout << "EXP: " << EXP << endl;
    cout << "Gold: " << gold << endl;

    if (!HasGodMode)
        cout << "Godmode: Off" << endl;
    else if (HasGodMode)
        cout << "Godmode: ON" << endl;

    cin >> choice;

    switch (choice)
    {
        case 'A':
            StoreLoop();
            break;
        case 'a':
            StoreLoop();
            break;
        case 'B':
            BattleLoop();
            break;
        case 'b':
            BattleLoop();
            break;
        case 'C':
            ExitPrgram();
            break;
        case 'c':
            ExitPrgram();
            break;
        default:
            do
            {
                cout << "Please pick one of the options below:" << endl;
                cout << "A. Store " << setw(5) << " B. Battle " << setw(5) << " C. Exit"  << endl;
                cin >> choice;

                if (choice == 'A' || choice == 'a')
                    StoreLoop();
                else if (choice == 'B' || choice == 'b')
                    BattleLoop();
                else if (choice == 'C' || choice == 'c')
                   ExitPrgram();
                else
                {
                    cout << "Please try again..." << endl;
                    cin >> choice;
                }

            } while (choice != 'A' || choice != 'a' || choice != 'B' || choice != 'b' || choice != 'C' || choice != 'c');

      break;
    }
}

void MonsterFight()
{
    int PlayerAttackDamage, MonsterAttackDamage, number;

    bool IsBattleOpen = true;
    char choice;

    PlayerAttackDamage = GenerateRandomDamage(number);

    if (!HasGodMode)
        MonsterAttackDamage = GenerateRandomDamage(number);
    else if (HasGodMode)
        MonsterAttackDamage = 0;

    MonsterHp = MonsterHp - PlayerAttackDamage;
    PlayerHp = PlayerHp - MonsterAttackDamage;

    Sleep(1000); // 1000 miliseconds = 1 second.

    cout << "You hit monster for " << PlayerAttackDamage << " damage!" << endl << endl;
    cout << "___________________" << endl << endl;

    if (!HasGodMode)
        cout << "Monster hits you for " << MonsterAttackDamage << " damage!" << endl << endl;
    else if (HasGodMode)
        cout << "Monster hits you for " << MonsterAttackDamage << " damage! (Godmode ON)" << endl << endl;

    cout << "___________________" << endl << endl;
    cout << "Your HP: " << PlayerHp << endl << endl;
    cout << "___________________" << endl << endl;
    cout << "Monster HP: " << MonsterHp << endl << endl;
    cout << "___________________" << endl << endl;

    if (MonsterHp <= 0)
    {
        cout << "You've slain the monster!" << endl << endl;
        EXP += 5;
        gold += 5;
        cout << "You've earned 5 EXP (total: " << EXP << ")" << " and looted 5 gold (total: " << gold << ")." << endl << endl;
        cout << "Want to fight another monster?" << endl << endl;
        cout << "A. Yes " << setw(5) << " B. No" << endl;
        cin >> choice;

        if (choice == 'A' || choice == 'a')
        {
            PlayerHp = 100;
            MonsterHp = 10;
            cout << "Battle Mode re-entered! Health restored back to 100!" << endl << endl;
            cout << "___________________" << endl << endl;
            BattleLoop();
        }
        else
        {
            IsBattleOpen = false;
            cout << "You flee!" << endl << endl << endl << endl;
            MainMenu();
        }

    }
    else if (PlayerHp <= 0)
    {
        IsBattleOpen = false;
        cout << "You died!" << endl;
        lives -= 1;
        cout << "You have " << lives << " lives remaining! Returning to main menu..." << endl << endl;
        MainMenu();
    }
}
