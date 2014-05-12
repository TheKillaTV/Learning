/* The CandyBar structure contains three members. The first member holds the brand name of the candy bar. The second member holds the weight
(which may have a fractional part) of the candy bar, and the third member holds the number of calories (an integer value) in the candy bar. Write
a program that declares such a structure and creates a CandyBar variable called snack, initializing its members to, "Mocha Munch", 2.3, and 350,
respectively. The initialization should be part of the declaration for snack. Finally, the program should display the contents of the snack variable.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct CandyBar
    {
        string name;
        double weight;
        int calories;
    };

    CandyBar snack;

    snack.name = "Mocha Munch ";
    snack.weight = 2.3;
    snack.calories = 350;

    cout << "Name: " << snack.name << endl << "Weight: " << snack.weight << endl << "Calories: " << snack.calories << endl;
}
