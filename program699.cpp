// write a recursive program as following....
//recursion used
//i/p: 5
//o/p:  1   2   3   4   5  

#include<iostream>
using namespace std;

void Display(int iNo)
{
    if(iNo >= 1)
    {
        cout<<iNo<<"\t";        //  5   4   3   2   1
        Display(iNo-1); 
        cout<<iNo<<"\t";        //  1   2   3   4   5
            
    }
}

int main()
{
    int iValue = 0;

    cout<<"Enter a number: ";
    cin>>iValue;
    Display(iValue);

    cout<<"\n";

    return 0;
}