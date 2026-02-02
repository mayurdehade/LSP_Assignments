#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler;
    void (*fp)(void);

    //load dynamic library using dlopen
    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        //handle error with dlerror()
        printf("%s\n", dlerror());
        return -1;
    }

    //get function pointer of the Welcome function using dlsym
    fp = dlsym(handler, "Welcome");
    if(fp == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    //call welcome function using function pinter
    fp();

    //free opened dynamic library
    dlclose(handler);

    return 0;
}