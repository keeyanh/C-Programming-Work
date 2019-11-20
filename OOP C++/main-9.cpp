// Course Number and section: 14:332:254:
// Lab Instructor: Kazem
// Date Performed: 04/09/2018
// Date Submitted: 04/09/2018
// Submitted by: Keeyan Haghshenas 171000841

#include "account.h"


using namespace std;

Account ::Account() {


}


Account ::Account(double) {
    balance = 300;
}


Account ::~Account() {
}


void Account ::credit(double deposit) {


    balance = balance + deposit;
    cout << "The balance is: " << balance << endl;


 }
   void Account :: debit(double withdraw)
   {

    if (withdraw <= balance) {

        balance = balance - withdraw;
        cout << "Your new balance after withdrawl is: " << balance << endl;
    }

    }

double Account ::GetBalance() {

    return balance;

}