 // Lab 2: bubblesort.cpp // This program sorts an array's values into ascending rder.
 #include <iostream>
 using std::cout;
 using std::endl;

#include <iomanip>
 using std::setw;

 int main()
 {
 const int arraySize = 10; // size of array a
 int a[ arraySize ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
 int hold; // temporary location used to swap array elements

 cout << "Data items in original order\n";

 // output original array
 for ( int i = 0; i < arraySize; i++ )
 cout << setw( 4 ) << a[ i ];

 // bubble sort
 // loop to control number of passes
 /* Write a for header to loop for one iteration less than the size
 of the array */
 {
 // loop to control number of comparisons per pass
 /* Write a for header to iterate j from 0 and keep
 looping while j is less than arraySize - 1 */
 {
 // compare side-by-side elements and swap them if
 // first element is greater than second element
 /* Write an if statement to test if element j is greater than
 element j + 1 */
 {
 /* Write code to swap the values in element j and
 element j + 1, using hold as temporary storage */
 } // end if
 } // end for
 } // end for

 cout << "\nData items in ascending order\n";

 // output sorted array
 for ( int k = 0; k < arraySize; k++ )
 cout << setw( 4 ) << a[ k ];

 cout << endl;
 return 0; // indicates successful termination
 } // end main