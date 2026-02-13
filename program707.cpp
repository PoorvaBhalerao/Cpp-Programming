
//o/p:// write a recursive program to count number of digits
//Recursion
//i/p: 567
//o/p:

#include<iostream>
using namespace std;

void DisplayDigits(int iNo)
{

    if(iNo > 0)
    {
        cout<<iNo<<"\n";                        

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