
// Iteration using Recursion

#include<iostream>
using namespace std;

void Display()
{
    cout<<"Jay Ganesh...\n";            // it will print n number of times and stops with segmentation fault
    Display();
}

int main()
{
    Display();

    return 0;
}