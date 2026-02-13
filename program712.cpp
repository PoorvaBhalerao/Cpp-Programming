// write a recursive program to display factors of number
//recursion
//i/p: 10
//o/p:  1   2   5

#include<iostream>
using namespace std;

void DisplayFactors(int iNo)
{
    static int iCnt = 1;
   
    if(iCnt <= (iNo/2))
    {
        if(iNo % iCnt == 0)
        {
            cout<<iCnt<<"\n";
        }
        iCnt++;
        DisplayFactors(iNo);
    }
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter a number: ";
    cin>>iValue;
    
    DisplayFactors(iValue);

    return 0;
}