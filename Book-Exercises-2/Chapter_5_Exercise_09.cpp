/* Write a program that matches the description of the program in Programming
Exercise 8, but use a string class object instead of an array. Include the string
header file and use a relational operator to make the comparison test.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int WordCount = 0;
    string sentence;

    cout << "Enter a sentence one word at a time. Type in the word done to exit."<< endl;
    cin >> sentence;

    while(sentence != "done")
    {
        WordCount += 1;
        cin >> sentence;
    }

    cout << "There were " << WordCount << " words before the word done." << endl;
}
