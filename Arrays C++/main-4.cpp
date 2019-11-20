 // Lab 1: dice.cpp
 // Keeyan Haghshenas

 #include <iostream>
 using std::cout;
 using std::ios;

#include <iomanip>
 using std::setw;
 using std::setprecision;
 using std::fixed;
 using std::showpoint;

 #include <cstdlib>
 using std::rand;
 using std::srand;

 #include <ctime>
 using std::time;

 int main()
 {
 const long ROLLS = 36000;
 const int SIZE = 13;

 // array exepected contains counts for the expected
 // number of times each sum occurs in 36 rolls of the dice
 /* Write the declaration of array exprected here. Assign an
 initializer list containing the expected values here. Use
 SIZE for the number of elements */


 int x; // first die
 int y; // second die


 /* Write declaration for array sum here. Initialize all
 elements to zero. Use SIZE for the number of elements */
     int Sum[SIZE] = {0};
     int expected[SIZE] = {0,1,2,3,4,5,6,5,4,3,2,1,0}; // possible values from the roll

 srand( time( 0 ) );

 // roll dice 36,000 times
 /* Write a for statement that iterates ROLLS times. Randomly
 generate values for x (i.e., die1) and y (i,e, die2)
 and increment the appropriate counter in array sum that
 corresponds to the sum of x and y */

     // for loop for the rolls
     for(int i=0; i<36000; i++)
     {
         x=rand()%6+1;
         y=rand()%6+1;


         int sum = x+y;

         Sum[sum]++;

     }

 cout << setw( 10 ) << "Sum" << setw( 10 ) << "Total" << setw( 10 )
 << "Expected" << setw( 10 ) << "Actual\n" << fixed << showpoint;


 // display results of rolling dice
 for ( int j = 2; j < SIZE; j++ )
 cout << setw( 10 ) << j << setw( 10 ) << Sum[ j ]
 << setprecision( 3 ) << setw( 9 )
 << 100.0 * expected[ j ] / 36 << "%" << setprecision( 3 )
 << setw( 9 ) << 100.0 * Sum[ j ] / 36000 << "%\n";


 return 0; // indicates successful completion
 } // end main