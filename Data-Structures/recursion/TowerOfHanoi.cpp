#include <bits/stdc++.h>
using namespace std;
void TOH(int n, int a, int b, int c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        printf("(%d,%d)\n", a, c);
        TOH(n - 1, b, a, c);
    }
}
int main(int argc, char const *argv[])
{
    int n, a, b, c;
    a = 1;
    b = 2;
    c = 3;
    scanf("%d", &n);
    TOH(n, a, b, c);
    return 0;
}