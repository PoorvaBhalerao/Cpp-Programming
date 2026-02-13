// write a recursive program as following
//i/p: 5
//o/p:  1   2   3   4   5

#include<iostream>
using namespace std;

void Display(int iNo)
{
    static int iCnt = 1;

    if(iCnt <= iNo)
    {
        cout<<iCnt<<"\t";
        iCnt++;
        Display(iNo);
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