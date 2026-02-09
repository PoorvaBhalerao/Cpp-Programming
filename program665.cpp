//Recursion
//write a program of factorial
//input 4
//output:1*2*3*4 = 10   

#include<iostream>
using namespace std;

int iFact = 1;                                // global variable

void Factorial(int iNo)
{
    if(iNo >=1)
    {
        iFact = iFact * iNo;
        Factorial(--iNo);                   
    }
}

int main()
{
    Factorial(4);

    cout<<"Factorial is: "<<iFact<<"\n";

    return 0;
}