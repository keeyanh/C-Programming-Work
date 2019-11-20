#include <iostream>
#include "Rational.h"
int main() {

    Rational firstFrac, secondFrac;
    firstFrac.setDenum((10));
    firstFrac.setNumer(1);

    secondFrac.setNumer(2);
    secondFrac.setDenum(3);

    firstFrac.PrintFrac();
    secondFrac.PrintFrac();

    secondFrac.setNumer(4);
    secondFrac.setDenum(5);

    cout << "The second fraction has changed " << endl;
    secondFrac.PrintFrac();


    Rational sum = firstFrac.addFrac(secondFrac);
    cout << "The Fraction has been added " << endl;

    sum.PrintFrac();

    Rational diff = firstFrac.SubFrac(secondFrac);
    cout << "the fraction has been subtracted " << endl;

    diff.PrintFrac();

    Rational product = firstFrac.multiply(secondFrac);

    product.PrintFrac();


    return 0;
}

