#include <iostream>

using namespace std;

int main()
{
    int FirstNum, SecondNum, total = 0;
    cout << "Enter two numbers to find the sum between those two numbers ";
    cin >> FirstNum;
    cin >> SecondNum;

    for(int i = FirstNum; FirstNum <= SecondNum; FirstNum++)
    {
        cout << " " << FirstNum;
        total += FirstNum;
    }
    
    cout << " The total is: " << total << endl;
}
