/* Do Programming Exercise 6, but instead of declaring an array of three CandyBar structures, use new to allocate the array dynmaically. */


#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    char name[20];
    double weight;
    int calories;
};

int main()
{
    CandyBar * ps = new CandyBar[3];

    cout << "Enter the name of CandyBar for first structure: ";
    cin >> ps[0].name;
    cout << "Enter the weight of CandyBar for first structure: ";
    cin >> ps[0].weight;
    cout << "Enter the calories of CandyBar for first structure: ";
    cin >> ps[0].calories;

    cout << endl << endl;

    cout << "Enter the name of CandyBar for second structure: ";
    cin >> ps[1].name;
    cout << "Enter the weight of CandyBar for second structure: ";
    cin >> ps[1].weight;
    cout << "Enter the calories of CandyBar for second structure: ";
    cin >> ps[1].calories;

    cout << endl << endl;

    cout << "Enter the name of CandyBar for third structure: ";
    cin >> ps[2].name;
    cout << "Enter the weight of CandyBar for third structure: ";
    cin >> ps[2].weight;
    cout << "Enter the calories of CandyBar for third structure: ";
    cin >> ps[2].calories;

    cout << "First structure: " << endl << endl;

    cout << "Name: " << ps[0].name << ". Weight: " << ps[0].weight << ". Calories: " << ps[0].weight << "." << endl << endl;

    cout << "Second structure: " << endl << endl;

    cout << "Name: " << ps[1].name << ". Weight: " << ps[1].weight << ". Calories: " << ps[1].weight << "." << endl << endl;

    cout << "Third structure: " << endl << endl;

    cout << "Name: " << ps[2].name << ". Weight: " << ps[2].weight << ". Calories: " << ps[2].weight << "." << endl << endl;

    delete ps;
}
