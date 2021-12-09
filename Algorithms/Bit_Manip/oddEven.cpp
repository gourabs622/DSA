#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
#define ll long long
    ll n, k;
    cin >> n >> k;
    if (n & 1)
    {
        if (k <= n / 2 + 1)
        {
            cout << 2 * k - 1 << endl;
            return 0;
        }
        else
        {
            cout << 2 * (k - n / 2 - 1) << endl;
            return 0;
        }
    }
    else
    {
        if (k <= (n / 2))
        {
            cout << ((2 * k) - 1) << endl;
        }
        else
        {
            cout << ((2 * k) - n) << endl;
        }
    }

    return 0;
}