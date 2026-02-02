#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler = NULL;
    int (*fp)(int, int) = NULL;
    int num1, num2;

    handler = dlopen("libmath.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("Error while opening shared library: %s\n", dlerror());
        return -1;
    }

    printf("Enter two numbers: \n");
    scanf("%d %d", &num1, &num2);

    fp = dlsym(handler, "Addition");
    if(fp == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handler);
        return -1;
    }
    
    printf("Addition: %d\n", fp(num1, num2));

    fp = dlsym(handler, "Substraction");
    if(fp == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handler);
        return -1;
    }
    
    printf("Substraction: %d\n", fp(num1, num2));

    dlclose(handler);
    
    return 0;
}