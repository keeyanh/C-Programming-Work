#include "SavingAccount.h"

SavingsAccount :: SavingsAccount(double bal, double rate) {


    bal = 300;
    rate = 1.5;

    balance = bal;
    interestrate = rate;
}

SavingsAccount ::~SavingsAccount() {
}

double SavingsAccount ::calculatedI() {

    double interest = balance * (interestrate/100);
    return interest;


}