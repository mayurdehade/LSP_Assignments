#include<stdio.h>

int Add(int A, int B);
int Sub(int A, int B);
int Mul(int A, int B);
int Div(int A, int B);

int main()
{
    int num1, num2;

    printf("Enter two numbers: \n");
    scanf("%d %d", &num1, &num2);

    printf("Addition: %d\n",Add(num1, num2));
    printf("Substraction: %d\n",Sub(num1, num2));
    printf("Multiplication: %d\n",Mul(num1, num2));
    printf("Division: %d\n",Div(num1, num2));

    return 0;
}