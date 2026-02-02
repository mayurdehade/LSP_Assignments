#include<stdio.h>
#include<dlfcn.h>

int main(int argc, char *argv[])
{
    void *handler = NULL;
    void (*fp)(void) = NULL;

    if(argc != 3)
    {
        printf("Incorrect number of argument is entered...\n");
        return -1;
    }

    handler = dlopen(argv[1], RTLD_LAZY);
    if(handler == NULL)
    {
        printf("Error: %s\n", dlerror());
        return -1;
    }

    fp = dlsym(handler, argv[2]);
    if(fp == NULL)
    {
        printf("Given Symbol is not found: %s\n", dlerror());
        dlclose(handler);
        return -1;
    } else 
    {   
        printf("Symbol is found\n");
        printf("Symbol Address: %p\n", fp);

    }

    dlclose(handler);
    return 0;
}