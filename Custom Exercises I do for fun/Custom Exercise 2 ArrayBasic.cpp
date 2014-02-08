/* Write a program that asks the user to type 10 integers of an array. The program must compute and write how many integers are greater than or equal to 10. */

// Thanks Nonomus for the tips :) :3 <3 x0x0x0x0!

#include <iostream>

using namespace std;

int main()
{
    int nums[11];
    cout << "Enter 10 values please" << endl;

    for(int i = 0; i < 10; i++)
    {
        cin >> nums[i];
        cout << i << " values entered" << endl;
    }
    for(int j = 0; j < 10; j++)
    {
        if(nums[j] == 10)
        {
            cout << "Number " << nums[j] << " is equal to 10!" << endl;
        }
        else if (nums[j] < 10)
        {
            cout << "Number " << nums[j] << " is less than 10" << endl;
        }
        else if(nums[j] > 10)
        {
            cout << "Number " << nums[j] << " is greater than 10" << endl;
        }
    }
}
