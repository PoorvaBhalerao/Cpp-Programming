//Recursion
// write a program 
//input 4
//output:1+2+3+4 = 10   

#include<iostream>
using namespace std;

int Addition(int iNo)
{
    static int iSum = 0;
    static int i = 1;

    if(i <= iNo)
    {
        iSum = iSum + i;
        i++;
        Addition(iNo);
    }
    return iSum;
}

int main()
{
    int iRet = 0;

    iRet = Addition(4);

    cout<<"Addition is: "<<iRet;

    return 0;
}