// Accept string from user and display String reversely

#include<stdio.h>
#include<iostream>
using namespace std;

void strDisplay(char *str)
{
    int iCount = 0;

    while(*str != '\0')
    {
        str++;
        iCount++;
    }
    str--;

    while(iCount > 0)
    {
        cout<<*str;
        str--;
        iCount--;
    }



}

int main()
{
    char Arr[50] = {'\0'};
    
    printf("Enter string: ");
    scanf("%[^'\n']s",Arr);

    strDisplay(Arr);
    
    return 0;
}