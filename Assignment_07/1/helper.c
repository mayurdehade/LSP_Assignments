#include "helper.h"

int SumOfFactors(int No)
{
    int sum = 0;

    for(int i=1; i < No; i++)
    {
        if(No % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}