// Accept two numbers from user and return Maximum(generic programming)

#include<iostream>
using namespace std;

template <class T>
T Maximum(T No1, T No2)
{
    T Max;
    
    if(No1 > No2)
    {
        Max = No1;
    }
    else
    {
        Max = No2;
    }
    return Max;
}

int main()
{
    double dValue1 = 10.0, dValue2 = 11.0, dRet = 0.0;

    dRet = Maximum(dValue1, dValue2);
    cout<<"Maximum: "<<dRet<<"\n";   

    return 0;
}