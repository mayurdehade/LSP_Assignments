#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler;
    void (*fpDisplay)(void);
    void (*fpChange)(int);
    void (*fpReset)(void);

    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    //display the value of global variable
    fpDisplay = dlsym(handler, "DisplayValue");
    if(fpDisplay == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }
    //display value
    printf("Default value of global varibale is: \n");
    fpDisplay();

    //change value of the global variable
    fpChange = dlsym(handler, "ChangeValue");
    if(fpChange == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    //change value
    fpChange(11);
    
    //display value
    printf("Changed value of global variable is: \n");
    fpDisplay();

    //reset value
    fpReset = dlsym(handler, "ResetValue");
    if(fpReset == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    //reset value
    fpReset();

    printf("After rest global variable value is: \n");
    fpDisplay();

    dlclose(handler);

    return 0;
}