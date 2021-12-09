#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//recursive way
// int fact(int m)
// {
//     if (m == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return m * fact(m - 1);
//     }
// }
// int main(int argc, char const *argv[])
// {
//     int n;
//     printf("Enter the no you want factorial\n");
//     scanf("%d", &n);
//     int r = fact(n);
//     printf("Factorial no is %d\n", r);
//     return 0;
// }

//iterative way
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n, fact = 1;
//     scanf("%d", &n);
//     if (n == 0)
//     {
//         printf("%d\n", fact);
//     }
//     else
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             fact = fact * i;
//         }
//         printf("%d\n", fact);
//     }
//     return 0;
// }

//tgamma method
// int main()
// {
//     int n = 4;
//     n = tgamma(n + 1);
//     printf("%d\n", n);
//     return 0;
// }
int a[200] = {0};
int fac(int n)
{
    a[0] = 1;
    int len = 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    // fact(n);
    int q = 2;
    a[0] = 1;
    int l = 1;
    int counter = 1;
    int num = 0;
    while (q <= n)
    {
        counter = 0;
        while (counter < l)
        {
            a[counter] = a[counter] * q;
            a[counter] = a[counter] + num;
            num = a[counter] / 10;
            a[counter] %= 10;
            counter++;
        }
        while (num != 0)
        {
            a[l] = num % 10;
            num = num / 10;
            l++;
        }
        q++;
    }
    for (int i = l - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}