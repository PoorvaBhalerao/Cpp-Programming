//Recursion
// write a program 
//input 4
//output:1+2+3+4 = 10   

#include<iostream>
using namespace std;

int Addition(int iNo)
{
    static int iSum = 0;

    if(iNo >=1)
    {
        iSum = iSum + iNo;
        iNo--;
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