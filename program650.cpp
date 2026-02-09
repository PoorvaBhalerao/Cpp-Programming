//Resursion
// print 1 to 4 on screen using recursion

#include<iostream>
using namespace std;

void Display()
{
    static int i = 1;               // issue resolved

    if(i <= 4)
    {
        cout<<i<<"\n";
        i++;
        Display();
    }  
}

int main()
{
    Display();

    return 0;
}