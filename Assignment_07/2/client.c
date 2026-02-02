#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler1 = NULL, *handler2 = NULL;
    int (*fpAdditon)(int, int) = NULL, (*fpSub)(int, int) = NULL;

    handler1 = dlopen("./libaddition.so", RTLD_LAZY);
    if(handler1 == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    handler2 = dlopen("./libsubstraction.so", RTLD_LAZY);
    if(handler2 == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fpAdditon = dlsym(handler1, "Addition");
    if(fpAdditon == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler1);
        dlclose(handler2);
        return -1;
    }

    fpSub = dlsym(handler2, "Substraction");
    if(fpSub == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler1);
        dlclose(handler2);
        return -1;
    }

    printf("Additon: %d\n", fpAdditon(11,10));
    printf("Substraction: %d\n", fpSub(11,10));
   
    dlclose(handler1);
    dlclose(handler2);

    return 0;
}