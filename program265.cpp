// Accept two numbers(double) from user and return Maximum(specific programming)

#include<iostream>
using namespace std;

double Maximum(double No1, double No2)
{
    double Max;
    
    if(No1 > No2)
    {
        Max = No1;
    }
    else
    {
        Max = No2;
    }
    return Max;
}

int main()
{
    double dValue1 = 10.0, dValue2 = 11.0, dRet = 0.0;

    dRet = Maximum(dValue1, dValue2);
    cout<<"Maximum: "<<dRet<<"\n";   

    return 0;
}