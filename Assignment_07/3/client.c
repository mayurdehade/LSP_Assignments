#include<stdio.h>
#include<dlfcn.h>
#include<string.h>

int main()
{
    void *handler;
    int (*fpdisplay)(char *);
    char arr[100];

    memset(arr, '\0', sizeof(arr));

    handler = dlopen("./libdisplay.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    printf("Enter string: \n");
    scanf("%[^\n]%*c", arr);

    
    fpdisplay = dlsym(handler, "Display");
    if(fpdisplay == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    fpdisplay(arr);

    dlclose(handler);

    return 0;
}