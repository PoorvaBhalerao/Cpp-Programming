// write a recursive program to display sum factors of number
//recursion
//i/p: 10
//o/p:  (1   2   5)=> 8

#include<iostream>
using namespace std;

int SumFactors(int iNo)
{
    static int iSum = 0;
    static int iCnt = 1;
   
    if(iCnt <= (iNo/2))
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
        iCnt++;
        SumFactors(iNo);
    }

    return iSum;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter a number: ";
    cin>>iValue;
    
    iRet = SumFactors(iValue);

    cout<<"Sum of factors of number is:"<<iRet<<"\n";

    return 0;
}