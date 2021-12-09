#include <bits/stdc++.h>
using namespace std;
//question no 2
// void foo(int n, int sum)
// {
//     int k = 0, j = 0;
//     if (n == 0)
//     {
//         return;
//     }
//     k = n % 10;
//     j = n / 10;
//     sum = sum + k;
//     foo(j, sum);
//     printf("%d", k);
// }
// int main(int argc, char const *argv[])
// {
//     int a = 2048, sum = 0;
//     foo(a, sum);
//     printf("%d", sum);
//     return 0;
// }

//question no 2
// int f(int &x, int c)
// {
//     c = c - 1;
//     if (c == 0)
//     {
//         return 1;
//     }
//     x = x + 1;
//     return f(x, c) * x;
// }
// int main(int argc, char const *argv[])
// {
//     int p = 5;
//     printf("%d", f(p, p));
//     return 0;
// }

//question no 3
// int fac(int p)
// {
//     int x = 1, k;
//     if (p == 1)
//     {
//         return 1;
//     }
//     for (int k = 0; k < p; k++)
//     {
//         x = x + fac(k) * fac(p - k);
//     }
//     return x;//wrong something find it!
// }
// int main(int argc, char const *argv[])
// {
//     int k;
//     k = fac(5);
//     printf("%d", k);
//     return 0;
// }
void count(int n)
{
    static int d = 1;
    printf("(%d,%d)\n", n, d);
    // printf("%d ", d);
    d++;
    if (n > 1)
    {
        count(n - 1);
    }
    printf("%d ", d);
}
int main()
{
    count(3);
    return 0;
}