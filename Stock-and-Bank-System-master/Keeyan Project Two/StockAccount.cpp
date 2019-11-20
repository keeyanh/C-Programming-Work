

#include "StockAccount.h"

StockHistory::StockHistory(StockTransactionType, int shares, string company, string symbol) {
    this->type = type;
    this->shares = shares;
    this->company = company;
    this->symbol = symbol;
}

StockTransactionType StockHistory::getType() {
    return this->type;
}

string StockHistory::getSymbol() {
    return this->symbol;
}

string StockHistory::getCompany() {
    return this->company;
}

time_t StockHistory::getTimer() {
    return this->timer;
}

int StockHistory::getShares() {
    return this->shares;
}


Stock::Stock(int shares, string company, string symbol) {
    this->shares = shares;
    this->company = company;
    this->symbol = symbol;
}

Stock::Stock() {
    this->shares = 0;
    this->company = "";
    this->symbol = "";
}

string Stock::getSymbol() {
    return this->symbol;
}

int Stock::getShares() {
    return this->shares;
}

string Stock::getCompany() {
    return this->company;
}

void Stock::setShares(int shares) {
    this->shares = shares;
}


StockAccount::StockAccount() {

}