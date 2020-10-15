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

ll gs[1001][1001]; // for non optimized

// inline ll cntMDSS_Recursive(vll v, ll ind, ll req_sum)
// {
//     if (ind == 0 && req_sum != 0)
//     {
//         return 0;
//     }
//     if (req_sum == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return (cntMDSS_Recursive(v, ind - 1, req_sum - v[ind - 1]) + cntMDSS_Recursive(v, ind - 1, req_sum));
//     }
// }

// inline ll cntMDSS_TopDown(vll v, ll ind, ll req_sum)
// {
//     if (ind == 0 && req_sum != 0)
//     {
//         return 0;
//     }
//     if (req_sum == 0)
//     {
//         return 1;
//     }
//     if (gs[ind][req_sum] != -1)
//     {
//         return gs[ind][req_sum];
//     }
//     else
//     {
//         gs[ind][req_sum] = (cntMDSS_TopDown(v, ind - 1, req_sum - v[ind - 1]) + cntMDSS_TopDown(v, ind - 1, req_sum));
//         return gs[ind][req_sum];
//     }
// }

inline void cntMDSS_BottomUp(vll v, ll s1)
{
    memset(gs, 0, sizeof(gs));
    ll n = v.size();
    fi(i, 0, s1 + 1)
    {
        gs[0][i] = 0;
    }
    fi(i, 0, n + 1)
    {
        gs[i][0] = 1;
    }
    fi(i, 1, n + 1)
    {
        fi(j, 1, s1 + 1)
        {
            gs[i][j] = (gs[i - 1][j - v[i - 1]] + gs[i - 1][j]);
        }
    }
    cout << gs[n][s1] << dl;
}

inline void solve()
{
    fast();
    ll n, diff, sum = 0;
    cin >> n >> diff;
    vll v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum <= diff)
    {
        cout << 0 << dl;
        return;
    }
    if ((sum + diff) % 2 != 0)
    {
        cout << 0 << dl;
        return;
    }
    ll s1 = (sum + diff) / 2;
    cntMDSS_BottomUp(v, s1);
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