#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll sum_n(ll n)
{
    if (n == 0)
        return 0;
    else
        return sum_n(n - 1) + n;
}
int main()
{
    ll n;
    cin >> n;
    // cout << sum_n(n) << endl;
    cout << (n * (n + 1)) / 2 << endl;//without recursion
    return 0;
}
