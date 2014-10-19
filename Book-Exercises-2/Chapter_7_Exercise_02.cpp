#include <iostream>

const int size = 10;

using namespace std;

void InputScores(int arr[], int size);
void DisplayScores(const int arr[], int size);
double AverageScores(int arr[], int size);

int main()
{
    double average = 0.0;
    int scores[size];
    InputScores(scores, size);

    cout << "Here are the scores: " << endl << endl;
    DisplayScores(scores, size);

    cout << "Here's the average of the scores: ";
    AverageScores(scores, size);

}

void InputScores(int arr[], int size)
{
    for (int i  = 0, q = 0; i < size; i++)
    {
        cout << "Enter the score for # " << i + 1 << ".  (Q to quit.) ";
        cin >> arr[i];
        if (cin.fail())
        {
            //sets the rest of the loop to 0.
            for (q = i; i < size; i++)
                arr[i] = 0;
            break;
        }
    }
}

void DisplayScores(const int arr[], int size)
{
    for (int i  = 0; i < size; i++)
        cout << "Score for # " << i + 1 << " is " << arr[i] << "." << endl;
}

double AverageScores(int arr[], int size)
{
    double average = 0.0;
    int total = 0;

    for (int i = 0; i < size; i++)
        total += arr[i];

    average = total / 10;
    cout << average << endl;
    return average;
}
