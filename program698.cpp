// write a recursive program as following....
//recursion used
//i/p: 5
//o/p:  5   4   3   2   1 => o/p displays for this coe is 0  1   2   3   4  

#include<iostream>
using namespace std;

void Display(int iNo)
{
    if(iNo >= 1)
    {
        Display(--iNo);           
        cout<<iNo<<"\t";
  
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