/* Do Programming Exercise 5 but use a two-dimensional array to store input for 3 years of monthly sales.
Report the total sales for each individual year and for the combined years.
*/

#include <iostream>
#include <string>

using namespace std;

int  main()
{

    int months[3][12];
    int total[3] = {0, 0, 0};
    string monthsname[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int year = 0, finalsum = 0;

   for (int i = 0; i < 3; i++)
   {
       for (int j = 0; j < 12; j++)
       {
           cout << "Enter the amount of sales for the " << monthsname[j] << " ";
           cin >> months[i][j];
           total[i] += months[i][j];
       }

       year = year + 1;
       cout << "The total sales for year " << year << " is " << total[i] << endl;
   }

   for (int i = 0; i < 3; i++)
   {
       cout << endl;
       cout << "Total sales for year " << i << " is " << total[i] << endl;
       finalsum += total[i];
   }

   cout << endl;
   cout << "The total sales in the past three years is " << finalsum << endl;
}
