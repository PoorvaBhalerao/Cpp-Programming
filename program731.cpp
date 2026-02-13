//Write a recursive program to Accept string from user and display String reversely(pattern displays)

#include<stdio.h>
#include<iostream>
using namespace std;

void strDisplay(char *str)
{

    if(*str != '\0')
    {
        strDisplay(str + 1); 
        cout<<str<<"\n";

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