

#include "BankAccount.h"

BankTransactionType Transaction::getType() {
    return this->type;
}

double Transaction::getAmount() {
    return this->amount;
}

double Transaction::getCurrentBalance() {
    return this->currentBalance;
}

Transaction::Transaction(BankTransactionType type, double amount, double currentBalance) {
    this->type = type;
    this->amount = amount;
    this->currentBalance = currentBalance;
}


BankAccount::BankAccount() {

}
