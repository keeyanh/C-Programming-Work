#include "SavingAccount.h"

using namespace std;


int main ()
{

    Account acc(5);
    SavingsAccount savings(9,15);

    cout << "What is in your regular account: " << endl;
    acc.credit(60);


    cout << "What is in your savings Account: " << endl;
    savings.credit(110);


    cout << 'The Regular Account: ' << endl;
    acc.debit(85);

    cout << "The saving account: " << endl;
    savings.debit(210);




   double interest = savings.calculatedI();
    cout << "the interest is: " << interest << endl;

    double accbal = acc.GetBalance();
    cout << "regular account balance: " << accbal << endl;



     acc.GetBalance();
   savings.GetBalance();


double svbal = savings.GetBalance();
    cout << "Saving account balance: " << svbal << endl ;

double profit = svbal + interest;
    cout << "saving account balance with interest: " << profit<<  endl;


    return 0;


}

