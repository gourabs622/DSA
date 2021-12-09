#include <stdio.h>
#include <stdlib.h>
int foo(int n)
{
    if (n < 1)
    {
        return 0;
    }
    else
    {
        foo(n - 1);
        printf("Hello World %d\n", n);
    }
}
int main()
{
    foo(3);
    return 0;
}