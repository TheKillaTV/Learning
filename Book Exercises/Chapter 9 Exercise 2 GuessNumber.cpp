/*  Write a program that picks a number between 1 and 10, and then lets the user guess what the number is.
The program should tell the user if their guess is too high, too low, or just right. */

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

int rand (int high, int low)
{
    return rand() % (high - low) + low;
}

int main()
{
    srand( time( NULL ) );
    int i;
    int guess;
    int answer = rand(10, 1);
    cout << "Guess a number between 1 and 10." << endl;
    cin >> guess;

    /*for (i = 0; i < 1; i++)
    {
        answer;
    }
    */

   do
   {
       if(guess > answer)
       {
           cout << "Guess lower!" << endl;
           cin >> guess;
       }
      else if (guess < answer)
      {
          cout << "Guess higher!" << endl;
          cin >> guess;
      }
      else if (guess == answer)
      {
          cout << "You got it!" << endl;
      }
      else
      {
          cout << "idk" << endl;
      }
   } while (guess != answer);
}
