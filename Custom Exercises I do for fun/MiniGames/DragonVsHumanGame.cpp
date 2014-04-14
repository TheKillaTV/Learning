/* The object of this simple game is to get lucky and get the health of the dragon down to 0 before the dragon gets your health down to 0.
 * Damage can be anywhere from 1 to 10. Theres a 25% chance a hit can crit. If you or the dragon crits, the damage is doubled for that hit.
 * Have fun!
 * Made by Sweats for fun and practice.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int CalculateDamage(int dmghigh, int dmglow) // Formula for calculating damage.
{
    return rand() % (dmghigh - dmglow) + dmglow;
}

int CritChance(int crithigh, int critlow) // Formula for calculating crit chance.
{
    return rand() % (crithigh - critlow) + critlow;
}

int main()
{
    srand( time ( NULL ));

    int attack;
    int dragondmg, dragoncritamount, dragoncritchance, newdragondmg, newdragoncritchance, newdragoncritamount, DragonHp = 100, NewDragonHp; // Dragon
    int dmg, crit, critamount, newdmg, newcritamount, newcrit, PlayerHp = 100, NewPlayerHp; // Player

    cout << "A dragon approaches. Enter 1 to attack!" << endl;
    cin >> attack;

    if(attack == 1)
    {
        dmg = CalculateDamage(10, 1); // Damage can be anywhere from 1 to 10
        crit = CritChance(4, 1); // 25% crit chance. Random number from 1-4 will be picked. If 1 is picked, then crit.
        critamount = dmg * 2; // Crits doubles the amount of original damage.

        if(crit == 1)
        {
            NewDragonHp = DragonHp - critamount;
            cout << "You've hit the dragon for a crit of " << critamount << ". (Original Damage: " << dmg << ")" << endl;
            cout << endl;
            cout << "-----------------------" << endl;
            cout << "Current Dragon Hp: " << NewDragonHp << endl;
            cout << "-----------------------" << endl;
            cout << endl;
            cout << "Dragon attacks you!" << endl;
            cout << endl;
        }
        else if(crit != 1)
        {
            NewDragonHp = DragonHp - dmg;
            cout << "You've hit the dragon for: " << dmg << "!" << endl;
            cout << endl;
            cout << "-----------------------" << endl;
            cout << "Current Dragon Hp: " << NewDragonHp << endl;
            cout << "-----------------------" << endl;
            cout << endl;
            cout << "__________" << endl;
            cout << "Your hp: " << PlayerHp << endl;
            cout << "__________" << endl;
            cout << endl;
            cout << "Dragon attacks you!" << endl;
            cout << endl;
        }

        dragondmg = CalculateDamage(10, 1);
        dragoncritamount = dragondmg * 2;
        dragoncritchance = CritChance(4, 1);

        if(dragoncritchance == 1)
        {
            NewPlayerHp = PlayerHp - dragoncritamount;
            cout << "The Dragon hits you for a crit of " << dragoncritamount << ". (Original amount: " << dragondmg << ")" << endl;
            cout << endl;
            cout << "__________" << endl;
            cout << "Your hp: " << NewPlayerHp << endl;
            cout << "__________" << endl;
            cout << endl;
        }
        else if(dragoncritchance != 1)
        {
            NewPlayerHp = PlayerHp - dragondmg;
            cout << "The Dragon hits you for " << dragondmg << " damage!" << endl;
            cout << endl;
            cout << "__________" << endl;
            cout << "Your hp: " << NewPlayerHp << endl;
            cout << "__________" << endl;
            cout << endl;
        }

        while(NewPlayerHp || NewDragonHp > 0)
        {
            cout << "_________________________________________________________" << endl;
            cout << endl;
            cout << "Enter 1 to re-attack the Dragon!" << endl;
            cin >> attack;

            if(attack == 1)
            {
                newdmg = CalculateDamage(10, 1);
                newcrit = CritChance(4, 1);
                newcritamount = newdmg * 2;

                if(newcrit == 1)
                {
                    NewDragonHp = NewDragonHp - newcritamount;

                    cout << "You've hit the dragon for a crit of " << newcritamount << " (Original Damage: " << newdmg << ")" << endl;
                    cout << endl;
                    cout << "-----------------------" << endl;
                    cout << "Current Dragon Hp: " << NewDragonHp << endl;
                    cout << "-----------------------" << endl;
                    cout << endl;
                    cout << "Dragon re-attacks you!" << endl;
                    cout << endl;

                    newdragondmg = CalculateDamage(10, 1);
                    newdragoncritchance = CritChance(4, 1);
                    newdragoncritamount = newdragondmg * 2;

                    if(dragoncritchance == 1)
                    {
                        NewPlayerHp = NewPlayerHp - newdragoncritamount;
                        cout << "Dragon attacked you with a crit of " << newdragoncritamount << " (Original Damage: " << newdragondmg << ")" << endl;
                        cout << endl;
                        cout << "__________" << endl;
                        cout << "Your Hp: " << NewPlayerHp << endl;
                        cout << "__________" << endl;
                        cout << endl;

                    }
                    else if(dragoncritchance != 1)
                    {
                        NewPlayerHp = NewPlayerHp - newdragondmg;
                        cout << "Dragon attacked you for " << newdragondmg << " damage." << endl;
                        cout << endl;
                        cout << "__________" << endl;
                        cout << "Your Hp: " << NewPlayerHp << "." << endl;
                        cout << "__________" << endl;
                        cout << endl;

                    }
                }
                else if (newcrit != 1)
                {
                    NewDragonHp = NewDragonHp - newdmg;
                    cout << "You've hit the dragon for " << newdmg << " damage." << endl;
                    cout << endl;
                    cout << "------------------------" << endl;
                    cout << "Current Dragon Hp: " << NewDragonHp << endl;
                    cout << "------------------------" << endl;
                    cout << endl;
                    cout << "Dragon re-attacks you!" << endl;
                    cout << endl;

                    newdragondmg = CalculateDamage(10, 1);
                    newdragoncritchance = CritChance(4, 1);
                    newdragoncritamount = newdragondmg * 2;

                    if(dragoncritchance == 1)
                    {
                        NewPlayerHp = NewPlayerHp - newdragoncritamount;
                        cout << "Dragon attacked you with a crit of " << newdragoncritamount << ". (Original Damage: " << newdragondmg << ")" << endl;
                        cout << endl;
                        cout << "___________" << endl;
                        cout << "Your Hp: " << NewPlayerHp << endl;
                        cout << "___________" << endl;
                        cout << endl;

                    }
                    else if(dragoncritchance != 1)
                    {
                        NewPlayerHp = NewPlayerHp - newdragondmg;
                        cout << "Dragon attacked you for " << newdragondmg << " damage." << endl;
                        cout << endl;
                        cout << "___________" << endl;
                        cout << "Your Hp: " << NewPlayerHp << "." << endl;
                        cout << "___________" << endl;
                        cout << endl;

                    }

                }

            }

            if(NewPlayerHp <= 0 && NewPlayerHp < NewDragonHp)
            {
                cout << "*******************" << endl;
                cout << "The Dragon Wins!" << endl;
                cout << "*******************" << endl;
                cout << endl;
                return 0;
            }
            else if(NewDragonHp <= 0 && NewDragonHp < NewPlayerHp)
            {
                cout << "**********" << endl;
                cout << "You win!" << endl;
                cout << "**********" << endl;
                cout << endl;
                return 0;
            }
        }
    }
}
