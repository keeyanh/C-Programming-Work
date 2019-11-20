#include <iostream>


class Account
{

protected:
    double balance;

public:

    Account();

    Account(double);
    ~Account();

    void credit(double);

    void debit(double);

    double GetBalance();

};