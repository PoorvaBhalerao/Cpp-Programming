//Iteration
// write a program 
//input 4
//output:1+2+3+4 = 10   

#include<iostream>
using namespace std;

int Addition(int iNo)
{
    int iSum = 0;
    int i = 0;

    while(i <= iNo)
    {
        iSum = iSum + i;
        i++;
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