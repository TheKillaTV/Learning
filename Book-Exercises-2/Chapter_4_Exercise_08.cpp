/* Do Programming Exercise 7 but use new to allocate a structure instead of declaring a structure variable. Also have the program request the pizza
diameter before it requests the pizza company name.
*/

#include <iostream>
#include <string>

using namespace std;

struct pizza
{
    double diameter;
    char name[20];
    double weight;
};

int main()
{
    pizza * ps = new pizza;
    cout << "Enter the diameter of the pizza";
    cin >> ps->diameter;
    cout << "Enter the name of the pizza company: ";
    cin >> ps->name;
    cout << endl;
    cout << "Enter the weight of the pizza";
    cin >> ps->weight;

    cout << "Name: " << (*ps).name << endl;
    cout << "Diameter: " << ps->diameter << endl;
    cout << "Weight: " << ps->weight << endl;

    delete ps;
}
