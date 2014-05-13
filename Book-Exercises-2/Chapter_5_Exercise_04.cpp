/* Daphne invests $100 at 10% simple interest.That is, every year, the investment earns
10% of the original investment, or $10 each and every year:

interest = 0.10 × original balance

At the same time, Cleo invests $100 at 5% compound interest.That is, interest is 5%
of the current balance, including previous additions of interest:

interest = 0.05 × current balance

Cleo earns 5% of $100 the first year, giving her $105.The next year she earns 5% of
$105, or $5.25, and so on.Write a program that finds how many years it takes for
the value of Cleo’s investment to exceed the value

*/

#include <iostream>


using namespace std;

int main()
{
    float Daphne = 100.0, Cleo = 100.0, interestDaphne = 10.0, interestCleo = 0;
    int years = 0;
    interestCleo = Cleo * 0.05;
    Cleo = Cleo + interestCleo;
    Daphne = Daphne + interestDaphne;
    cout << "Cleo: " << Cleo << endl;
    cout << "Daphne: " << Daphne << endl;

    for(int i = 0; ; i++)
    {
        years += 1;
        interestCleo = Cleo * 0.05;
        Cleo = Cleo + interestCleo;
        Daphne = Daphne + interestDaphne;
        cout << Daphne << endl;
        cout << Cleo << endl;

        if(Cleo > Daphne)
        {
            cout << "It took " << years << " years for Cleo's interest to exceed Daphne's.";
            break;
        }
    }
}
