// write a recursive program as following....
//iteration used
//i/p: 5
//o/p:  1   2   3   4   5

#include<iostream>
using namespace std;

void Display(int iNo)
{
    int iCnt = 0;
    iCnt = 1;
    while(iCnt <= iNo)
    {
        cout<<iCnt<<"\t";
        iCnt++;
    }
    cout<<"\n";
}

int main()
{
    int iValue = 0;

    cout<<"Enter a number: ";
    cin>>iValue;

    Display(iValue);

    return 0;
}