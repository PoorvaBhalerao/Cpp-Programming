//Iteration
// write a program to dislay value given by user

//input 4
//output:4   3   2   1   

#include<iostream>
using namespace std;

void Display(int iNo)
{
    int i = 0;
    
    i = iNo;

    while(i>0)
    {
        cout<<i<<"\n";
        i--;
    }
}

int main()
{
    Display(4);

    return 0;
}