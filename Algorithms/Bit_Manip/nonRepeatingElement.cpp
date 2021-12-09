#include <bits/stdc++.h>
using namespace std;

void withSort()
{
#define ll long long
    ll n, f = 0;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i] == v[i + 1])
        {
            i++;
            continue;
        }
        else
        {
            f = 1;
            cout << v[i] << " ";
        }
    }
    if (f == 0)
    {
        cout << "No unique element is here" << endl;
    }
}

void withXor()
{
#define ll long long
    ll n, f = 0;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < v.size(); i++)
    {
        if (i == 0 && ((v[i] ^ v[i + 1]) == 0))
        {
            continue;
        }
        else if (i == (v.size() - 1) && ((v[i] ^ v[i - 1]) == 0))
        {
            break;
        }
        else if (((v[i] ^ v[i + 1]) == 0) || ((v[i] ^ v[i - 1]) == 0))
        {
            // i++;
            continue;
        }
        else
        {
            f = 1;
            cout << v[i] << " ";
        }
    }
    if (f == 0)
    {
        cout << "No unique element is here" << endl;
    }
}

int main()
{
    // withSort();
    withXor();

    return 0;
}
