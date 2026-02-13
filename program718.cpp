// Write a recursive code to Accept string from user and display length of string

#include<stdio.h>
#include<iostream>
using namespace std;

int strlenX(char *str)
{
    static int iCount = 0;

    if(*str != '\0')
    {
        iCount++;
        str++;
        strlenX(str);
    }
    return iCount;
}

int main()
{
    char Arr[50] = {'\0'};
    int iRet = 0;

    printf("Enter string: ");
    scanf("%[^'\n']s",Arr);

    iRet = strlenX(Arr);

    printf("Length of string is: %d\n",iRet);
    
    return 0;
}