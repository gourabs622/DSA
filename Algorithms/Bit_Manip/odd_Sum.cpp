#include <bits/stdc++.h>
using namespace std;
int main()
{
#define ll long long
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            v.push_back(a);
        }
        ll sum = accumulate(v.begin(), v.end(), 0);
        if (sum % 2 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
        sum = 0;
    }
    // int a[n][n];

    return 0;
}