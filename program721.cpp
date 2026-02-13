// Write a program to Accept N numbers from user and  display it.

#include<stdio.h>
#include<iostream>
using namespace std;

void Display(int Brr[], int iSize)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Brr[iCnt]<<"\n";
    }
}


int main()
{
    int Arr[] = {10, 20,30, 40, 50};

    Display(Arr, 5);
    
    return 0;
}