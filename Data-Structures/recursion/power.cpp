#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll poww(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y % 2 == 0)
    {
        return poww(x * x, y / 2);
    }
    else
    {
        return x * poww(x * x, (y - 1) / 2);
    }
}
int main()
{
    ll m, n;
    cin >> m >> n;
    cout << poww(m, n) << endl;
    return 0;
}