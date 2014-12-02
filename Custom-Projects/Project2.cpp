// http://a.fsdn.com/con/app/proj/gsprogrammerchallengeforn00bz/screenshots/challenge.jpg
// Note to self: Will add more challenges to this. 

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h> // Compiled on Linux. Use #include <windows.h> instead to compile on Windows. Replace sleep(1) with Sleep(1000).

using std::cout;
using std::cin;
using std::cin;
using std::endl;
using std::string;

const int size = 101; // For FizzBuzz.
const int rock = 1, paper = 2, scissors = 3; // For Rock Paper Scissors
const double pi = 3.14;

struct shape
{
    double length, width, height, area, radius;
};

void CountDown();
void FizzBuzz();
void RockPaperScissors();
void Mainmenu();
void PickShape();
void HeadsOrTails();
void ConvertTemperature();
int FahrenheitToCelsius(int temperature);
int CelsiusToFahrenheit(int temperature);
void MagicEightBall();

//Shapes

void CalculateTriangleArea(shape * t);
void CalculateRectangleArea(shape * r);
void CalculateSquareArea(shape * s);
void CalculateCircleArea(shape * c);
void CalculateTrapezoidArea(shape * tz);

int main()
{
    shape stats;
    srand( time (NULL) );
    Mainmenu();
}

void FizzBuzz()
{
    for (int i = 0; i < size; i++)
    {
        if (i % 15 == 0)
            cout << "FizzBuzz" << endl;
        else if (i % 5 == 0)
            cout << "Buzz" << endl;
        else if (i % 3 == 0)
            cout << "Fizz" << endl;
        else
            cout << i << endl;
    }

    cout << "FizzBuzz completed. Returning to main menu." << endl;

    CountDown();
}

void RockPaperScissors()
{
    int choice, computer;
    string ctemp, temp;

    cout << "Which one do you choose?" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cin >> choice;
    cin.ignore();

    computer = rand() % 3 + 1;

    // The next two switch statements are used to make the end more specific. Ex, "Your Rock beats the computers Scissors!"

   switch (choice)
   {
    case rock:
        temp = "Rock";
        break;
    case paper:
        temp = "Paper";
        break;
    case scissors:
        temp = "Scissors";
        break;
    default:
        cout << "You should try picking one of the options! Returning to main menu." << endl << endl;
        CountDown();
        break;
   }

   switch (computer)
   {
    case rock:
        ctemp = "Rock";
        break;
    case paper:
        ctemp = "Paper";
        break;
    case scissors:
        ctemp = "Scissors";
        break;
    default:
        cout << "How did the computer get here?" << endl;
        break;
   }

    if ((choice == 1 && computer == 3) || (choice == 2 && computer == 1) || (choice == 3 && computer == 2)) // Check if player won
        cout << "You win! Your " << temp << " beats the computers " << ctemp << "!" << endl;
    else if ((computer == 1 && choice == 3) || (computer == 2 && choice == 1) || (computer == 3 && choice == 2)) // Check if computer won
        cout << "You lose! The computers " << ctemp << " beats your " << temp << "!" << endl;
    else if ((choice == 1 && computer == 1) || (choice == 2 && computer == 2) || (choice == 3 && computer == 3)) // Check if draw.
        cout << "Draw! You and the computer both picked " << temp << "!" << endl;

    CountDown();
}

void Mainmenu()
{
    char input;
    cout << "Welcome to the /g/ programming challenges. Which one would you like to run? " << endl;
    cout << "A. 005. Fizbuzz." << endl;
    cout << "B. 006. Rock Paper Scissors." << endl;
    cout << "C. 033. Area Calculator" << endl;
    cout << "D. 001. Heads Or Tails" << endl;
    cout << "E. 002. Temperature Converter" << endl;
    cout << "F. 013. Magic Eight Ball" << endl;
    cin >> input;
    cin.ignore();

    if (input == 'A' || input == 'a')
        FizzBuzz();
    else if (input == 'B' || input == 'b')
        RockPaperScissors();
    else if (input == 'C' || input == 'c')
        PickShape();
    else if (input == 'D' || input == 'd')
        HeadsOrTails();
    else if (input == 'E' || input == 'e')
        ConvertTemperature();
    else if (input == 'F' || input == 'f')
        MagicEightBall();
}

