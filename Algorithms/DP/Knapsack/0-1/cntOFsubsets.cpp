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

ll gs[1001]; // space optimized
// ll gs[101][101];// non optimized

// inline ll CntSSum_Recursive(vll v, ll sum, ll ind, ll currSum)
// {
//     if (currSum == sum)
//     {
//         return 1;
//     }
//     if (ind == 0 && currSum != sum)
//     {
//         return 0;
//     }
//     // if (v[ind - 1] > sum)
//     // {
//     //     return CntSSum_Recursive(v, sum, ind - 1, currSum);
//     // }
//     // else
//     // {
//     return (CntSSum_Recursive(v, sum, ind - 1, currSum + v[ind - 1]) + CntSSum_Recursive(v, sum, ind - 1, currSum));
//     // }
// }

// inline ll CntSSum_TopDown(vll v, ll sum, ll ind, ll currSum)
// {
//     if (currSum == sum)
//     {
//         return 1;
//     }
//     if (ind == 0 && currSum != sum)
//     {
//         return 0;
//     }
//     if (gs[ind][currSum] != -1)
//     {
//         return gs[ind][currSum];
//     }
//     // if (v[ind - 1] > sum)
//     // {
//     //     return CntSSum_Recursive(v, sum, ind - 1, currSum);
//     // }
//     // else
//     // {
//     // }
//     else
//     {
//         gs[ind][currSum] = (CntSSum_TopDown(v, sum, ind - 1, currSum + v[ind - 1]) + CntSSum_TopDown(v, sum, ind - 1, currSum));
//         return gs[ind][currSum];
//     }
// }

// inline ll CntSSum_BottomUp(vll v, ll sum)
// {
//     ll n = v.size();
//     memset(gs, 0, sizeof(gs));
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
//         fi(j, 0, sum + 1)
//         {
//             gs[i][j] = gs[i - 1][j - v[i - 1]] + gs[i - 1][j];
//         }
//     }
//     cout << gs[n][sum] << dl;
// }

inline ll CntSSum_BottomUp_Optimized(vector<ll> v, ll sum) //space optimization O(sum) space
{
    ll n = v.size();
    memset(gs, 0, sizeof(gs));
    gs[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = sum; j >= v[i]; j--)
        {
            if (v[i] <= j)
            {
                gs[j] += gs[j - v[i]];
            }
        }
    }
    return gs[sum];
}

inline void solve()
{
    fast();
    ll n, sum;
    cin >> n >> sum;
    vll v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    ll ans = CntSSum_BottomUp_Optimized(v, sum);
    cout << ans << dl;
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