//Resursion
// print 4 times * on screen using recursion

#include<iostream>
using namespace std;

void Display()
{
    int i = 1;

    cout<<i<<"\n";
    
    i++;
    
    Display();

}

int main()
{
    Display();

    return 0;
}