void PickShape()
{
    shape stats;
    char input;
    cout << "Which shape do you want to calculate the area of? ";
    cout << "A. Triangle" << endl;
    cout << "B. Rectangle" << endl;
    cout << "C. Square" << endl;
    cout << "D. Trapezoid" << endl;
    cout << "E. Circle" << endl;
    cin >> input;
    cin.ignore();

    switch (input)
    {
        case 'A':
            CalculateTriangleArea(&stats);
            break;
        case 'a':
            CalculateTriangleArea(&stats);
            break;
        case 'B':
            CalculateRectangleArea(&stats);
            break;
        case 'b':
            CalculateRectangleArea(&stats);
            break;
        case 'C':
            CalculateSquareArea(&stats);
            break;
        case 'c':
            CalculateSquareArea(&stats);
            break;
        case 'D':
            CalculateTrapezoidArea(&stats);
            break;
        case 'd':
            CalculateTrapezoidArea(&stats);
            break;
        case 'E':
            CalculateCircleArea(&stats);
            break;
        case 'e':
            CalculateCircleArea(&stats);
        default:
            cout << "Pick one of the options above next time!" << endl;
            CountDown();
    }
}

void CalculateTriangleArea(shape * t)
{
    t->area = 0;
    cout << "Enter the triangle base and height amount: " << endl << "Base: ";
    cin >> t->length;
    cout << endl;
    cout << "Height: ";
    cin >> t->height;
    t->area = (t->length * t->height) / 2;
    cout << "The area of the triangle is: " << t->area << "." << endl;
    CountDown();
}

void CalculateRectangleArea(shape * r)
{
    r->area = 0;
    cout << "Enter the rectangle length and width: " << endl << "Length: ";
    cin >> r->length;
    cout << endl;
    cout << "Width: ";
    cin >> r->width;
    r->area = r->length * r->width;
    cout << "The area of the rectangle is: " << r->area << "." << endl;
    CountDown();
}

void CalculateSquareArea(shape * s)
{
    s->area = 0;
    cout << "Enter length of side: ";
    cin >> s->length;
    s->area = s->length * s->length;
    cout << endl;
    cout << "The area of the square is: " << s->area << "." << endl;
    CountDown();
}

void CalculateTrapezoidArea(shape * tz)
{
    tz->area = 0;
    cout << "Enter length of base 1: ";
    cin >> tz->length;
    cout << endl;
    cout << "Enter length of base 2: ";
    cin >> tz->width;
    cout << endl;
    cout << "Enter its height: ";
    cin >> tz->height;
    cout << endl;
    tz->area = ((tz->width + tz->length) * tz->height) / 2;
    cout << "The area of the trapezoid is: " << tz->area << "." << endl;
    CountDown();
}

void CalculateCircleArea(shape * c)
{
    c->area = 0;
    cout << "Enter the circles radius: ";
    cin >> c->radius;
    cout << endl;
    c->area = (c->radius * c->radius) * pi;
    cout << "The area of the circle is: " << c->area << endl;
    CountDown();
}

void CountDown()
{
    for (int i = 3; i > 0; i--)
    {
        cout << i << "..." << endl;
        sleep(1); // Replace with Sleep(1000) if on Windows.
    }

    Mainmenu();
}

void HeadsOrTails()
{
    int Headscount = 0, Tailscount = 0, luck, key;
    cout << "Enter any number to flip the coin! ";

    while (cin >> key)
    {
        if (key == -1)
        {
            cout << "Returning to main menu." << endl;
            CountDown();
        }

        luck = rand() % 2 + 1;

        if (luck == 1)
        {
            cout << "Heads!" << endl;
            Headscount++;
            cout << "Enter any number to flip again! (Enter any letter to quit program) (-1 to go back to menu) " << endl;
            cout << "Score: " << endl << endl;
            cout << "Heads: " << Headscount << "." << endl;
            cout << "______________________________________" << endl;
            cout << "Tails: " << Tailscount << "." << endl;
        }
        else if (luck == 2)
        {
            cout << "Tails!" << endl;
            Tailscount++;
            cout << "Enter any number to flip again! (Enter any letter to quit program) (-1 to go back to menu) " << endl;
            cout << "Score: " << endl << endl;
            cout << "Heads: " << Headscount << "." << endl;
            cout << "______________________________________" << endl;
            cout << "Tails: " << Tailscount << "." << endl;
        }
    }
}

