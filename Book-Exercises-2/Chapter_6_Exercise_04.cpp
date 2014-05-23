/* When you join the Benevolent Order of Programmers, you can be known at BOP
meetings by your real name, your job title, or your secret BOP name.Write a program
that can list members by real name, by job title, by secret name, or by a member’s
preference. Base the program on the following structure:

// Benevolent Order of Programmers name structure
struct bop {
char fullname[strsize]; // real name
char title[strsize]; // job title
char bopname[strsize]; // secret BOP name
int preference; // 0 = fullname, 1 = title, 2 = bopname
};

In the program, create a small array of such structures and initialize it to suitable
values. Have the program run a loop that lets the user select from different alternatives:

a. display by name b. display by title
c. display by bopname d. display by preference
q. quit

Note that “display by preference” does not mean display the preference member; it
means display the member corresponding to the preference number. For instance, if
preference is 1, choice d would display the programmer’s job title.A sample run
may look something like the following:

Benevolent Order of Programmers Report
a. display by name b. display by title
c. display by bopname d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!

*/

#include <iostream>
#include <iomanip>

using namespace std;

struct bop
{
    string fullname;
    string title;
    string bopname;
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
    int preference = 0;
    char choice;
    bop info[3];

    info[0].fullname = "Sweats";
    info[0].title = "God";
    info[0].bopname = "Sweats the god";

    info[1].fullname = "Jeans";
    info[1].title = "Not a god";
    info[1].bopname = "Jeans the noob";

    info[2].fullname = "Hoodie";
    info[2].title = "May-May";
    info[2].bopname = "Awesome";

    cout << "Welcome to the informational program. Pick one of the options below: " << endl;
    cout << "A. Display by name " << setw(5) << "B. Display by title " << endl;
    cout << "C. Display by bopname " << setw(5) << "D. Display by preference " << endl;
    cout << "Q. Quit " << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != 'Q' || choice != 'q')
    {
        if (choice == 'A' || choice == 'a')
        {
            preference = 0;
            cout << "You've chosen to display the information by name:" << endl << endl;

            for (int i = 0; i < 3; i++)
            {
                cout << "Fullname: " << info[i].fullname << endl;
                cout << "Bopname: " << info[i].bopname << endl;
                cout << "Title: " << info[i].title << endl;
                cout << endl << endl;
            }

            cout << "Next choice: ";
            cin >> choice;
        }
        else if (choice == 'B' || choice == 'b')
        {
            preference = 1;
            cout << "You've chosen to display the information by title:" << endl << endl;

            for (int i = 0; i < 3; i++)
            {
                cout << "Title: " << info[i].title << endl;
                cout << "Fullname: " << info[i].fullname << endl;
                cout << "Bopname: " << info[i].bopname << endl;
                cout << endl << endl;
            }

            cout << "Next choice: ";
            cin >> choice;
        }
        else if (choice == 'C' || choice == 'c')
        {
            preference = 2;
            cout << "You've chosen to display the information by bopname:" << endl << endl;

            for (int i = 0; i < 3; i++)
            {
                cout << "Bopname: " << info[i].bopname << endl;
                cout << "Fullname: " << info[i].fullname << endl;
                cout << "Title: " << info[i].title << endl;
                cout << endl << endl;
            }

            cout << "Next choice: ";
            cin >> choice;
        }
        else if (choice == 'D' || choice == 'd')
        {
            switch(preference)
            {
            case 0:
                cout << "Fullnames: " << endl;
                for (int i  = 0; i < 3; i++)
                    cout << info[i].fullname << endl << endl;
                break;

            case 1:
                cout << "Titles: " << endl;
                for (int i = 0; i < 3; i++)
                    cout << info[i].title << endl << endl;
                break;

            case 2:
                cout << "Bopnames: " << endl;
                for (int i = 0; i < 3; i++)
                    cout << info[i].bopname << endl << endl;
                break;

            default:
                cout << "Default preference: " << endl;
                for (int i = 0; i < 3; i++)
                    cout << info[i].fullname << endl << endl;
                break;
            }

            cout << "Next choice: ";
            cin >> choice;
        }
        else if (choice == 'Q' || choice == 'q')
        {
            cout << "Bye!" << endl;
            return 0;
        }
        else
        {
            do
            {
                // Normally, I would use a function. For the sake of this exercise, i'm going to do it the hard way because the book has not taught functions yet.

                cout << "Pick one of the letters: " << endl << endl;

                cout << "A. Display by name " << setw(5) << "B. Display by title " << endl;
                cout << "C. Display by bopname " << setw(5) << "D. Display by preference " << endl;
                cout << "Q. Quit " << endl << endl;

                cout << "Enter your choice: ";
                cin >> choice;

                while(choice != 'Q' || choice != 'q')
                {
                    if (choice == 'A' || choice == 'a')
                    {
                        preference = 0;
                        cout << "You've chosen to display the information by name:" << endl << endl;

                        for (int i = 0; i < 3; i++)
                        {
                            cout << "Fullname: " << info[i].fullname << endl;
                            cout << "Bopname: " << info[i].bopname << endl;
                            cout << "Title: " << info[i].title << endl;
                            cout << endl << endl;
                        }

                        cout << "Next choice: ";
                        cin >> choice;

                    }
                    else if (choice == 'B' || choice == 'b')
                    {
                        preference = 1;
                        cout << "You've chosen to display the information by title:" << endl << endl;

                        for (int i = 0; i < 3; i++)
                        {
                            cout << "Title: " << info[i].title << endl;
                            cout << "Fullname: " << info[i].fullname << endl;
                            cout << "Bopname: " << info[i].bopname << endl;
                            cout << endl << endl;
                        }

                        cout << "Next choice: ";
                        cin >> choice;
                    }
                    else if (choice == 'C' || choice == 'c')
                    {
                        preference = 2;
                        cout << "You've chosen to display the information by bopname:" << endl << endl;

                        for (int i = 0; i < 3; i++)
                        {
                            cout << "Bopname: " << info[i].bopname << endl;
                            cout << "Fullname: " << info[i].fullname << endl;
                            cout << "Title: " << info[i].title << endl;
                            cout << endl << endl;
                        }

                        cout << "Next choice: ";
                        cin >> choice;
                    }
                    else if (choice == 'D' || choice == 'd')
                    {
                        switch(preference)
                        {
                        case 0:
                            cout << "Fullnames: " << endl;
                            for (int i  = 0; i < 3; i++)
                                cout << info[i].fullname << endl << endl;
                            break;

                        case 1:
                            cout << "Titles: " << endl;
                            for (int i = 0; i < 3; i++)
                                cout << info[i].title << endl << endl;
                            break;

                        case 2:
                            cout << "Bopnames: " << endl;
                            for (int i  = 0; i < 3; i++)
                                cout << info[i].bopname << endl << endl;
                            break;

                        default:
                            cout << "Default preference: " << endl;
                            for (int i  = 0; i < 3; i++)
                                cout << info[i].fullname << endl << endl;
                            break;
                        }

                        cout << "Next choice: ";
                        cin >> choice;
                    }
                    else if (choice == 'Q' || choice == 'q')
                    {
                        cout << endl;
                        cout << "Bye!" << endl;
                        return 0;
                    }
                    else
                    {
                        cout << "Try again: ";
                        cin >> choice;
                    }
                }

            } while (choice != 'A' || choice != 'a' || choice != 'B' || choice != 'b' || choice != 'C' || choice != 'c' || choice != 'D' || choice != 'd' || choice != 'Q' || choice != 'q');
        }
    }
}
