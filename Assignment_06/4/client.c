#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler;
    void (*fp)(void);

    //load a valid shared library
    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    //Invalid function name is paase then it give fp as NULL
    //and store error in dlerror()
    //it give error as undefined symbol and segmentation fault
    fp = dlsym(handler, "Addition");
    if(fp == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    //valid function name is passed
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