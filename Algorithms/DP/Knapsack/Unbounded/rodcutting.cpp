/* Same as Unbounded Knapsack */

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

ll gs[1001][1001];

inline ll maxProfit(vll p, vll w, ll s, ll c)
{
    if (s == 0 || c == 0)
    {
        return 0;
    }
    if (w[s - 1] > c)
    {
        return maxProfit(p, w, s - 1, c);
    }
    else
    {
        return max(p[s - 1] + maxProfit(p, w, s, c - w[s - 1]), maxProfit(p, w, s - 1, c));
    }
}

inline ll maxProfit_TopDown(vll p, vll w, ll s, ll c)
{
    if (s == 0 || c == 0)
    {
        return 0;
    }
    if (gs[s][c] != -1)
    {
        return gs[s][c];
    }
    if (w[s - 1] > c)
    {
        gs[s][c] = maxProfit_TopDown(p, w, s - 1, c);
        return gs[s][c];
    }
    else
    {
        gs[s][c] = max(p[s - 1] + maxProfit_TopDown(p, w, s, c - w[s - 1]), maxProfit_TopDown(p, w, s - 1, c));
        return gs[s][c];
    }
}

inline void solve()
{
    fast();
    ll n;
    cin >> n;
    vll profit(n), size;
    fi(i, 0, n)
    {
        cin >> profit[i];
    }
    fi(i, 0, n)
    {
        size.PB(i + 1);
    }
    ll W = n;
    // cout << maxProfit(profit, size, n, W) << dl;
    // memset(gs, -1, sizeof(gs));
    // cout << maxProfit(profit, size, n, W) << dl;
    fi(i, 0, n + 1)
    {
        gs[i][0] = 0;
    }
    fi(i, 0, W + 1)
    {
        gs[0][i] = 0;
    }
    fi(i, 1, n + 1)
    {
        fi(j, 1, W + 1)
        {
            if (size[i - 1] <= j)
            {
                gs[i][j] = max(profit[i - 1] + gs[i][j - size[i - 1]], gs[i - 1][j]);
            }
            else
            {
                gs[i][j] = gs[i - 1][j];
            }
        }
    }
    fi(i, 0, n + 1)
    {
        fi(j, 0, W + 1)
        {
            cout << gs[i][j] << " ";
        }
        cout << dl;
    }
    cout << gs[n][W] << dl;
    //Try to use this problem with 1D array
}

int main()
{
    fast();
    // OPEN();
    // solve();
    test
    {
        solve();
    }

    return 0;
}