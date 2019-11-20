

#ifndef KEEYAN_PROJECT_TWO_BANKACCOUNT_H
#define KEEYAN_PROJECT_TWO_BANKACCOUNT_H

#include <vector>
#include "Account.h"

using namespace std;

enum BankTransactionType {
    WITHDRAWN, DEPOSITED
};

class Transaction {
public:
    Transaction(BankTransactionType type, double amount, double currentBalance);

    BankTransactionType getType();

    double getAmount();

    double getCurrentBalance();

private:
    BankTransactionType type;
    double amount, currentBalance;
};


class BankAccount : public Account {
public:
    BankAccount();

    vector<Transaction> history;
};




#endif //KEEYAN_PROJECT_TWO_BANKACCOUNT_H
