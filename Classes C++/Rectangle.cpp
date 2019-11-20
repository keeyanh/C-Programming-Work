
// Course Number: 14:332:254
// Lab Instructor: Kazem Cheshmi
// Date Performed: 04/02/2018
// Date Submitted: 04/02/2018
// Submitted by: Keeyan Haghshenas, 171000841
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include "Rectangle.h"


using namespace ::std;

void Rectangle :: Rectangle()
{
    x1 = x2= x3= x4 = y1= y2= y3=y4;

}

Rectangle ::setCorners(float firstcornex,float firstcornery, float secondcornerx, float secondcornery, float thirdcornerx, float thirdconery, float fourthcornerx, float fourthcornery){




    x1 = firstcornex;

    y1 = firstcornery;

    x2 = secondcornerx;
    y2 = secondcornery;

    y3 = thirdconery;
    x3 = thirdcornerx;

    x4 = fourthcornerx;

    y4 = fourthcornery;

}

int Rectangle ::Perimeter()
{
   p = (x2-x1) + (x3-x4) + (y1 -y4 ) + (y2 - y3);

}

int Rectangle ::Width() {

    w = (x4 - x3) || (x1 - x2);

}

int Rectangle ::length() {


    if ((x2 - x1) > (y2 - y3)){
        l = (x2-x1);
    }
    else{
        l = (y2 -y3);

    }
}

int Rectangle ::Area() {
    a = l * w;

}

void Rectangle :: printCorners() {

    cout << "The first corner is" <<  x1 << "." << y1 << endl;
    cout << "The second corner is" <<  x2 << "." << y2 << endl;
    cout << "The third corner is" <<  x3 << "." << y3 << endl;
    cout << "The fourth corner is" <<  x4 << "." << y4 << endl;

}