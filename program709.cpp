// write a recursive program to display sum of number of digits
//Recursion
//i/p: 7891
//o/p:  25 

#include<iostream>
using namespace std;

int SumDigits(int iNo)
{
    static int iSum = 0;

    if(iNo > 0)
    {
        iSum = iSum + (iNo % 10);
        SumDigits(iNo / 10);
    }
    return iSum;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter a number: ";
    cin>>iValue;
    
    iRet = SumDigits(iValue);

    cout<<"Summation of digits are: "<<iRet<<"\n";

    return 0;
}