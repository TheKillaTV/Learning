/* Ask the user for two users' ages, and indicate who is older; behave differently if both are over 100. */

#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;

    cout << "Please enter the first persons age." << endl;
    cin >> x;
    cout << "Now enter the second persons age." << endl;
    cin >> y;
    cout << "The first persons age is: " << x << "." << endl;
    cout << "The second persons age is: " << y << "." << endl;

    if(x > y)
    {
        cout << "First person is older than second person." << endl;
    }
    else if (y > x)
    {
        cout << "Second person is older than the first person." << endl;
    }
    else if (x + y >= 100)
    {
        cout << "Both of your ages added together equals 100 or more!" << endl;
    }
    else
    {
        cout << "Both of you are the same age!" << endl;
    }
}
