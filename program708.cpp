// write a recursive program to display sum of number of digits
//Recursion
//i/p: 7891
//o/p:  25 

#include<iostream>
using namespace std;

int SumDigits(int iNo)
{
    static int iSum = 0;
    int iDigit = 0;

    if(iNo > 0)
    {
        iDigit= iNo % 10;
        iSum = iSum + iDigit;
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

    cout<<"Sum of digits are: "<<iRet<<"\n";

    return 0;
}