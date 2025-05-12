#include <string.h>

int Fibonacci(int n)
{
    int sum = 0;
    int a = 0;
    int b = 1;

    if (n == 0)
        return a;
    else if (n == 1)
        return b;

    for (int i = 2; i < n; i++)
    {
        int temp = a;
        a = b;
        b = temp + b;
    }

    return b;
}

int BinaryToDecimal(const char *binary)
{
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++)
        decimal = (decimal << 1) + (binary[i] - '0');
    return decimal;
}