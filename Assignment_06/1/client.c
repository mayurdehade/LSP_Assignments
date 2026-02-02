#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handler;
    int (*fd)(int, int);

    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fd = dlsym(handler, "Addition");
    if(fd == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    printf("Addition is: %d\n", fd(10, 20));

    fd = dlsym(handler, "Substraction");
    if(fd == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    printf("Substraction is: %d\n", fd(20, 5));

    dlclose(handler);

    return 0;
}