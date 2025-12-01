// Accept two numbers(float) from user and return Maximum(specific programming)

#include<iostream>
using namespace std;

int Maximum(int No1, int No2)
{
    int Max;
    
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
    int iValue1 = 10, iValue2 = 11, iRet = 0;
    
    iRet = Maximum(iValue1, iValue2);
    cout<<"Maxmimum: "<<iRet<<"\n";

    return 0;
}