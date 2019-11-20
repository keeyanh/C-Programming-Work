// Course Number and section: 14:332:254:
// Lab Instructor: Kazem
// Date Performed: 04/09/2018
// Date Submitted: 04/09/2018
// Submitted by: Keeyan Haghshenas 171000841

#include "Rational.h"


using namespace std;

#include <iostream>

Rational :: Rational()
{
    numb = 1;
    dem = 2;
}

Rational :: ~Rational()
{



}
void Rational :: setNumer(int NewNum)
{
    numb = NewNum;
}
void Rational ::setDenum( int newNum)
{
   dem = newNum;
}
Rational Rational ::addFrac(Rational frac)
{
    Rational sum;

    if (dem = frac.dem){
        sum.numb = numb + frac.numb;
    } else
    {
        int i = 1;
        while (dem != frac.dem)
        {
            if ((i%dem==0) && (i%frac.dem == 0))
            {
                numb = numb * i / dem;
                frac.numb = frac.numb * i / frac.dem;
                dem = i;
                frac.dem = i;

            }
            i++;

        }

    }
   sum.dem = dem + frac. dem;
    return sum;

}
Rational Rational ::SubFrac(Rational frac)
{
    Rational difference;
    if (dem == frac.dem){
        difference.numb = numb - frac.numb;
    }
    else{
        int i = 1;
        while (dem != frac.dem){
            if ((i%dem==0)&&(i%frac.dem == 0)){
                numb = numb * i/dem;
                frac.numb = frac.numb * i/frac.dem;
                dem = i;
                frac.dem = i;

            }
            i++;
        }
        difference.numb = numb + frac.numb;
        difference.dem = dem + frac. dem;
        return difference;
    }

    return difference;
}

Rational Rational ::multiply(Rational frac) {Rational prod;
    prod.numb = numb * frac.numb;
    prod.dem = dem * frac.dem;
}

void Rational ::PrintFrac() {

    cout << "The rational fraction is " << numb << "/" << dem << endl;

}