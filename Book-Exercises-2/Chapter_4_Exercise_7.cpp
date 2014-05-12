/* William Wingate runs a pizza-analysis service. For each pizza, he needs to record the following information:

* The name of the pizza company, which can consist of more than word
* The diameter of the pizza
* The weight of the pizza

Devise a structure that can hold this information and write a program that uses a structure variable of that type. The program
should ask the user to enter each of the preceding items of information, and then the program should display that information.
Use cin (or its methods), and cout.

*/

#include <iostream>
#include <string>

using namespace std;

struct pizza
{
    string name;
    double diameter;
    double weight;
};

int main()
{
    pizza sweats;
    cout << "Enter the name of the pizza company: ";
    getline(cin, sweats.name);
    cout << endl;
    cout << "Enter the diameter of the pizza: ";
    cin >> sweats.diameter;
    cout << endl;
    cout << "Enter the weight of the pizza: ";
    cin >> sweats.weight;

    cout << "Here's the information you entered: " << endl << endl;

    cout << "Name: " << sweats.name << endl << "Diameter: " << sweats.diameter << endl << "Weight: " << sweats.weight << endl << endl;
}
