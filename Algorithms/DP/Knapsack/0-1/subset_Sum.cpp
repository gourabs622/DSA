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

// ll gs[1001][1001]; // for non optimized
ll gs[2][100001]; // for optimized 1
// ll gs[100001]; // for optimized 2
// bool gs[1001][1001];

// inline ll SSum(vll v, ll sum, ll ind) // Recursive --> O(exponential) and Stack space
// {
//     if (ind == 0 && sum != 0)
//     {
//         return false;
//     }
//     if (sum == 0 && ind >= 0)
//     {
//         return true;
//     }
//     if (v[ind - 1] > sum)
//     {
//         return SSum(v, sum, ind - 1);
//     }
//     else
//     {
//         return (SSum(v, sum - v[ind - 1], ind - 1) || SSum(v, sum, ind - 1));
//     }
// }

// inline ll SSumTopDown(vll v, ll sum, ll ind) // Memoize/TopDown --> O(n*sum) and O(n*sum) space
// {
//     if (ind == 0 && sum != 0)
//     {
//         return false;
//     }
//     if (sum == 0 && ind >= 0)
//     {
//         return true;
//     }
//     if (gs[ind][sum] != false)
//     {
//         return gs[ind][sum];
//     }
//     if (v[ind - 1] > sum)
//     {
//         gs[ind][sum] = SSumTopDown(v, sum, ind - 1);
//         return gs[ind][sum];
//     }
//     else
//     {
//         gs[ind][sum] = (SSumTopDown(v, sum - v[ind - 1], ind - 1) || SSumTopDown(v, sum, ind - 1));
//         return gs[ind][sum];
//     }
// }

// inline void SSumBottomUp(vll v, ll sum) // Tabular/BottomUp --> O(n*sum) and O(n*sum) space
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
//     fi(i, 0, n + 1)
//     {
//         fi(j, 0, sum + 1)
//         {
//             cout << gs[i][j] << " ";
//         }
//         cout << dl;
//     }
//     if (gs[n][sum])
//     {
//         cout << "YES" << dl;
//     }
//     else
//     {
//         cout << "NO" << dl;
//     }
// }

// inline void SSum_SpaceOptimized_1(vector<ll> v, ll sum) // optimization 1 --> O(n*sum) and O(2*sum)
// {
//     ll n = v.size();
//     memset(gs, 0, sizeof(gs));
//     for (ll i = 0; i < n + 1; i++)
//     {
//         for (ll j = 0; j < sum + 1; j++)
//         {
//             if (j == 0)
//             {
//                 gs[i % 2][j] = 1;
//             }
//             else if (i == 0)
//             {
//                 gs[i % 2][j] = 0;
//             }
//             else if (v[i - 1] <= j)
//             {
//                 gs[i % 2][j] = (gs[(i + 1) % 2][j] || gs[(i + 1) % 2][j - v[i - 1]]);
//             }
//             else
//             {
//                 gs[i % 2][j] = gs[(i + 1) % 2][j];
//             }
//         }
//     }
//     // fi(i, 0, 2)
//     // {
//     //     fi(j, 0, sum + 1)
//     //     {
//     //         cout << gs[i][j] << " ";
//     //     }
//     //     cout << dl;
//     // }
//     cout << gs[n % 2][sum] << dl;
// }

inline void SSum_SpaceOptimized_1_further(vector<ll> v, ll sum) // optimization 1 --> O(n*sum) and O(2*sum)
{
    ll n = v.size();
    memset(gs, 0, sizeof(gs));
    fi(i, 0, 2)
    {
        gs[i][0]=1;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j < sum + 1; j++)
        {
            gs[1][j]=(gs[0][j-v[i]]||gs[0][j]);
        }
        for (ll j = 1; j < sum + 1; j++)// instead of copy u can use mod to not change
        {
            gs[0][j]=gs[1][j];
        }
    }
    // fi(i, 0, 2)
    // {
    //     fi(j, 0, sum + 1)
    //     {
    //         cout << gs[i][j] << " ";
    //     }
    //     cout << dl;
    // }
    cout << (gs[0][sum] ? "YES" : "NO") << dl;
}

// inline void SSum_SpaceOptimized_2(vector<ll> v, ll sum) // optimization 2 --> O(n*sum) and O(sum)
// {
//     ll n = v.size();
//     memset(gs, 0, sizeof(gs));
//     gs[0] = 1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = sum; j >= v[i]; j--)
//         {
//             if (gs[j - v[i]] == 1)
//             {
//                 gs[j] = 1;
//             }
//         }
//     }
//     cout << (gs[sum] ? "YES" : "NO") << dl;
// }

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
    SSum_SpaceOptimized_1_further(v, sum);
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