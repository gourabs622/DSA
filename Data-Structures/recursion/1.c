#include <stdio.h>
#include <stdlib.h>

// //find biggest number in a array using recursion
// int findhighest(int a[], int n)
// {
//     static int highest = INT_MIN;
//     if (n == -1)
//     {
//         return highest;
//     }
//     else if (a[n] > highest)
//     {
//         highest = a[n];
//     }
//     return findhighest(a, n - 1);
// }
// int main()
// {
//     int a[10] = {5, 55, 12, 48, 61, 100, 14, 58, 77, 10};
//     int n = sizeof(a) / sizeof(a[0]);
//     int k = findhighest(a, n);
//     printf("%d\n", k);
//     return 0;
// }

//find biggest number in a array using iteration
// int main()
// {
//     int a[10] = {5, 55, 12, 48, 61, 100, 14, 58, 77, 10};
//     int n = sizeof(a) / sizeof(a[0]);
//     int highest = a[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] > highest)
//         {
//             highest = a[i];
//         }
//     }
//     printf("%d\n", highest);
//     return 0;
// }