#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *stringHandler, *mathHandler;
    int option;

    stringHandler = dlopen("./libmystring.so", RTLD_LAZY);
    if(stringHandler == NULL)
    {
        printf("Error in dlopen(): %s\n", dlerror());
        return -1;
    }

    mathHandler = dlopen("./libmymath.so", RTLD_LAZY);
    if(mathHandler == NULL)
    {
        printf("Error in dlopen(): %s\n", dlerror());
        dlclose(stringHandler);
        return -1;
    }

    //menu
    printf("\n------- Menu ---------\n");
    printf("1. String Operations\n");
    printf("2. Math Operations\n");
    printf("Enter you choice: ");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
        {
            int choice;
            printf("\n--- String Operations ---\n");
            printf("1. String Length\n");
            printf("2. String Copy\n");
            printf("3. String Copy N Characters\n");
            printf("4. String Concatenate\n");
            printf("5. String Compare\n");
            printf("6. String Compare N Characters\n");
            printf("7. Reverse String\n");
            printf("8. Find Character Index\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            
            switch (choice)
            {
                case 1:
                {
                    int (*fp)(char *);
                    char str[100];

                    fp = (int(*)(char *))dlsym(stringHandler, "MyStrlen");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter a string: ");
                    scanf("%s", str);

                    printf("String Length is: %d\n", fp(str));

                    break;
                }

                case 2:
                {
                    void (*fp)(char *, char *);
                    char src[100], dest[100];

                    fp = (void(*)(char *, char *))dlsym(stringHandler, "MyStrcpy");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter a string: ");
                    scanf("%s", src);

                    fp(dest, src);
                    printf("Copied string is: %s\n", dest);
                    break;
                }

                case 3:
                {
                    void (*fp)(char *, char *, int);
                    char src[100], dest[100];
                    int n;

                    fp = (void(*)(char *, char *, int))dlsym(stringHandler, "MyStrcat");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter first string: ");
                    scanf("%s", src);
                    printf("Enter n: ");
                    scanf("%d", &n);

                    fp(dest, src, n);
                    printf("Result: %s\n", dest);
                    break;
                }

                case 4:
                {
                    void (*fp)(char *, char *);
                    char a[200], b[100];

                    fp = (void(*)(char *, char *))dlsym(stringHandler, "MyStrcat");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter first string: ");
                    scanf("%s", a);

                    printf("Enter second string: ");
                    scanf("%s", b);

                    fp(a, b);

                    printf("Concatenated = %s\n", a);
                    break;
                }

                case 5:
                {
                    int (*fp)(char *, char *);
                    char a[100], b[100];

                    fp = (int(*)(char *, char *))dlsym(stringHandler, "MyStrcmp");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter first string: ");
                    scanf("%s", a);

                    printf("Enter second string: ");
                    scanf("%s", b);

                    int r = fp(a, b);

                    if(r == 0) 
                        printf("Equal\n");
                    else if(r < 0) 
                        printf("First smaller\n");
                    else 
                        printf("First greater\n");

                    break;
                }

                case 6:
                {
                    int (*fp)(char *, char *, int);
                    char a[100], b[100];
                    int n;

                    fp = (int(*)(char *, char *, int))dlsym(stringHandler, "MyStrncmp");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter first string: ");
                    scanf("%s", a);

                    printf("Enter second string: ");
                    scanf("%s", b);

                    printf("Enter n: ");
                    scanf("%d", &n);

                    int r = fp(a, b, n);

                    if(r == 0) 
                        printf("Equal\n");
                    else if(r < 0) 
                        printf("First smaller\n");
                    else 
                        printf("First greater\n");

                    break;
                }

                case 7:
                {
                    void (*fp)(char *);
                    char a[100];

                    fp = (void(*)(char *))dlsym(stringHandler, "Mystrrev");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter string: ");
                    scanf("%s", a);

                    fp(a);

                    printf("Reversed = %s\n", a);
                    break;
                }

                case 8:
                {
                    char* (*fp)(char *, char);
                    char a[100], ch;

                    fp = (char*(*)(char *, char))dlsym(stringHandler, "MyStrchr");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter string: ");
                    scanf("%s", a);

                    printf("Enter character: ");
                    scanf(" %c", &ch);

                    char *pos = fp(a, ch);

                    if(pos == NULL)
                        printf("Character not found\n");
                    else
                        printf("Index = %ld\n", pos - a);

                    break;
                }
            
                default:
                    printf("Invalid Option Choice\n");
                    break;
            }
            break;
        }
        case 2:
        {
            int choice;

            printf("\n--- Math Operations ---\n");
            printf("1. Power (base^exp)\n");
            printf("2. Square Root\n");
            printf("3. Absolute Value\n");
            printf("4. Maximum of Two Numbers\n");
            printf("5. Minimum of Two Numbers\n");
            printf("6. Factorial\n");
            printf("7. GCD\n");
            printf("8. LCM\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                {
                    double (*fp)(double, int);
                    double base;
                    int exp;

                    fp = (double(*)(double,int))dlsym(mathHandler, "MyPow");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter base and exponent: ");
                    scanf("%lf %d", &base, &exp);

                    printf("Result: %lf\n", fp(base, exp));
                    break;
                }

                case 2:
                {
                    double (*fp)(double);
                    double n;

                    fp = (double(*)(double))dlsym(mathHandler, "MySqrt");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter number: ");
                    scanf("%lf", &n);

                    printf("Square Root: %lf\n", fp(n));
                    break;
                }

                case 3:
                {
                    int (*fp)(int);
                    int n;

                    fp = (int(*)(int))dlsym(mathHandler, "MyAbs");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter number: ");
                    scanf("%d", &n);

                    printf("Absolute: %d\n", fp(n));
                    break;
                }

                case 4:
                {
                    int (*fp)(int,int);
                    int a, b;

                    fp = (int(*)(int,int))dlsym(mathHandler, "MyMax");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);

                    printf("Max: %d\n", fp(a, b));
                    break;
                }

                case 5:
                {
                    int (*fp)(int,int);
                    int a, b;

                    fp = (int(*)(int,int))dlsym(mathHandler, "MyMin");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);

                    printf("Min = %d\n", fp(a, b));
                    break;
                }

                case 6:
                {
                    int (*fp)(int);
                    int n;

                    fp = (int(*)(int))dlsym(mathHandler, "MyFactorial");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter number: ");
                    scanf("%d", &n);

                    printf("Factorial: %d\n", fp(n));
                    break;
                }

                case 7:
                {
                    int (*fp)(int,int);
                    int a, b;

                    fp = (int(*)(int,int))dlsym(mathHandler, "MyGCD");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);

                    printf("GCD: %d\n", fp(a, b));
                    break;
                }

                case 8:
                {
                    int (*fp)(int,int);
                    int a, b;

                    fp = (int(*)(int,int))dlsym(mathHandler, "MyLCM");
                    if (fp == NULL) {
                        printf("Error: %s\n", dlerror());
                        break;
                    }

                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);

                    printf("LCM: %d\n", fp(a, b));
                    break;
                }

                default:
                    printf("Invalid Option Choice\n");
                    break;
            }

            break;
        }
        default:
            printf("Invalid option is entered...\n");
            break;
    }

    dlclose(stringHandler);
    dlclose(mathHandler);

    return 0;
}