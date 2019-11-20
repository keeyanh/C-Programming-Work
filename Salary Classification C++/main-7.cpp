#include <iostream>
#include <time.h>
//Keeyan Haghshenas

using namespace std;

int main()
{
    srand(time(NULL));

    const int sp=150;

    double a [sp];

    int ct200;
    int ct300;
    int ct400;
    int ct500;
    int ct600;
    int ct700;
    int ct800;
    int ct900;
    int ct1000;

    for (int i=0; i<sp; i++)
    {
        *(a+i)=rand()%10000;



        
        int b= (*(a+i))*0.09+200;

            if (b>=200 && b<=299 )
                {
                    ct200++;
                 }
                         else if (b>=300 && b<=399 )
                                {
                                         ct300++;
                                }
                                  else if (b>=400 && b<=499 )
                                         {
                                               ct400++;
                                             }
                                          else if (b>=500 && b<=599 )
                                             {
                                                      ct500++;
                                             }
                                                     else if (b>=600 && b<=699 )
                                                         {
                                                                ct600++;
                                                             }
                                                           else if (b>=700 && b<=799 )
                                                              {
                                                                    ct700++;
                                                                  }
                                                                  else if (b>=800 && b<=899 )
                                                                          {
                                                                                  ct800++;
                                                                          }
                                                                          else if (b>=900 && b<=999 )
                                                                             {
                                                                                      ct900++;
                                                                                  }
                                                                                  else if (b>=1000 )
                                                                                      {
                                                                                              ct1000++;
                                                                                          }
    }

    cout<<"Between $200-299: "<<ct200<<endl;
    cout<<"Between $300-399: "<<ct300<<endl;
    cout<<"Between $400-499: "<<ct400<<endl;
    cout<<"Between $500-599: "<<ct500<<endl;
    cout<<"Between $600-699: "<<ct600<<endl;
    cout<<"Between $700-799: "<<ct700<<endl;
    cout<<"Between $800-899: "<<ct800<<endl;
    cout<<"Between $900-299: "<<ct900<<endl;
    cout<<"Between $1000 and over: "<<ct1000<<endl;
}
