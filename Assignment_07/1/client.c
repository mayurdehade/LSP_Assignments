#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handler;
    int (*fp)(int);
    int No = 0;

    printf("Enter Number: ");
    scanf("%d", &No);

    handler = dlopen("./libperfect.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handler, "IsPerfect");
    if(fp == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    if(fp(No))
    {
        printf("%d is a Perfect Number\n", No);
    } 
    else
    {
        printf("%d is NOT a Perfect Number\n", No);
    }

    dlclose(handler);

    return 0;
}