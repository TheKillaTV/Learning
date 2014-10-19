#include <iostream>

using namespace std;

double CalculateHarmonicMean(int x, int y);

int main()
{
    while(1)
    {
        int x, y;
        double answer = CalculateHarmonicMean(x, y);
        cout << "The Harmonic Mean of the two numbers is " << answer << "." << endl;

        if (answer == 0)
        {
            cout << "One of the pair of numbers is zero. Exiting program.";
            return 0;
        }
    }
}

double CalculateHarmonicMean(int x, int y)
{
    double answer = 0.0;
    cout << "Enter the number pair: (Enter 0 for one of the numbers to quit)." << endl;
    cin >> x;
    cin >> y;

    if (x != 0 && y != 0)
    {
        answer = 2.0 * x * y / (x + y);
        return answer;
    }
    else
    {
        answer = 0;
        return answer;
    }
}
