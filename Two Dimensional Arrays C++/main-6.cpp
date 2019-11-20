#include <iostream>
#include <iomanip>

using namespace std;


int main() {

    string issues[5] = {"Immigration","Global Warming","Guns","Health Care","Economy"};
    int i,j;
    int response[5][10];
    int sum = 0;
    int highest = 0;
    int highesttot = INT_MIN;
    int lowest = 0;
    int lowesttot = INT_MAX;

    for(i=0;i<5;i++)
    {
        cout <<"rate " << i+1 <<"th issue from 1 to 10\n";
        cin >> rate;
        if(rate >=1 && rate <=10)
        {
            response[i][rate-1] += rate;
            count[i][rate-1]++;
        }

    for(i=0;i<5;i++){
        for(j=1;j<=10;j++) {
            sum = j * response[i][j] + sum;
        }
        response[j][0]=sum/100;

        if(sum > highest) {
            highest = j;
            highesttot = sum;
        }
        if(sum < lowest){
            lowest = j;
            lowesttot = sum;
        }
        sum = 0;
    }
    cout<<"The Responses of the 100 people who entered the survey"<<endl<<"Issue:"<<setw(20);

    for(i=1; i<= 10; i++){
        cout<<i<<setw(20);
    }
    cout<<"Average"<<endl;
    for(i=0;i<5;i++) {
        cout << issues[j] << setw(20);
    }
    for(j=1;j<=10;j++){
        cout<<response[i][j]<<setw(20);
    }
    cout<<response[j][0]<<endl;

    cout << "The highest total is"<<issues[highest] << " " << highesttot << endl;
    cout << "The lowest total is"<<issues[lowest] << " " << lowesttot << endl;

    return 0; }