/*
    Put together a program that keeps track of monetary contributions to the Society
for the Preservation of Rightful Influence. It should ask the user to enter the number
of contributors and then solicit the user to enter the name and contribution of
each contributor.
    The information should be stored in a dynamically allocated array
of structures. Each structure should have two members: a character array (or else a
string object) to store the name and a double member to hold the amount of the
contribution.
    After reading all the data, the program should display the names and
amounts donated for all donors who contributed $10,000 or more.This list should
be headed by the label Grand Patrons.After that, the program should list the
remaining donors.That list should be headed Patrons.
    If there are no donors in one of the categories, the program should print the word “none.” Aside from displaying
two categories, the program needs no sorting.

*/

#include <iostream>

using namespace std;

struct Members
{
    bool HasDonatedMoreThan10k;
    string name;
    double amount;
};

int main()
{
    char answer;
    int contributors, specialcontributors = 0;
    cout << "Enter the the amount of contributors ";
    cin >> contributors;

    Members Stats[contributors];

    for (int i = 0; i < contributors; i++)
    {
        cout << "Enter the name for the " << i + 1 << " contributor:" << endl;
        cin >> Stats[i].name;
        cout << "Now enter their amount: " << endl;
        cin >> Stats[i].amount;
        cout << i + 1 << " out of " << contributors << " recorded." << endl;
    }

    cout << "Here are the contributors: " << endl << endl << endl;

    for (int j = 0; j < contributors; j++)
    {
        if (Stats[j].amount >= 10000)
        {
            specialcontributors++;
            Stats[j].HasDonatedMoreThan10k = true;
            cout << "Contributor " << Stats[j].name << " skipped because he or she has donated more than $10k." << endl;
        }
        else
        {
            Stats[j].HasDonatedMoreThan10k = false;
            cout << "Contributor number " << j << ":" << endl << endl;
            cout << "Name: " << Stats[j].name << "." << endl << endl;
            cout << "Donation amount: " << Stats[j].amount << "." << endl << endl;
        }
    }

    cout << "Display list of people who have donated more than 10k? " << endl;
    cout << "A. Yes.    B. No." << endl;
    cin >> answer;

    if (answer == 'A' || answer == 'a')
    {
        if (specialcontributors > 0)
        {
            for (int k = 0; k < contributors; k++)
            {
                if (Stats[k].HasDonatedMoreThan10k)
                {
                    cout << endl << endl;
                    cout << "Name of special contributor: " << Stats[k].name << "." << endl;
                    cout << "Donation amount: " << Stats[k].amount << "." << endl << endl;
                }
                else
                    cout << endl; // Do nothing basically.
            }
        }
        else
            cout << "Special contributors: None." << endl;
    }

    else if (answer == 'B' || answer == 'b')
    {
        cout << "Option B picked. Exiting program..." << endl;
        return 0;
    }
    else
    {
        cout << "No option picked. Exiting program..." << endl;
        return 0;
    }
}
