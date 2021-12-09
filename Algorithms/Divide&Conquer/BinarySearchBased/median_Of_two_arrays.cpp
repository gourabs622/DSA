#include <bits/stdc++.h>
/*          					GOURAB SARKAR					            */
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;

double EPS = 1e-9;
int INF = 1000000005;
ll INFF = 1000000000000000005LL;
#define mod 1000000007
#define PI 3.141592653589793238
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define PBO pop_back()
#define dl "\n"

#define test  \
    ll t;     \
    cin >> t; \
    while (t--)

#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))

#define fi(a, b, c) for (ll a = b; a < c; ++a)
#define fd(a, b, c) for (ll a = c - 1; a >= b; --a)
#define fei(a, b, c) for (ll a = b; a <= c; ++a)
#define fed(a, b, c) for (ll a = c; a >= b; --a)
#define fs(a, b) for (auto &a : b)

inline void OPEN()
{
    // #ifdef ONLINE_JUDGE
    //     freopen("input.in", "r", stdin);
    //     freopen("output.in", "w", stdout);
    // #endif
}

inline ll medianOFtwo(vll a, vll b) //Time Complexity - O(n)
{
    ll size = a.size() + b.size();
    ll temp = size;
    (size & 1) ? size /= 2 : size = (size - 1) / 2;
    ll i = 0, j = 0, cnt = 0;
    while (i < a.size() || j < b.size())
    {
        if (cnt == size)
        {
            if (temp & 1)
            {
                if (a[i] < b[j])
                {
                    return a[i];
                }
                else
                {
                    return b[j];
                }
            }
            return (a[i] + b[j]) / 2;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        cnt++;
    }
    if (i == a.size())
    {
        while (cnt != size)
        {
            cnt++;
            j++;
        }
        if (temp & 1)
        {
            return b[j];
        }
        return (b[j] + b[j + 1]) / 2;
    }
    while (cnt != size)
    {
        cnt++;
        i++;
    }
    if (temp & 1)
    {
        return a[i];
    }
    return (a[i] + a[i + 1]) / 2;
}

inline void solve()
{
    fast();
    ll n, m;
    cin >> n >> m;
    vll v(n), w(m);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    fi(i, 0, m)
    {
        cin >> w[i];
    }
    /*
    //if both arrays are not sorted
    SORT(v);
    SORT(w);
    */
    cout << medianOFtwo(v, w) << dl;
}

int main()
{
    fast();
    // OPEN();
    solve();
    // test
    // {
    //     solve();
    // }

    return 0;
}