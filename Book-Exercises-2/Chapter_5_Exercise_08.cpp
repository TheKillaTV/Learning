/* Write a program that uses an array of char and a loop to read one word at a time
until the word done is entered.The program should then report the number of
words entered (not counting done).A sample run could look like this:

Enter words (to stop, type the word done):
anteater birthday category dumpster
envy finagle geometry done for sure
You entered a total of 7 words.
You should include the cstring header file and use the strcmp() function to
make the comparison test.

*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int WordSize = 40;
    int WordCount = 0;

    char Word[WordSize];

    cout << "Enter a sentence with the word done in it. The program will read the words up to the done word and exit" << endl;

    cin >> Word;

    while(strcmp(Word, "done"))
    {
        WordCount += 1;
        cin >> Word;

    }

    cout << "Sentence finished. Their were " << WordCount << " words." << endl;
}