void ConvertTemperature()
{
    char input;
    int Ftemp, Ctemp;
    cout << "Do you want to convert temperature from Fahrenheit to Celsius or vice versa? " << endl;
    cout <<  "A. Fahrenheit to Celsius" << endl;
    cout <<  "B. Celsius to Fahrenheit" << endl;
    cin >> input;

    switch (input)
    {
        case 'A':
            cout << "Enter Temperature (in Fahrenheit): ";
            cin >> Ftemp;
            Ctemp = FahrenheitToCelsius(Ftemp);
            cout << endl << Ftemp << " Fahrenheit = " << Ctemp << " Celsius." << endl;
            CountDown();
            break;
        case 'a':
            cout << "Enter Temperature (in Fahrenheit): ";
            cin >> Ftemp;
            Ctemp = FahrenheitToCelsius(Ftemp);
            cout << endl << Ftemp << " Fahrenheit = " << Ctemp << " Celsius." << endl;
            cout << "Returning to main menu" << endl;
            CountDown();
            break;
        case 'B':
            cout << "Enter temperature: ";
            cin >> Ctemp;
            Ftemp = CelsiusToFahrenheit(Ctemp);
            cout << endl << Ctemp << " Celsius = " <<  Ftemp << " Fahrenheit." << endl;
            CelsiusToFahrenheit(Ctemp);
            cout << "Returning to main menu." << endl;
            CountDown();
            break;
        case 'b':
            cout << "Enter temperature: ";
            cin >> Ctemp;
            Ftemp = CelsiusToFahrenheit(Ctemp);
            cout << endl << Ctemp << " Celsius = " <<  Ftemp << " Fahrenheit." << endl;
            CelsiusToFahrenheit(Ctemp);
            cout << "Returning to main menu" << endl;
            CountDown();
            break;
        default:
            cout << "Try picking one of the options next time! Returning to main menu." << endl;
            CountDown();
            break;
    }
}

int FahrenheitToCelsius(int temperature)
{
    return (temperature - 30) / 2;
}

int CelsiusToFahrenheit(int temperature)
{
    return (temperature * 2) + 30;
}

void MagicEightBall()
{
    string question, answer, status;
    cout << "Enter a question to ask The Magic-8-Ball!" << endl;
    getline(cin, question);
    int random = rand() % 20 + 1;

    switch (random)
    {
        case 1:
            answer = "It is certain.";
            break;
        case 2:
            answer = "It is decidedly so.";
            break;
        case 3:
            answer = "Without a doubt.";
            break;
        case 4:
            answer = "Yes definitely.";
            break;
        case 5:
            answer = "You may rely on it.";
            break;
        case 6:
            answer = "As I see it, yes.";
            break;
        case 7:
            answer = "Most likely.";
            break;
        case 8:
            answer = "Outlook good.";
            break;
        case 9:
            answer = "Yes.";
            break;
        case 10:
            answer = "Signs point to yes.";
            break;
        case 11:
            answer = "Reply hazy try again.";
            break;
        case 12:
            answer = "Ask again later.";
            break;
        case 13:
            answer = "Better not tell you now.";
            break;
        case 14:
            answer = "Cannot predict now.";
            break;
        case 15:
            answer = "Cocentrate and ask again.";
            break;
        case 16:
            answer = "Don't count on it.";
            break;
        case 17:
            answer = "My reply is no.";
            break;
        case 18:
            answer = "My sources say no.";
            break;
        case 19:
            answer = "Outlook not so good.";
            break;
        case 20:
            answer = "Very doubtful.";
            break;
        default:
            CountDown();
            break;
    }

    cout << "The Magic-8-Ball answers: " << answer << endl;
    cout << "Returning to main menu." << endl;
    CountDown();
}
