#include <iostream>
using std :: cout;
using std :: cin;
using std :: endl;


int main()
{

    int inputnumber;
    int sum = 0;
    int x;

    cout << "Enter a number please!" << endl;

    cin >> inputnumber ;

    for ( x = 1; x < inputnumber; x = x+1) {
        if (inputnumber % x == 0) {
            sum = sum + x;
        }
    }
        if (inputnumber == sum)
        {
            cout << "This number is a perfect number" << endl;
        }
        else {
            cout << "This number is not a perfect number" << endl;
        }
    return 0;
}