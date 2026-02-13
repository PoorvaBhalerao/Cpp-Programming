// write a recursive program to display factors of number
//iteration
//i/p: 10
//o/p:  1   2   5

#include<iostream>
using namespace std;

void DisplayFactors(int iNo)
{
    int iCnt = 0;

    for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            cout<<iCnt<<"\n";
        }
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