
#include "Account.h"

using namespace std;

Account::Account() {
    cashBalance = DEFAULT_CASH_BALANCE;
}

double Account::getCashBalance() {
    return cashBalance;
}

void Account::setCashBalance(double accountBalance) {
    this->cashBalance = accountBalance;
}


