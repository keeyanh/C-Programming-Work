
#ifndef PROGRAMMINGMETHODPROJECTFINAL_HF_H
#define PROGRAMMINGMETHODPROJECTFINAL_HF_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

using namespace ::std;

enum State {
    EMPTY,
    MAKE_ACC,
    DEPOSIT_ACCOUNT,
    WITHDRAW_ACCOUNT,
    TRANSFER,
    PRINT_ACCOUNT,
    ACTIVE_DEACTIVE,
    DELETE_ACCOUNT,
    PRINT_ACCOUNTS,
    QUIT
};

struct Account {
    int accountNumber;
    string lastName;
    string firstName;
    double accountBalance;
    bool active;
};

vector<Account> bankAccounts;

void makeAccount();

void printAllAccounts();

void depositAccount();

void withdrawAccount();

void printAccount(Account);

void deleteAccount();

int findAccount(unsigned long);

void activeDeactive();

void transfer();

void menu();


#endif 

