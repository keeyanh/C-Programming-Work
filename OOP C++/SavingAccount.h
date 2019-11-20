#include "account.h"

class SavingsAccount : public Account
{

protected:
    double interestrate;

public:
     SavingsAccount(double, double);

    ~SavingsAccount();



    double calculatedI();


};

