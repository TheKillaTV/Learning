/* Write a C++ program that requests and displays information as shown in the following example of output:

What is your first name? Betty Sue
What is your last name? Yewe
What letter grade did you receive? B
What is your age? 22

Name: Yewe, Betty Sue
Grade: C
Age: 22

*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct info
    {
        string firstname, lastname;
        char grade;
        int age;

    };

    info you;
    cout << "What is your first name? ";
    getline(cin, you.firstname);
    cout << endl;
    cout << "What is your last name? ";
    getline(cin, you.lastname);
    cout << endl;
    cout << "What letter grade did you receive? ";
    cin >> you.grade;
    cout << endl;
    cout << "What is your age? ";
    cin >> you.age;
    cout << endl << endl;

    cout << "Name: " << you.firstname << ", " << you.lastname << endl;
    cout << "Grade: " << you.grade << endl;
    cout << "Age: " << you.age << endl;
}
