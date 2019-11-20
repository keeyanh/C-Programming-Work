

#ifndef KEEYAN_PROJECT_TWO_ACCOUNT_H
#define KEEYAN_PROJECT_TWO_ACCOUNT_H

#include <iostream>

#define DEFAULT_CASH_BALANCE 10000.00

class Account {


public:
    Account();
    double getCashBalance();

    void setCashBalance(double);

private:
    double cashBalance;
};


#endif //KEEYAN_PROJECT_TWO_ACCOUNT_H
