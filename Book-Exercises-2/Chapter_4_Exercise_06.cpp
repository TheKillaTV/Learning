/* The CandyBar structure contains three members, as described in programming exercise 5. Write a program that creates an array of three CandyBar structures, initializes them
to values of your choice, and then displays the contents of each structure.

*/

#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string name;
    double weight;
    int calories;
};

int main()
{
    CandyBar snacks[3] =
    {
        {"Yummy Yum ", 3.14, 420},
        {"Delicious Yummy ", 4.20, 314},
        {"<3 Sweats ", 3.60, 525}
    };

    cout << "First structure: " << endl << endl;

    cout << "Name: " << snacks[0].name << ". Weight: " << snacks[0].weight << ". Calories: " << snacks[0].calories << endl << endl;

    cout << "Second structure: " << endl << endl;

    cout << "Name: " << snacks[1].name << ". Weight: " << snacks[1].weight << ". Calories: " << snacks[1].calories << endl << endl;

    cout << "Third structure: " << endl << endl;

    cout << "Name: " << snacks[2].name << ". Weight: " << snacks[2].weight << ". Calories: " << snacks[2].calories << endl << endl;

}
