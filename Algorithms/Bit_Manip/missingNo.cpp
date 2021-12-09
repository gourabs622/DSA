#include <bits/stdc++.h>
using namespace std;

void basic()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int m = *max_element(v.begin(), v.end());
    int sum = (m * (m + 1)) / 2;
    cout << sum - (accumulate(v.begin(), v.end(), 0)) << endl;
}

void basic2() //Avoid integer overflow condition
{
#define ll long long
    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    ll t = 1;
    for (ll i = 2; i < v.size() + 1; i++)
    {
        t += i;
        t -= v[i - 2];
    }
    cout << t << endl;
}

void usingxor() //using bitwise xor operation
{
#define ll long long
    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    ll x1 = v[0], x2 = 0;
    ll m = *max_element(v.begin(), v.end());
    for (ll i = 1; i < v.size(); i++)
    {
        x1 ^= v[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        x2 ^= i;
    }
    cout << (x1 ^ x2) << endl;
}

int main()
{
    // basic();
    // basic2();
    usingxor();

    return 0;
}
