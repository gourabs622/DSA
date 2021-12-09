#include <bits/stdc++.h>
using namespace std;

void B(int n);

void A(int n)
{
    if (n > 0)
    {
        printf("In A %d\n", n);
        B(n - 1);
    }
}

void B(int n)
{
    if (n > 0)
    {
        printf("In B %d\n", n);
        A(n / 2);
    }
}

int main()
{
    int n;
    cin >> n;
    A(n);

    return 0;
}