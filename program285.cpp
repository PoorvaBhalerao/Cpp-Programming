
// Iteration using Recursion

#include<iostream>
using namespace std;

void Display()
{
    int iCnt = 0;                           // auto storage class
    cout<<"Jay Ganesh..."<<iCnt<<"\n";      // it will print n number of times and stops with segmentation fault
    iCnt++;       
    Display();
}

int main()
{
    Display();

    return 0;
}