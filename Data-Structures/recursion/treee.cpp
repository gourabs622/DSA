#include <bits/stdc++.h>
using namespace std;

void tre(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        tre(n - 1);
        tre(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    tre(n);

    return 0;
}