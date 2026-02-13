// write a recursive program to count number of digits
//Recursion
//i/p: 56798
//o/p: 5    56    567     5679    56798  

#include<iostream>
using namespace std;

void DisplayDigits(int iNo)
{

    if(iNo > 0)
    {
        DisplayDigits(iNo / 10);
        cout<<iNo<<"\n";                        

    }
}

int main()
{
    int iValue = 0;

    cout<<"Enter a number: ";
    cin>>iValue;
    
    DisplayDigits(iValue);

    return 0;
}