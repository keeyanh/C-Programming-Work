#include <iostream>
#include <fstream>

#include "StockAccount.h"
#include "BankAccount.h"

#define DELIM "\t"

void startBankMenu();

void startStockMenu();

Stock *findStock(string symbol);

double findPrice(string symbol);

void saveStockHistory();

void saveBankHistory();

using namespace std;

static StockAccount stockAccount;
static BankAccount bankAccount;

void startMenu() {
    int option = -1;

    do {
        cout << "Please select one of the following options." << endl;

        cout << "1) Stock Account" << endl;
        cout << "2) Bank Account" << endl;
        cout << "3) Quit Program" << endl;

        cout << "Your selection: ";

        cin >> option;


        switch (option) {
            case 1:
                startStockMenu();
                break;
            case 2:
                startBankMenu();
                break;
            case 3:
                saveStockHistory();
                saveBankHistory();
                cout << "\nExiting program....." << endl;
                exit(0);
                return;
        }

    } while (option != 3);

}

void saveBankHistory() {
    ofstream out ("bank_transaction_history.txt");
    out.clear();

    out << "Action\tAmount\tCash\tBalance\tDate\tTime" << endl;
    for (Transaction history : bankAccount.history) {
        out << (history.getType() == WITHDRAWN ? "Withdrawl" : "Deposit") << "\t" << history.getAmount()
             << "\t" << history.getCurrentBalance() << endl;
    }

    out.close();
}

void saveStockHistory() {
    ofstream out ("stock_transaction_history.txt");
    out.clear();

    out << "Symbol\tCompany\t\t\tNumber\tPrice\tTotal" << endl;

    double portfolioValue = 0.0;
    for (Stock stock : stockAccount.portfolio) {
        double price = findPrice(stock.getSymbol());

        double totalPrice = stock.getShares() * price;
        out << stock.getSymbol() << "\t" << stock.getCompany() << "\t" << stock.getShares() << "\t"
             << price << "\t" << totalPrice << endl;

        portfolioValue += totalPrice;
    }

    out << endl << "Total portfolio value: $" << portfolioValue << endl;

    out.close();
}

void startBankMenu() {
    int option = -1;

    do {
        cout << "Please select one of the following options." << endl;

        cout << "1) Display current cash balance" << endl;
        cout << "2) Deposit to account" << endl;
        cout << "3) Withdraw from account" << endl;
        cout << "4) Display transactions history" << endl;
        cout << "5) Return to main menu" << endl;

        cout << "Your selection: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Current balance: " << bankAccount.getCashBalance() << endl;
                break;
            case 2:
                double depositAmount;
                do {
                    cout << "Enter amount to be deposited: " << endl;
                    cin >> depositAmount;
                } while (depositAmount < 0);


                if (depositAmount > stockAccount.getCashBalance()) {
                    depositAmount = stockAccount.getCashBalance();
                } else if (depositAmount == 0) {
                    cout << "Insufficient funds in stock account" << endl;
                } else {
                    stockAccount.setCashBalance(stockAccount.getCashBalance() - depositAmount);
                    bankAccount.setCashBalance(bankAccount.getCashBalance() + depositAmount);

                    bankAccount.history.push_back(
                            *new Transaction(DEPOSITED, depositAmount, bankAccount.getCashBalance()));
                }
                break;
            case 3: {
                double withdrawlAmount;
                do {
                    cout << "Enter amount to be withdraw: " << endl;
                    cin >> withdrawlAmount;
                } while (withdrawlAmount < 0);

                if (withdrawlAmount > bankAccount.getCashBalance())
                    withdrawlAmount = bankAccount.getCashBalance();

                bankAccount.setCashBalance(bankAccount.getCashBalance() - withdrawlAmount);
                stockAccount.setCashBalance(stockAccount.getCashBalance() + withdrawlAmount);

                bankAccount.history.push_back(
                        *new Transaction(WITHDRAWN, withdrawlAmount, bankAccount.getCashBalance()));

                cout << withdrawlAmount << " has been withdrawn. Remaining balance: "
                     << bankAccount.getCashBalance() << endl;
                break;
            }

            case 4:
                cout << "Action\tAmount\tCash\tBalance\tDate\tTime" << endl;
                for (Transaction history : bankAccount.history) {
                    cout << (history.getType() == WITHDRAWN ? "Withdrawl" : "Deposit") << "\t" << history.getAmount()
                         << "\t" << history.getCurrentBalance() << endl;
                }
                break;
            case 5:
                startMenu();
                return;
        }

    } while (option != 5);
}

