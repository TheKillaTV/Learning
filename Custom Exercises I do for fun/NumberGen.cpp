// Creates a file with 10k random numbers, then prints how many of those numbers were odd and even.

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream fin;
    fin.open("Example.txt");
    int even = 0, odd = 0;
    for (int i = 0; i < 10000; i++)
    {
        int random = rand() % 1000 + 1;
        fin << random << endl;

        if (random % 2 == 0 )
            even++;
        else
            odd++;
    }
    fin << even << " even numbers were generated." << endl;
    fin << odd << " odd numbers were generated." << endl;

    fin.close();
}
