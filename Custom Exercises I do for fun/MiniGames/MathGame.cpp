#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int PickRandomNumber(int high, int low)
{
    return rand() % (high - low) + low;
}

int PickType(int PickHigh, int PickLow)
{
    return rand() % (PickHigh - PickLow) + PickLow;
}

int ReverseOrderChance(int top, int bot)
{
    return rand() % (top - bot) + bot;
}

int main()
{
    srand( time( NULL ) );

    int Type, ADDITION = 0, SUBTRACTION = 1, MULTIPLICATION = 2, DIVISION = 3;
    int i, start, generator, high = 10, low = 1, problemcount = -1, answer, useranswer, incorrectcount = 0, correctcount = 0, bot = 1, top = 3;
    int firstnumber = PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low), chance = ReverseOrderChance(top, bot);

    cout << "Welcome to the Math mini game. A random number will be picked between the values you enter." << endl;
    cout << endl;
    cout << "How many problems do you want to be generated? " << endl;
    cout << endl;
    cin >> generator;
    cout << endl;
    cout << "A random number will be chosen between " << high << " and " << low << " and " << generator << " problems will be generated." << endl;
    cout << endl;
    cout << "Enter 1 or any number to begin." << endl;
    cout << endl;
    cin >> start;
    cout << endl;

    if(start == 1 || start != 1)
    {
        for (i = 0; i < generator; i++)
        {
            cout << "___________________________________________________________" << endl;
            cout << endl;
            problemcount = problemcount + 1;
            cout << "Problems attempted so far: " << problemcount << "." << endl;
            cout << endl;
            cout << "Problems correct: " << correctcount << "." << endl;
            cout << endl;
            cout << "Problems incorrect: " << incorrectcount << "." << endl;
            cout << endl;

            Type = PickType(4, 0);

            if (Type == ADDITION)
            {
                cout << "Addition picked!" << endl;
                cout << endl;
                chance = ReverseOrderChance(top, bot);

                if (chance == 1)
                {
                    cout << endl;
                    cout << "Math problem reversed." << endl;
                    cout << endl;
                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = secondnumber + firstnumber;

                    cout << "What is " << secondnumber << " + " << firstnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                       cout << endl;
                       cout << "Correct!" << endl;
                       cout << secondnumber << " + " << firstnumber << " = " << answer << "!" << endl;
                       cout << endl;
                       correctcount = correctcount + 1;
                    }
                   else if(useranswer != answer)
                   {
                       //cout << "DEBUGGING: " << answer << endl;
                       cout << endl;
                       cout << "Incorrect!" << endl;
                       cout << endl;
                       cout << "*************************" << endl;
                       cout << "The correct answer is: " << answer << "." << endl;
                       cout << "*************************" << endl;
                       cout << endl;
                       incorrectcount = incorrectcount + 1;
                   }
                }
                else if (chance != 1)
                {
                    cout << endl;
                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = firstnumber + secondnumber;

                    cout << "What is " << firstnumber << " + " << secondnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                       cout << endl;
                       cout << "Correct!" << endl;
                       cout << firstnumber << " + " << secondnumber << " = " << answer << "!" << endl;
                       cout << endl;
                       correctcount = correctcount + 1;
                    }
                   else if(useranswer != answer)
                   {
                       //cout << "DEBUGGING: " << answer << endl;
                       cout << endl;
                       cout << "Incorrect!" << endl;
                       cout << endl;
                       cout << "*************************" << endl;
                       cout << "The correct answer is: " << answer << "." << endl;
                       cout << "*************************" << endl;
                       cout << endl;
                       incorrectcount = incorrectcount + 1;
                   }
                }
            }
            else if (Type == SUBTRACTION)
            {
                cout << "Subtraction picked!" << endl;
                cout << endl;
                chance = ReverseOrderChance(top, bot);

                if (chance == 1)
                {
                    cout << endl;
                    cout << "Math problem reversed." << endl;
                    cout << endl;
                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = secondnumber - firstnumber;

                    cout << "What is " << secondnumber << " - " << firstnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                       cout << endl;
                       cout << "Correct!" << endl;
                       cout << secondnumber << " - " << firstnumber << " = " << answer << "!" << endl;
                       cout << endl;
                       correctcount = correctcount + 1;
                    }
                   else if(useranswer != answer)
                   {
                       //cout << "DEBUGGING: " << answer << endl;
                       cout << endl;
                       cout << "Incorrect!" << endl;
                       cout << endl;
                       cout << "**************************" << endl;
                       cout << "The correct answer is: " << answer << "." << endl;
                       cout << "**************************" << endl;
                       cout << endl;
                       incorrectcount = incorrectcount + 1;
                   }
                }
                else if (chance != 1)
                {
                    cout << endl;
                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = firstnumber - secondnumber;

                    cout << "What is " << firstnumber << " - " << secondnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                        cout << endl;
                        cout << "Correct!" << endl;
                        cout << firstnumber << " - " << secondnumber << " = " << answer << "!" << endl;
                        cout << endl;
                        correctcount = correctcount + 1;
                    }
                    else if(useranswer != answer)
                    {
                        //cout << "DEBUGGING: " << answer << endl;
                        cout << endl;
                        cout << "Incorrect!" << endl;
                        cout << endl;
                        cout << "**************************" << endl;
                        cout << "The correct answer is: " << answer << "." << endl;
                        cout << "**************************" << endl;
                        incorrectcount = incorrectcount + 1;
                    }
                }
            }
            else if (Type == MULTIPLICATION)
            {
                cout << "Multiplication picked!" << endl;
                cout << endl;
                chance = ReverseOrderChance(top, bot);

                if (chance == 1)
                {
                    cout << endl;
                    cout << "Math problem reversed." << endl;
                    cout << endl;
                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = secondnumber * firstnumber;

                    cout << "What is " << secondnumber << " * " << firstnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                       cout << endl;
                       cout << "Correct!" << endl;
                       cout << secondnumber << " * " << firstnumber << " = " << answer << "!" << endl;
                       cout << endl;
                       correctcount = correctcount + 1;
                    }
                   else if(useranswer != answer)
                   {
                       //cout << "DEBUGGING: " << answer << endl;
                       cout << endl;
                       cout << "Incorrect!" << endl;
                       cout << endl;
                       cout << "**************************" << endl;
                       cout << "The correct answer is: " << answer << "." << endl;
                       cout << "**************************" << endl;
                       cout << endl;
                       incorrectcount = incorrectcount + 1;
                   }
                }
                else if (chance != 1)
                {
                    cout << endl;
                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = firstnumber * secondnumber;

                    cout << "What is " << firstnumber << " * " << secondnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                        cout << endl;
                        cout << "Correct!" << endl;
                        cout << firstnumber << " * " << secondnumber << " = " << answer << "!" << endl;
                        cout << endl;
                        correctcount = correctcount + 1;
                    }
                    else if(useranswer != answer)
                    {
                        //cout << "DEBUGGING: " << answer << endl;
                        cout << endl;
                        cout << "Incorrect!" << endl;
                        cout << "**************************" << endl;
                        cout << "The correct answer is: " << answer << "." << endl;
                        cout << "**************************" << endl;
                        cout << endl;
                        incorrectcount = incorrectcount + 1;
                    }
                }
            }
            else if (Type == DIVISION)
            {
                cout << "Division picked!" << endl;
                cout << endl;
                chance = ReverseOrderChance(top, bot);

                if (chance == 1)
                {
                    cout << endl;
                    cout << "Math problem reversed." << endl;
                    cout << endl;

                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = secondnumber / firstnumber;

                    cout << "What is " << secondnumber << " / " << firstnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                       cout << endl;
                       cout << "Correct!" << endl;
                       cout << secondnumber << " / " << firstnumber << " = " << answer << "!" << endl;
                       cout << endl;
                       correctcount = correctcount + 1;
                    }
                   else if(useranswer != answer)
                   {
                       //cout << "DEBUGGING: " << answer << endl;
                       cout << endl;
                       cout << "Incorrect!" << endl;
                       cout << endl;
                       cout << "**************************" << endl;
                       cout << "The correct answer is: " << answer << "." << endl;
                       cout << "**************************" << endl;
                       incorrectcount = incorrectcount + 1;
                   }
                }
                else if (chance != 1)
                {
                    cout << endl;

                    firstnumber =  PickRandomNumber(high, low), secondnumber = PickRandomNumber(high, low);
                    answer = firstnumber / secondnumber;

                    cout << "What is " << firstnumber << " / " << secondnumber << "?" << endl;
                    cin >> useranswer;
                    cout << endl;

                    if(useranswer == answer)
                    {
                        cout << endl;
                        cout << "Correct!" << endl;
                        cout << firstnumber << " / " << secondnumber << " = " << answer << "!" << endl;
                        cout << endl;
                        correctcount = correctcount + 1;
                    }
                    else if(useranswer != answer)
                    {
                        //cout << "DEBUGGING: " << answer << endl;
                        cout << endl;
                        cout << "Incorrect!" << endl;
                        cout << endl;
                        cout << "***************************" << endl;
                        cout << "The correct answer is: " << answer << "." << endl;
                        cout << "***************************" << endl;
                        cout << endl;
                        incorrectcount = incorrectcount + 1;
                    }
                }
            }
        }
        if (i == generator)
        {
            problemcount = problemcount + 1;
            cout << "-------------------------" << endl;
            cout << "Generation limit reached!" << endl;
            cout << "-------------------------" << endl;
            cout << endl;
            cout << "Here are your final results: " << endl;
            cout << endl;
            cout << endl;
            cout << "----------------------" << endl;
            cout << "Problems Attempted: " << problemcount << "." << endl;
            cout << "----------------------" << endl;
            cout << endl;
            cout << "********************" << endl;
            cout << "Problems Correct: " << correctcount << "." << endl;
            cout << "********************" << endl;
            cout << endl;
            cout << "######################" << endl;
            cout << "Problems Incorrect: " << incorrectcount << "." << endl;
            cout << "######################" << endl;
            cout << endl;
            cout << "()()()()()(()()()()" << endl;
            cout << "Thanks For Playing!" << endl;
            cout << "()()()()()(()()()()" << endl;
            return 0;
        }
    }
}
