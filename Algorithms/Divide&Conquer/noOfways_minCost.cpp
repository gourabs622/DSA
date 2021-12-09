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

inline ll MC(ll a[][50], ll i, ll j, ll n, ll m, ll tot_cost)
{
    if (tot_cost < 0)
    {
        return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
        return (tot_cost - a[i][j] == 0);
    }
    if (i == n - 1)
    {
        return MC(a, i, j + 1, n, m, tot_cost - a[i][j]);
    }
    if (j == m - 1)
    {
        return MC(a, i + 1, j, n, m, tot_cost - a[i][j]);
    }
    ll aa = MC(a, i + 1, j, n, m, tot_cost - a[i][j]); //move only in down
    ll bb = MC(a, i, j + 1, n, m, tot_cost - a[i][j]); // move only in right
    // ll cc = a[i][j] + MC(a, i + 1, j + 1, n, m); //move only in diagonally
    // return min(aa, min(bb, cc));
    return aa + bb;
}

inline void solve()
{
    fast();
    ll n, m, a[50][50], tot_cost;
    cin >> n >> m >> tot_cost;
    fi(i, 0, n)
    {
        fi(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    cout << MC(a, 0, 0, n, m, tot_cost) << dl;
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