double MyPow(double base, int exp)
{
    double result = 1.0;
    int i;

    for(i = 0; i < exp; i++)
    {
        result = result * base;
    }

    return result;
}

double MySqrt(double n)
{
    double x = n;
    double root;
    int i;

    for(i = 0; i < 20; i++)
    {
       root = 0.5 * (x + n/x);
       x = root; 
    }

    return root;
}

int MyAbs(int n)
{
    if(n < 0)
    {
        return -n;
    }
    return n;
}

int MyMax(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int MyMin(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

int MyFactorial(int n)
{
    int fact = 1;
    int i;

    for(i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int MyGCD(int a, int b)
{
    int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MyLCM(int a, int b)
{
    return (a * b) / MyGCD(a, b);
}