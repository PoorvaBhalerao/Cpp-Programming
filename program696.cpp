// write a recursive program as following....
//recursion used
//i/p: 5
//o/p:  5   4   3   2   1   

#include<iostream>
using namespace std;

void Display(int iNo)
{
    if(iNo >= 1)
    {
        cout<<iNo<<"\t";
        Display(iNo-1);             
    }
    else
    {
        cout<<"\n";
    }
}

int main()
{
    int iValue = 0;

    cout<<"Enter a number: ";
    cin>>iValue;

    Display(iValue);

    return 0;
}