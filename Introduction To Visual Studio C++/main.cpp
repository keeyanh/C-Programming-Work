//Programming Methodologies Lab
// Lab A - Introduction to Microsoft Visual Studio C++ 2003
//Keeyan Haghshenas
//Section 3
//January 22, 2018


#include <iostream> // allows program to perform input and output

using std::cout; // program uses cout
using std::endl; // program uses endl
using std::cin; // program uses cin

int main()
{
    int number1; // first integer read from user
    int number2; // second integer read from user
    int number3; // third integer read from user
    int number4; // fourth integer read from user
    int smallest; // smallest integer read from user
    int largest; // largest integer read from user

    cout << "Input first integer: "; // prompt
    cin >> number1; // read an integer
    cout << "Input second integer: "; // prompt
    cin >> number2; // read a second integer
    cout << "Input third integer: "; // prompt
    cin >> number3; // read a third integer
    cout << "Input fourth integer: "; //prompt
    cin >> number4; //read an integer

    largest = number1; // assume first integer is largest

    if ( number2 > largest ) // is number2 larger?
        largest = number2; // number2 is now the largest

    if ( number3 > largest ) // is number3 larger?
        largest = number3; // number3 is now the largest

    if ( number4 > largest ) // is number4 larger?
        largest = number4; // number4 is now the largest

    smallest = number1; // assume first integer is smallest

    if ( number2 < smallest ) // is number2 smaller?
        smallest = number2; // number2 is now the smallest

    if ( number3 < smallest ) // is number3 smaller?
        smallest = number3; // number3 is now the smallest

    if ( number4 < smallest ) // is number4 smaller?
        smallest = number4; // number4 is now the smallest


    cout << "Sum is " << number1 + number2 + number3 + number4
         << "\nAverage is " << ( number1 + number2 + number3 + number4 ) / 4
         << "\nProduct is " << number1 * number2 * number3 * number4
         << "\nSmallest is " << smallest
         << "\nLargest is " << largest << endl;

    return 0; // indicate successful termination

} // end main
