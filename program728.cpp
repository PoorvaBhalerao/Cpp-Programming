//Write a recursive program to Accept string from user and display String reversely

#include<stdio.h>
#include<iostream>
using namespace std;

void strDisplay(char *str)
{

    if(*str != '\0')
    {
        str++;                          // due to this first letter is not displayed
        strDisplay(str); 
        cout<<*str<<"\n";

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