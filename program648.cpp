//Resursion
// print 1 to 4 on screen using recursion

#include<iostream>
using namespace std;

void Display()
{
    int  i = 1;

    while(i <= 4)
    {
        cout<<i<<"\n";
        i++;
    }  
}

int main()
{
    Display();

    return 0;
}