#include <bits/stdc++.h>
using namespace std;

void xorr()
{
#define ll long long
    ll n, x = 0, y = 0, set;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    ll xor_of;
    for (ll i = 0; i < v.size(); i++)
    {
        xor_of ^= v[i];
    }
    set = xor_of & (~(xor_of - 1));
    for (ll i = 0; i < v.size(); i++)
    {
        if (set & v[i])
        {
            x ^= v[i];
        }
        else
        {
            y ^= v[i];
        }
    }
    cout << x << " " << y << endl;
}

int main()
{
    xorr();

    return 0;
}
