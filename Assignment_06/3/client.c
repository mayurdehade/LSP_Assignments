#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handler;
    int (*fp)(int, int);
    int iRet = 0, iNum1, iNum2, choice;

    handler = dlopen("./libserver.so", RTLD_LAZY);
    if(handler == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    //get user input
    printf("Enter two number: \n");
    scanf("%d", &iNum1);
    scanf("%d", &iNum2);

    while(1)
    {
        printf("1. Addition, 2. Substraction, 3. Multiplication, 4. Division 5. Exit\n");
        printf("Enter your choice for operation: \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                fp = dlsym(handler, "Addition");
                if(fp == NULL)
                {
                    printf("%s\n", dlerror());
                    dlclose(handler);
                    return -1;
                }
                printf("Addition is: %d\n", fp(iNum1, iNum2));
                break;
            case 2:
                fp = dlsym(handler, "Substraction");
                if(fp == NULL)
                {
                    printf("%s\n", dlerror());
                    dlclose(handler);
                    return -1;
                }
                printf("Substraction is: %d\n", fp(iNum1, iNum2));
                break;
            case 3:
                fp = dlsym(handler, "Multiplication");
                if(fp == NULL)
                {
                    printf("%s\n", dlerror());
                    dlclose(handler);
                    return -1;
                }
                printf("Multiplication is: %d\n", fp(iNum1, iNum2));
                break;
            case 4:
                fp = dlsym(handler, "Division");
                if(fp == NULL)
                {
                    printf("%s\n", dlerror());
                    dlclose(handler);
                    return -1;
                }
                printf("Division is: %d\n", fp(iNum1, iNum2));
                break;
            
            case 5:
                return 0;
                break;
            
            default:
                printf("You have entered incorrect choice\n");
        }
    } 
    
    dlclose(handler);
    return 0;
}