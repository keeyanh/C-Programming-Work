#include <iostream>
//Keeyan Haghshenas
using std::cout;
using std::endl;
using std::cin;
using namespace std;

int main() {


    int year;
    int month;




    std::cout << "Please Input Year ";
    std::cin >> year;

    if (year % 4 == 0)

    {


    cout << "This year is a leap year and ";
        cout << "There are 366 days in this year \n";


    }


    else

    {


       cout << "This year is not a leap year and ";
        cout << "There are 365 days in this year \n";

    }

cout << "Please input month ";
    cin >> month;

        switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:

                cout << "There are 31 days in this month";
                break;

            case 4:
            case 6:
            case 9:
            case 11:

                cout << "There are 30 days in this month";
                break;


            case 2:
                if ((year % 4 == 0 && month == 2))

                {

                    cout << "This month has 29 days ";



                }


                else

                {
                    cout << "This month has 28 days";


                }


break ;



    }


    return 0;

}




