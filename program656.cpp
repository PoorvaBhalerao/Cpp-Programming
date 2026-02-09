//Recursion
// write a program to dislay  to value given by user

//input 4
//output:4   3   2   1   

#include<iostream>
using namespace std;

void Display(int iNo)
{
    if(iNo > 0)
    {
        cout<<iNo<<"\n";
        iNo--;
        Display(iNo);
    }
}

int main()
{
    Display(4);

    return 0;
}