#include<stdio.h>

int iNum = 100;

void ChangeValue(int num)
{
    iNum = num;
}

void DisplayValue()
{
    printf("Number is: %d\n", iNum);
}

void ResetValue()
{
    iNum = 100;
}