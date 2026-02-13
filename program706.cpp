// write a recursive program to count number of digits
//Recursion
//i/p: 567
//o/p: 5    56      567       

#include<iostream>
using namespace std;

void DisplayDigits(int iNo)
{

    if(iNo > 0)
    {
        cout<<iNo<<"\n";                        

        DisplayDigits(iNo / 10);

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