// sscanf function - take input from String

#include<stdio.h>

int main()
{
    char str[80] = "India is my Country";
    char Command[4][20] = {{'\0'},{'\0'},{'\0'},{'\0'}};
    int iRet = 0;

    printf("CVFS > ");
    fgets(str, sizeof(str), stdin);

    iRet = sscanf(str, "%s %s %s %s", Command[0], Command[1], Command[2], Command[3]);

    printf("Return Value of sscanf is: %d\n",iRet);         // 4

    printf("%s\n",Command[0]);
    printf("%s\n",Command[1]);
    printf("%s\n",Command[2]);
    printf("%s\n",Command[3]);

    return 0;
}
