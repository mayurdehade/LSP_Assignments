#include<stdio.h>

int add(int A, int B);

int main()
{
    int A, B;
    printf("Enter two numbers: \n");
    scanf("%d %d", &A, &B);

    printf("Addition is: %d\n", add(A, B));
    return 0;
}