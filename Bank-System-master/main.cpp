
#include "hf.h"

int main() {
    menu();
    cout << "The bank is closed" << endl;
    return 0;
}

void menu() {
    State state;
    for (;;) {

        do {
            cout << "Welcome! Select options below:"
                    "\n1. Make new account->"
                    "\n2. Deposit to an account->"
                    "\n3. Withdraw from an account->"
                    "\n4. Transfer Money from one account to another."
                    "\n5. Print account->"
                    "\n6. Activate/Deactivate an account->"
                    "\n7. Delete an account->"
                    "\n8. Display all accounts."
                    "\n9. Quit."
                    "\n\nSelection:"
                 << endl;
            scanf("%d", &state);
        } while (state < 0 || state > DELETE_ACCOUNT);

        switch (state) {
            case MAKE_ACC:
                makeAccount();
                break;
            case PRINT_ACCOUNTS:
                printAllAccounts();
                break;
            case DEPOSIT_ACCOUNT:
                depositAccount();
                break;
            case WITHDRAW_ACCOUNT:
                withdrawAccount();
                break;
            case TRANSFER:
                transfer();
                break;
            case ACTIVE_DEACTIVE:
                activeDeactive();
                break;
            case PRINT_ACCOUNT:
                unsigned long accountNumber;
                int position;

                do {
                    cout << "Enter the account number to print: " << endl;
                    cin >> accountNumber;

                    position = findAccount(accountNumber);
                } while (position == -1);

                printAccount(bankAccounts.at(position));
                break;
            case DELETE_ACCOUNT:
                deleteAccount();
                break;
            case QUIT:
                return;
        }
    }
}

void transfer() {
    unsigned long senderAccNumber;
    int position = -1;

    do {
        cout << "Enter the account number for the sender: " << endl;
        cin >> senderAccNumber;

        position = findAccount(senderAccNumber);
    } while (position == -1);


    unsigned long recieveAccNumber;
    do {
        cout << "Enter the account number for the reciever: " << endl;
        cin >> recieveAccNumber;

        position = findAccount(recieveAccNumber);
    } while (position == -1);

    Account* senderAccount = &bankAccounts.at(position);
    Account* recieveAccount = &bankAccounts.at(position);


    if (senderAccNumber == recieveAccNumber) {
        cout << "You cannot transfer to the same account!" << endl;
        return;
    }

    double transferAmount;

    do {
        cout << "Enter the account to transfer: " << endl;
        cin >> transferAmount;
    } while (transferAmount < 0);

    if (transferAmount > senderAccount->accountBalance) {
        cout << "Transfer amount is greater than balance of " << senderAccount->accountBalance << endl;
        return;
    }

    senderAccount->accountBalance -= transferAmount;
    recieveAccount->accountBalance += transferAmount;

}

void activeDeactive() {
    unsigned long accountNumber;
    int position;
    do {
        cout << "Enter the account number to active/de-active : " << endl;
        cin >> accountNumber;

        position = findAccount(accountNumber);
    } while (position == -1);

    Account* account = &bankAccounts.at(position);
    account->active = !account->active;
    cout << "The account is now: " << (account->active ? "Active" : "Deactivated") << endl;
}

void deleteAccount() {
    unsigned long accountNumber;

    cout << "Enter the account number to delete : " << endl;
    cin >> accountNumber;

    int position = findAccount(accountNumber);
    if (position == -1) {
        cout << "Account could not be found." << endl;
        return;
    }

    bankAccounts.erase(bankAccounts.begin() + position);

    cout << "Account has been successfully delete" << endl;
}

void printAccount(Account acc) {
    cout << "Account number: " << acc.accountNumber << "\tBalance: " << acc.accountBalance << endl;
    cout << "Last name: " << acc.lastName << "\tFirst name: " << acc.firstName;
}

void withdrawAccount() {
    unsigned long accountNumber;
    int position;

    do {
        cout << "Enter account number for withdraw: " << endl;
        cin >> accountNumber;

        position = findAccount(accountNumber);
    } while (position == -1);

    double withdrawlAmount;
    do {
        cout << "Enter amount to be withdraw: " << endl;
        cin >> withdrawlAmount;
    } while (withdrawlAmount < 0);

    Account* account = &bankAccounts.at(position);

    if (withdrawlAmount > account->accountBalance)
        withdrawlAmount = account->accountBalance;

    account->accountBalance -= withdrawlAmount;

    cout << "Withdrawl has been complete for account " << account->firstName << " " << account->lastName << ". Balance: " << account->accountBalance << "Withdrew: " << withdrawlAmount << endl;
}

void depositAccount() {
    unsigned long accountNumber;
    int position;

    do {
        cout << "Enter account number for deposit: " << endl;
        cin >> accountNumber;

        position = findAccount(accountNumber);
    } while (position == -1);

    int depositAmount;
    do {
        cout << "Enter amount to be deposited: " << endl;
        cin >> depositAmount;
    } while (depositAmount < 0);
    Account* account = &bankAccounts.at(position);

    account->accountBalance += depositAmount;
    cout << "Deposit has been complete for account " << account->firstName << " " << account->lastName << ". Balance: " << account->accountBalance << endl;

}

void printAllAccounts() {
    cout << "\nPrinting all accounts" << endl;
    for (int index = 0; index < bankAccounts.size(); index++) {
        Account acc = bankAccounts.at(index);

        printAccount(acc);
    }
}

void makeAccount() {
    Account account;

    cout << "Enter first name" << endl;
    cin >> account.firstName;

    cout << "Enter last name" << endl;
    cin >> account.lastName;

    account.accountNumber = (rand() % 9000) + 1;

    account.accountBalance = 0;
    account.active = true;

    cout << "Congradulations " << account.firstName << " " << account.lastName << ". You're account "
         << account.accountNumber << " has been successfully created." << endl;

    bankAccounts.push_back(account);
}

int findAccount(unsigned long accountNumber) {
    for (int index = 0; index < bankAccounts.size(); index++) {
        Account acc = bankAccounts.at(static_cast<unsigned long>(index));
        if (acc.accountNumber == accountNumber) {
            return index;
        }
    }
    return -1;
}