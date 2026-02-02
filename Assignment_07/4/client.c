#include<stdio.h>
#include<dlfcn.h>
#include<string.h>

int main()
{
    void *handler;
    int (*MyStrlen)(char *);
    char arr[100];

    memset(arr, '\0', sizeof(arr));

    handler = dlopen("./libmystring.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    printf("Enter string: \n");
    scanf("%[^\n]%*c", arr);

    
    MyStrlen = dlsym(handler, "MyStrlen");
    if(MyStrlen == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    MyStrlen(arr);

    dlclose(handler);

    return 0;
}