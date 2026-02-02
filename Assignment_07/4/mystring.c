#include<stdio.h>

void MyStrlen(char *str)
{
    int iCnt = 0;
    
    while(*str != '\0')
    {
        iCnt++;
        str++;
    }

    printf("String length: %d\n", iCnt);
}