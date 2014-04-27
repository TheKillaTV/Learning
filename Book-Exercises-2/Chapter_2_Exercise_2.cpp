/* Write a short program that asks for your height in feet and inches and your weight
*  in pounds. (Use three variables to store the information.) Have the program report
*  your body mass index (BMI).To calculate the BMI, first convert your height in feet
*  and inches to your height in inches (1 foot = 12 inches).Then convert your height
*  in inches to your height in meters by multiplying by 0.0254.Then convert your
*  weight in pounds into your mass in kilograms by dividing by 2.2. Finally, compute
*  your BMI by dividing your mass in kilograms by the square of your height in meters.
*/ 

#include <iostream>

using namespace std;

int main()
{
    int feet, inches, pounds, feetininches;
    double inchestometer, kilograms, BMI;
    cout << "Enter your height beginning with feet" << endl;
    cin >> feet;
    cout << "Now inches." << endl;
    cin >> inches;
    cout << "Now enter your weight in pounds" << endl;
    cin >> pounds;

    feetininches = (feet * 12) + inches;
    cout << "Your total height in inches is: " << feetininches << " inches." << endl;
    cout << endl;
    inchestometer = feetininches * 0.0254;
    cout << "Your height in meters is: " << inchestometer << endl;
    cout << endl;
    kilograms = pounds / 2.2;
    cout << "Your weight in Kilograms is: " << kilograms << " Kilograms." << endl;
    cout << endl;
    BMI = kilograms / (inchestometer * inchestometer);
    cout << "Your BMI is: " << BMI << "." << endl;
}
