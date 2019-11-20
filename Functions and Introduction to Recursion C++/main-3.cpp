// Lab 3: gcd.cpp
 // Finds greatest common divisor (GCD) of 2 inputs.
 #include <iostream>
#include "GCD.h"

 using std::cin;
 using std::cout;
 using std::endl;

/* Write prototype for gcd */
 int main()
 {
 int a; // first number
 int b; // second number

 // loop for 5 pairs of inputs
 for ( int j = 1; j <= 5; j++ )
 {
 cout << "Enter two integers: ";
 cin >> a >> b;

 cout << "The greatest common divisor of "
 << a << " and " << b << " is ";

 // find greatest common divisor of a and b
 cout << GCD(a,b) << endl;
 } // end for

 return 0; // indicate successful termination
 } // end main

int GCD(int a, int b) {
    int greatest = 1; // current greatest common divisor, 1 is minimum


// loop from 2 to smaller of x and y
    for (int i = 2; i <= ((a < b) ? a : b); i++)

    {
// if current i divides both x and y
        if (a % i == 0 && b % i == 0)
        {
            greatest = i; // update greatest common divisor
        }// end for

    }
    return greatest;
}
