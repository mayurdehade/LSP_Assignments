#include<stdio.h>
#include<dlfcn.h>
#include<string.h>

int main()
{
    void *handler;
    char arr[100];
    int (*fpArr[3])(char *);
    int i = 0;

    memset(arr, '\0', sizeof(arr));

    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    printf("Enter string: \n");
    scanf("%s", arr);

    
    fpArr[0] = dlsym(handler, "CountLowerCaseLetters");
    if(fpArr[0] == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    fpArr[1] = dlsym(handler, "CountUpparCaseLetters");
    if(fpArr[1] == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    fpArr[2] = dlsym(handler, "CountLDigits");
    if(fpArr[2] == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    for(i = 0; i < 3; i++)
    {
        printf("Function Address: %p\n", fpArr[i]);
        printf("Function Result: %d\n", fpArr[i](arr));
    }

    dlclose(handler);

    return 0;
}