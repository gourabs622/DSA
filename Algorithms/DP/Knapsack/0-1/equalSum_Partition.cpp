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

// ll gs[101][10001]; //very careful about the space cause this will give segmentation fault
//vector<vector<int>> dp(num.size(), vector<int>(sum / 2 + 1, -1));
ll gs[2][100001]; // Optimization1
// ll gs[100001]; // Optimization2

// inline ll ESUMP_Recursive(vll v, ll req_sum, ll ind)
// {
//     if (ind == 0 && req_sum != 0)
//     {
//         return 0;
//     }
//     if ((ind == 0 && req_sum == 0) || (ind != 0 && req_sum == 0))
//     {
//         return 1;
//     }
//     if (v[ind - 1] > req_sum)
//     {
//         return ESUMP_Recursive(v, req_sum, ind - 1);
//     }
//     else
//     {
//         return max(ESUMP_Recursive(v, req_sum - v[ind - 1], ind - 1), ESUMP_Recursive(v, req_sum, ind - 1));
//         // return (ESUMP_Recursive(v, req_sum - v[ind - 1], ind - 1) || ESUMP_Recursive(v, req_sum, ind - 1));
//     }
// }

// inline ll ESUMP_TopDown(vll v, ll req_sum, ll ind)
// {
//     if (ind == 0 && req_sum != 0)
//     {
//         return 0;
//     }
//     if ((ind == 0 && req_sum == 0) || (ind != 0 && req_sum == 0))
//     {
//         return 1;
//     }
//     if (gs[ind][req_sum] != -1)
//     {
//         return gs[ind][req_sum];
//     }
//     if (v[ind - 1] > req_sum)
//     {
//         gs[ind][req_sum] = ESUMP_TopDown(v, req_sum, ind - 1);
//         return gs[ind][req_sum];
//     }
//     else
//     {
//         gs[ind][req_sum] = max(ESUMP_TopDown(v, req_sum - v[ind - 1], ind - 1), ESUMP_TopDown(v, req_sum, ind - 1));
//         // return (ESUMP_Recursive(v, req_sum - v[ind - 1], ind - 1) || ESUMP_Recursive(v, req_sum, ind - 1));
//         return gs[ind][req_sum];
//     }
// }

// inline void ESUMP_BottomUp(vll v, ll sum)
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
//     if (gs[n][sum] == 1)
//     {
//         cout << "YES" << dl;
//     }
//     else
//     {
//         cout << "NO" << dl;
//     }
// }

// inline void ESum_SpaceOptimized_1(vector<ll> v, ll sum) // optimization 1 --> O(n*sum) and O(2*sum)
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
//     cout << (gs[n % 2][sum] ? "YES" : "NO") << dl;
// }

inline void ESum_SpaceOptimized_1_further(vector<ll> v, ll sum) // optimization 1 --> O(n*sum) and O(2*sum)
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

// inline void ESum_SpaceOptimized_2(vector<ll> v, ll sum) // optimization 2 --> O(n*sum) and O(sum)
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
    ll n, sum = 0;
    cin >> n;
    vll v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
        sum += v[i];
    }
    // memset(gs, -1, sizeof(gs));
    if (sum & 1)
    {
        cout << "NO" << dl;
        return;
    }
    ESum_SpaceOptimized_1_further(v, sum / 2);
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