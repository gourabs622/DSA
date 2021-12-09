#include <bits/stdc++.h>
using namespace std;

int nn(int n)
{
    if (n > 100)
    {
        printf("%d\n", n);
        return n - 10;
    }
    else
    {
        printf("%d\n", n);
        return nn(nn(n + 11));
    }
}

int main()
{
    int n;
    cin >> n;
    nn(n);

    return 0;
}