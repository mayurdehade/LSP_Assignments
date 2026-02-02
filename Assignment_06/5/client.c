#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler;
    void (*fp)(void);

    //RTLD_LAZY --> resolve symbol only when used it not in advance
    //RTLD_NOW --> resolve symbol immediately

    //loading shared library using RTLD_LAZY 
    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }
    fp = dlsym(handler, "Display");
    if(fp == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    fp();

    dlclose(handler);

    //loding shared library using RTLD_NOW
    handler = dlopen("./libserver.so", RTLD_NOW);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handler, "Display");
    if(fp == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    fp();

    dlclose(handler);

    return 0;
}