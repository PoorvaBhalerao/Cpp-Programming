// write a recursive program to check number is perfect or not
//recursion
//i/p: 28
//o/p: number is perfect

#include<iostream>
using namespace std;

bool CheckPerfect(int iNo)
{
    static int iSum = 0;
    static int iCnt = 1;
   
    if(iCnt <= (iNo/2))
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
        iCnt++;
        CheckPerfect(iNo);
    }

    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }

    return iSum;
}

int main()
{
    int iValue = 0;
    bool bRet = false;

    cout<<"Enter a number: ";
    cin>>iValue;
    
    bRet = CheckPerfect(iValue);

    if(bRet == true)
    {
        cout<<"Its a perfect number\n";
    }
    else
    {
        cout<<"Its not a perfect number\n";

    }
    
    return 0;
}