void startStockMenu() {
    int option = -1;

    do {
        cout << "Please select one of the following options." << endl;

        cout << "1) Display current price for a stock symbol" << endl;
        cout << "2) Buy stock" << endl;
        cout << "3) Sell stock" << endl;
        cout << "4) Display current portfolio" << endl;
        cout << "5) Display transactions history" << endl;
        cout << "6) Return to main menu" << endl;

        cout << "Your selection: ";
        cin >> option;

        string symbol = "";
        Stock *stock;
        int shares;
        double price;

        switch (option) {
            case 1: // Takes a stock's symbol and display's the price
            {
                cout << "Enter stock symbol for checking price." << endl;
                cout << "Symbol: ";

                cin >> symbol;
                stock = findStock(symbol);
                price = findPrice(symbol);

                cout << endl << stock->getSymbol() << "\t" << stock->getCompany() << "\t\t" << price << endl << endl;
            }
                break;
            case 2: {// Buy a random stock?
                cout << "Enter stock symbol: ";
                cin >> symbol;

                cout << "Enter shares: ";
                cin >> shares;

                cout << "Enter price to purchase: ";
                cin >> price;

                stock = findStock(symbol);
                double stockPrice = findPrice(symbol);
                if (stock->getCompany().empty())
                    cout << "Could not find the stock." << endl;
                else if (shares <= 0) {
                    cout << "Invalid share count" << endl;
                } else if (price < stockPrice) {
                    cout << "Could not purchase stock for " << price << ", being sold for " << stockPrice << endl;
                } else if (stockAccount.getCashBalance() < (price * shares)) {
                    cout << "Not enough funds available to purchase!" << endl;
                } else {
                    Stock *active = NULL;
                    bool found = false;
                    for (int index = 0; index < stockAccount.portfolio.size(); index++) {
                        active = &stockAccount.portfolio.at(index);
                        if (active->getSymbol() != symbol)
                            continue;
                        found = true;
                        break;
                    }

                    stockAccount.setCashBalance(stockAccount.getCashBalance() - (price * shares));

                    if (!found) {
                        stock->setShares(stock->getShares() + shares);
                        stockAccount.portfolio.push_back(*stock);
                        stockAccount.history.push_back(
                                *new StockHistory(BOUGHT, shares, stock->getCompany(), symbol));
                    } else {
                        active->setShares(active->getShares() + shares);
                        stockAccount.history.push_back(
                                *new StockHistory(BOUGHT, shares, active->getCompany(), symbol));
                    }


                }
            }


                break;
            case 3: // Sell a random stock?
            {
                cout << "Enter stock symbol: ";
                cin >> symbol;

                cout << "Enter shares: ";
                cin >> shares;

                cout << "Enter price to sell: ";
                cin >> price;

                Stock *active = NULL;
                int activePosition = 0;
                bool found = false;
                for (int index = 0; index < stockAccount.portfolio.size(); index++) {
                    active = &stockAccount.portfolio.at(index);
                    if (active->getSymbol() != symbol)
                        continue;
                    activePosition = index;
                    found = true;
                    break;
                }

                if (!found) {
                    cout << "Could not find stock." << endl;
                } else {
                    double stockPrice = findPrice(symbol);
                    double totalPrice = price * shares;
                    if (price >= stockPrice) {
                        cout << "Could not complete transaction" << endl;
                    } else if (active->getShares() < shares) {
                        cout << "Not enough shares to sell!" << endl;
                    } else {
                        stockAccount.setCashBalance(stockAccount.getCashBalance() + totalPrice);
                        stockAccount.history.push_back(
                                *new StockHistory(SOLD, active->getShares(), active->getCompany(),
                                                  active->getSymbol()));

                        active->setShares(active->getShares() - shares);

                        if (active->getShares() == 0) {
                            stockAccount.portfolio.erase(stockAccount.portfolio.begin() + activePosition);
                        }
                    }
                }
            }
                break;
            case 4: // Display the stocks that you currently own.
            {
                cout << "Cash balance: " << stockAccount.getCashBalance() << endl << endl;
                cout << "Symbol\tCompany\t\t\tNumber\tPrice\tTotal" << endl;

                double portfolioValue = 0.0;
                for (Stock stock : stockAccount.portfolio) {
                    price = findPrice(stock.getSymbol());

                    double totalPrice = stock.getShares() * price;
                    cout << stock.getSymbol() << "\t" << stock.getCompany() << "\t" << stock.getShares() << "\t"
                         << price << "\t" << totalPrice << endl;

                    portfolioValue += totalPrice;
                }

                cout << endl << "Total portfolio value: $" << portfolioValue << endl;
            }
                break;
            case 5: // Display your stock purchase/history
            {
                cout << "Action\tSymbol\tShares\tPrice\tTime" << endl;

                for (StockHistory history : stockAccount.history) {
                    double price = findPrice(history.getSymbol());

                    cout << (history.getType() == BOUGHT ? "Buy" : "Sell") << "\t" << history.getSymbol() << "\t"
                         << history.getShares() << "\t" << price << "\t";
                }
            }

                break;
            case 6: // Return to the main menu
                startMenu();
                return;
        }

    } while (option != 6);
}

Stock *findStock(string symbol) {
    char buffer[19];
    srand(static_cast<unsigned int>(time(NULL)));

    sprintf(buffer, "./stocks/stock%d.txt", rand() % 4 + 1);

    ifstream file(buffer);
    string line;
    vector<string> tokens;
    while (getline(file, line)) {
        for (int i = 0; i < 3; i++) {
            if (i == 2) { // handling newline character
                line = line.substr(line.rfind(DELIM) + 1, string::npos);
                line.resize(line.length() - 1); // remove newline

                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(DELIM)));
            line = line.substr(line.find(DELIM) + 1, string::npos);
        }

        if (tokens.at(0) == symbol)
            break;

        tokens.clear();
    }

    file.close();

    return new Stock(0, tokens.empty() ? "" : tokens.at(1), symbol);
}

double findPrice(string symbol) {
    char buffer[2048];
    srand(static_cast<unsigned int>(time(NULL)));

    sprintf(buffer, "./stocks/stock%d.txt", rand() % 4 + 1);

    ifstream file(buffer);
    string line;
    vector<string> tokens;
    while (getline(file, line)) {
        for (int i = 0; i < 3; i++) {
            if (i == 2) { // handling newline character
                line = line.substr(line.rfind(DELIM) + 1, string::npos);
                line.resize(line.length() - 1); // remove newline

                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(DELIM)));
            line = line.substr(line.find(DELIM) + 1, string::npos);
        }

        if (tokens.at(0).compare(symbol) == 0)
            break;

        tokens.clear();
    }

    file.close();

    return tokens.empty() ? -1.0 : stod(tokens.at(2));

}

int main() {
    startMenu();
    return 0;
}
