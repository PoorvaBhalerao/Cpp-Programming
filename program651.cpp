//Resursion
// write a program to dislay 1 to value given by user

#include<iostream>
using namespace std;

void Display(int iNo)
{
    int i = 1;

    while(i <= iNo)
    {
        cout<<i<<"\n";
        i++;
    }  
}

int main()
{
    Display(6);

    return 0;
}