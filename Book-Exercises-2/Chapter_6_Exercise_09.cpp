/* 
    Do Programming Exercise 6 but modify it to get information from a file.The first
item in the file should be the number of contributors,
and the rest of the file should
consist of pairs of lines,
with the first line of each pair being a contributor’s name
and the second line being a contribution.That is,
the file should look like this:

4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 100;

struct Members
{
    string name;
    double amount;
};

int main()
{
    char answer;
    int contributors;
    ifstream fin;
    fin.open("ContributorInfo.txt");

    if (!fin.is_open())
    {
     cout << "Could not find the file! Program terminating...";
     return 0;
    }

    fin >> contributors;
    Members * ps = new Members [contributors];

    for (int i  = 0; i < contributors; i++)
    {
        fin.get();
        getline(fin, ps[i].name);
        fin >> ps[i].amount;
    }

    cout << "File Input read. Display in console?" << endl << endl;
    cout << "A. Yes     B. No ";
    cin >> answer;

    if (answer == 'A' || answer == 'a')
    {
        cout << "Grand Patrons: " << endl << endl;

        for (int i = 0; i < contributors; i++)
        {
            cout << ps[i].name << endl;
            cout << ps[i].amount << endl << endl;
        }

        cout << "Patrons: " << endl << endl;

        for (int i = 0; i < contributors; i++)
        {
            if (ps[i].amount >= 10000)
            {
                cout << ps[i].name  << endl;
                cout << ps[i].amount << endl << endl;
            }
        }

    }
    else
        return 0;
    fin.close();
    delete[] ps;
}
