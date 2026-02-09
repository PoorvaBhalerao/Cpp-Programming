//Resursion
// print 4 times * on screen using recursion

#include<iostream>
using namespace std;

void Display()
{
    cout<<"*\n";
    Display();

}

int main()
{
    Display();

    return 0;
}