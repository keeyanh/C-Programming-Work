#include <iostream>

using namespace std;


class Rational
{

private:
    int numb;
    int dem;

public:
    Rational();
    ~Rational();

    Rational addFrac(Rational);

    Rational SubFrac(Rational);
    Rational multiply(Rational);

    void PrintFrac();
    void setNumer(int);
    void setDenum(int);


};

