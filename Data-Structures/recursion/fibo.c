#include <stdio.h>
#include <stdlib.h>

//recursion method
// int fibo(int m)
// {
//     int first = 0, second = 1;
//     if (m == 0)
//     {
//         return first;
//     }
//     else if (m == 1)
//     {
//         return second;
//     }
//     else
//     {
//         return (fibo(m - 1) + fibo(m - 2));
//     }
// }
// int main()
// {
//     int n;
    // int f = 0, s = 1,fibo;
    // printf("Enter the limit\n");
    // scanf("%d", &n);
    //iteration method
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == 0)
    //     {
    //         printf("%d ", f);
    //     }
    //     else if (i == 1)
    //     {
    //         printf("%d ", s);
    //     }
    //     else
    //     {
    //         fibo = f + s;
    //         f = s;
    //         s = fibo;
    //         printf("%d ", fibo);
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", fibo(n));
    // }
//     int r = fibo(n);
//     printf("Fibo of this %d", fibo(n));

//     return 0;
// }

//more method to see copy
//a) Dynamic method
//b) Space optimized method