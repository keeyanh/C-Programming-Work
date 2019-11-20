

#ifndef KEEYAN_PROJECT_TWO_STOCKACCOUNT_H
#define KEEYAN_PROJECT_TWO_STOCKACCOUNT_H

#include <vector>
#include <string>
#include <ctime>

#include "Account.h"

using namespace std;

enum StockTransactionType {
    BOUGHT, SOLD
};

class StockHistory {


public :
    StockHistory(StockTransactionType, int, string, string);

    StockTransactionType getType();

    string getSymbol();

    string getCompany();

    int getShares();

    time_t getTimer();

private:
    StockTransactionType type;
    int shares;
    string symbol, company;
    time_t timer;
};

class Stock {

public:
    Stock();

    int getShares();
    string getSymbol();
    string getCompany();

    Stock(int, string, string);

    void setShares(int i);

private:
    int shares;
    string symbol, company;
};

class StockAccount : public Account {



public:
    StockAccount();

    vector<StockHistory> history;
    vector<Stock> portfolio;
};





#endif //KEEYAN_PROJECT_TWO_STOCKACCOUNT_H
