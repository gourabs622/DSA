//Minimum no of coins
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

// const ll maxN = 1000001;
// const ll maxM = 1000001;
// vvl gs(maxN, vll(maxM));
// ll gs[10001][10001]; // non optimized code
ll gs[1000001]; // for space optimization

// inline ll MinNoOfCoins(vll v, ll ind, ll sum)
// {
//     if (ind == 0 && sum != 0)
//     {
//         return INT_MAX - 1;
//     }
//     if (sum == 0)
//     {
//         return 0;
//     }
//     if (v[ind - 1] > sum)
//     {
//         return MinNoOfCoins(v, ind - 1, sum);
//     }
//     else
//     {
//         return min(1 + MinNoOfCoins(v, ind, sum - v[ind - 1]), MinNoOfCoins(v, ind - 1, sum));
//     }
// }

// inline ll MinNoOfCoins_BottomUp(vll v, ll sum)
// {
//     ll n = v.size();
//     memset(gs, 0, sizeof(gs));
//     fi(i, 1, sum + 1)
//     {
//         gs[0][i] = LLONG_MAX - 1;
//     }
//     fi(i, 1, n + 1)
//     {
//         fi(j, 1, sum + 1)
//         {
//             if (v[i - 1] <= j)
//             {
//                 gs[i][j] = min(1 + gs[i][j - v[i - 1]], gs[i - 1][j]);
//             }
//             else
//             {
//                 gs[i][j] = gs[i - 1][j];
//             }
//         }
//     }
//     cout << (gs[n][sum] == LLONG_MAX - 1 ? -1 : gs[n][sum]) << dl;
// }

inline ll MinNoOfCoins_BottomUp_Optimized(vll v, ll sum)
{
    ll n = v.size();
    memset(gs, 0, sizeof(gs));
    fi(i, 1, sum + 1)
    {
        gs[i] = LLONG_MAX - 1;
    }
    fi(i, 0, n)
    {
        fi(j, v[i], sum + 1)
        {
            gs[j] = min(1 + gs[j - v[i]], gs[j]);
        }
    }
    if (gs[sum] == LLONG_MAX - 1)
    {
        cout << -1 << dl;
    }
    else
    {
        cout << gs[sum] << dl;
    }
}

inline void solve()
{
    fast();
    ll n, sum;
    cin >> sum;
    cin >> n;
    vll v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
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