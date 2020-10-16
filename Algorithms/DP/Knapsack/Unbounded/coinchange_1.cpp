//Max No of Way
/* Speacial Problem */
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

// ll gs[301][30001];//non optimized
ll gs[90001]; //for optimized O(sum) space

// inline ll NoOfWays(vll v, ll ind, ll sum)
// {
//     if (ind == 0 && sum != 0)
//     {
//         return 0;
//     }
//     if (sum == 0)
//     {
//         return 1;
//     }
//     if (v[ind - 1] > sum)
//     {
//         return NoOfWays(v, ind - 1, sum);
//     }
//     else
//     {
//         return (NoOfWays(v, ind, sum - v[ind - 1]) + NoOfWays(v, ind - 1, sum));
//     }
// }

// inline ll NoOfWays_BottomUp(vector<ll> v, ll sum, ll n)
// {
//     fi(i, 0, sum + 1)
//     {
//         gs[0][i] = 0;
//     }
//     fi(i, 0, n + 1)
//     {
//         gs[i][0] = 1;
//     }
//     fi(i, 1, n + 1)
//     {
//         fi(j, 1, sum + 1)
//         {
//             if (v[i - 1] <= j)
//             {
//                 gs[i][j] = (gs[i][j - v[i - 1]] + gs[i - 1][j]);
//             }
//             else
//             {
//                 gs[i][j] = gs[i - 1][j];
//             }
//         }
//     }
//     cout << gs[n][sum] << dl;
// }

inline ll NoOfWays_BottomUp_Optimized(vector<ll> v, ll c) // Space Optimized O(sum) space
{
    ll n = v.size();
    memset(gs, 0, sizeof(gs));
    gs[0] = 1;
    // fi(i, 0, c + 1)
    // {
    //     cout << gs[i] << " ";
    // }
    // cout << dl;
    fi(i, 0, n)
    {
        fi(j, v[i], c + 1)
        {
            gs[j] += gs[j - v[i]];
        }
    }
    // fi(i, 0, c + 1)
    // {
    //     cout << gs[i] << " ";
    // }
    // cout << dl;
    return gs[c];
}

inline void solve()
{
    fast();
    ll n, sum;
    cin >> n;
    vll v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    cin >> sum;
    cout << NoOfWays_BottomUp_Optimized(v, sum) << dl;
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