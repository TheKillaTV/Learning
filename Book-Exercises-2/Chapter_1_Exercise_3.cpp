/* Write a C++ program that uses three user-defined functions (counting main() as
one) and produces the following output:
Three blind mice
Three blind mice
See how they run
See how they run
One function, called two times, should produce the first two lines, and the remaining
function, also called twice, should produce the remaining output.
*/

#include <iostream>

using namespace std;

void PrintOutPutMice();
void PrintOutPutRun();

int main()
{
    int i;
    PrintOutPutMice();
    PrintOutPutRun();

    return 0;
}

void PrintOutPutMice()
{
    for(int i = 0; i < 2; i++)
    {
        cout << "Three blind mice" << endl;
    }
}

void PrintOutPutRun()
{
    for(int i = 0; i < 2; i++)
    {
        cout << "See how they run" << endl;
    }
}
