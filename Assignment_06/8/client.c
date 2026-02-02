#include<stdio.h>
#include<dlfcn.h>
#include<string.h>

int main()
{
    void *handler;
    int (*countLowerCaseLetters)(char *);
    int (*countUpperCaseLetters)(char *);
    int (*countDigits)(char *);
    char arr[100];

    memset(arr, '\0', sizeof(arr));

    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    printf("Enter string: \n");
    scanf("%[^\n]%*c", arr);

    
    countLowerCaseLetters = dlsym(handler, "CountLowerCaseLetters");
    if(countLowerCaseLetters == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    //Lower case letters
    printf("Total lower case letters in string: %d\n", countLowerCaseLetters(arr));

    countUpperCaseLetters = dlsym(handler, "CountUpparCaseLetters");
    if(countUpperCaseLetters == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    //Lower case letters
    printf("Total uppar case letters in string: %d\n", countUpperCaseLetters(arr));

    countDigits = dlsym(handler, "CountLDigits");
    if(countDigits == NULL)
    {
        printf("%s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    //Lower case letters
    printf("Total digits in string: %d\n", countDigits(arr));

    dlclose(handler);

    return 0;
}