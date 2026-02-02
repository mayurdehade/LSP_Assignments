#include<stdio.h>
#include<dlfcn.h>
#include "perfect.h"

int IsPerfect(int No)
{
    void *handler;
    int (*fp)(int);

    if(No <= 0)
    {
        return 0;
    }

    handler = dlopen("./libhelper.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return 0;
    }

    fp = dlsym(handler, "SumOfFactors");
    if(fp == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return 0;
    }

    printf("No and fp: %d and %d\n", No, fp(No));
    if(No == fp(No))
    {
        return 1;
    }

    return 0;
}

