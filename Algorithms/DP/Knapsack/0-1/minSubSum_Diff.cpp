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

// ll gs[51][20001];
ll gs[10001]; // Optimization

// inline ll MSSumDiff_R(vll v, ll sum, ll ind, ll curr)
// {
//     if (ind == 0)
//     {
//         return (labs(sum - (2 * curr)));
//     }
//     return min(MSSumDiff_R(v, sum, ind - 1, curr + v[ind - 1]), MSSumDiff_R(v, sum, ind - 1, curr));
// }

// inline ll MSSumDiff_TopDown(vll v, ll sum, ll ind, ll curr)
// {
//     if (ind == 0)
//     {
//         return (labs(sum - (2 * curr)));
//     }
//     if (gs[ind][curr] != -1)
//     {
//         return gs[ind][curr];
//     }
//     gs[ind][curr] = min(MSSumDiff_TopDown(v, sum, ind - 1, curr + v[ind - 1]), MSSumDiff_TopDown(v, sum, ind - 1, curr));
//     return gs[ind][curr];
// }

// inline void MSSunDiff_BottomUp(vector<ll> v, ll sum)
// {
//     ll n = v.size();
//     fi(i, 0, n + 1)
//     {
//         fi(j, 0, sum + 1)
//         {
//             if (i == 0 && j == 0)
//             {
//                 gs[i][j] = 1;
//             }
//             else if (j == 0)
//             {
//                 gs[i][j] = 1;
//             }
//             else if (i == 0)
//             {
//                 gs[i][j] = 0;
//             }
//         }
//     }
//     fi(i, 1, n + 1)
//     {
//         fi(j, 1, sum + 1)
//         {
//             if (v[i - 1] <= j)
//             {
//                 gs[i][j] = max(gs[i - 1][j - v[i - 1]], gs[i - 1][j]);
//             }
//             else
//             {
//                 gs[i][j] = gs[i - 1][j];
//             }
//         }
//     }
//     // fi(i, 0, n + 1)
//     // {
//     //     fi(j, 0, sum + 1)
//     //     {
//     //         cout << gs[i][j] << " ";
//     //     }
//     //     cout << dl;
//     // }
//     // Main thinking theme behind the problem
//     ll diff = INT_MAX;
//     fi(i, 0, (sum / 2) + 1)
//     {
//         if (gs[n][i])
//         {
//             ll inst = labs(sum - (2 * i));
//             diff = min(diff, inst);
//         }
//     }
//     cout << diff << dl;
// }

inline void MSSum_Diff_Optimized(vector<ll> v, ll sum)
{
    memset(gs, 0, sizeof(gs));
    ll n = v.size();
    gs[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = sum; j >= v[i]; j--)
        {
            if (gs[j - v[i]])
            {
                gs[j] = 1;
            }
        }
    }
    // fi(i, 0, sum + 1)
    // {
    //     cout << gs[i] << " ";
    // }
    // cout << dl;
    ll diff = INT_MAX;
    fi(i, 1, (sum / 2) + 1)
    {
        if (gs[i])
        {
            ll inst = labs(sum - (2 * i));
            diff = min(diff, inst);
        }
    }
    cout << diff << dl;
}

inline void solve()
{
    fast();
    ll n, sum = 0;
    cin >> n;
    vll v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
        sum += v[i];
    }
    // memset(gs, -1, sizeof(gs));
    MSSum_Diff_Optimized(v, sum);
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