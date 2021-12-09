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
        ll x = 0, count = 0, flag = 0;
        x = n;
        while (x > 0)
        {
            if (floor(x / 10) > 0)
            {
                flag++;
                count++;
                x = x - 10 + 1;
            }
            else
            {
                break;
            }
        }
        if (flag != 0)
        {
            cout << n + count << endl;
        }
        else
        {
            cout << n << endl;
        }
    }
    return 0;
}