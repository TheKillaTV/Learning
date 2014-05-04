/* creates an empty box like this:

* * * * * *
*         *
*         *
*         *
*         *
*         *
* * * * * *

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char border[10][10];

    for (int row = 0; row < 6; ++row)
    {
        border[row][0] = '*';
        cout << border[row][0] << " ";
    }
    cout << endl;

    for(int col = 0; col < 6; ++col)
    {
        border[1][col] = '*';
        cout << border[1][col] << setw(10) << border[1][col] << endl;
    }

    for(int row = 0; row < 6; ++row)
    {
        border[0][row] = '*';
        cout << border[0][row] << " ";
    }

}
