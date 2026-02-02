#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler = NULL;

    handler = dlopen("libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("Error while opening shared library: %s\n", dlerror());
        return -1;
    }

    printf("File gets successfully loaded\n");

    return 0;
}

/*
    Explanation:
        case 1: without LD_LIBRARY_PATH:
            Error while opening shared library: libserver.so: cannot open shared object file: No such file or directory

        case 2: with LD_LIBRARY_PATH is set:
            File gets successfully loaded


*/