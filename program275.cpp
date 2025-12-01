//accept two numbers (of two different datatypes) and display then (generic programming)

#include<iostream>
using namespace std;

template <class T, class W>
void Display(T no1, W no2)
{
    cout<<no1<<"\n";
    cout<<no2<<"\n";
}

int main()
{
    int no1 = 11;
    double no2 = 99.9955;

    Display(no1, no2);

    return 0;
}