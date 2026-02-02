#include<stdio.h>

void Display(char *str)
{
    printf("Entered String is: %s\n", str);

    int iCnt = 0;
    
    while(*str != '\0')
    {
        iCnt++;
        str++;
    }

    printf("Total Characters: %d\n", iCnt);
}