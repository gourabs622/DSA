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

// ll gs[101][101];// for non optimized
const ll nn = 100001;
// ll gs[2][nn];// optimization 1
ll gs[nn];// optimization 2

// inline ll lcsRecursive(string a, string b, ll n, ll m)
// {
//     if (n == 0 || m == 0)
//     {
//         return 0;
//     }
//     if (a[n - 1] == b[m - 1])
//     {
//         return (1 + lcsRecursive(a, b, n - 1, m - 1));
//     }
//     else
//     {
//         return max(lcsRecursive(a, b, n - 1, m), lcsRecursive(a, b, n, m - 1));
//     }
// }

// inline ll lcs_TopDown(string a, string b, ll n, ll m)
// {
//     if (n == 0 || m == 0)
//     {
//         return 0;
//     }
//     if (gs[n][m] != -1)
//     {
//         return gs[n][m];
//     }
//     if (a[n - 1] == b[m - 1])
//     {
//         gs[n][m] = (1 + lcs_TopDown(a, b, n - 1, m - 1));
//         return gs[n][m];
//     }
//     else
//     {
//         gs[n][m] = max(lcs_TopDown(a, b, n - 1, m), lcs_TopDown(a, b, n, m - 1));
//         return gs[n][m];
//     }
// }


// inline ll lcs_BottomUp(string a, string b, ll n, ll m)
// {
    // fi(i, 0, n + 1)
    // {
    //     gs[i][0] = 0;
    // }
    // fi(i, 0, m + 1)
    // {
    //     gs[0][i] = 0;
    // }
    // fi(i, 1, n + 1)
    // {
    //     fi(j, 1, m + 1)
    //     {
    //         if (a[i - 1] == b[j - 1])
    //         {
    //             gs[i][j] = 1 + gs[i - 1][j - 1];
    //         }
    //         else
    //         {
    //             gs[i][j] = max(gs[i - 1][j], gs[i][j - 1]);
    //         }
    //     }
    // }
    // cout << gs[n][m] << dl;
// }

// inline ll lcs_BottomUp_Optimization1(string a, string b, ll n, ll m)
// {
//     memset(gs, 0, sizeof(gs));
//     fi(i, 0, m + 1)
//     {
//         fi(j, 1, n + 1)
//         {
//             if (b[i] == a[j - 1])
//             {
//                 gs[1][j]=1+gs[0][j-1];
//             }
//             else
//             {
//                 gs[1][j]=max(gs[1][j-1], gs[0][j]);
//             }
//         }
//         fi(j, 1, n + 1)
//         {
//             gs[0][j]=gs[1][j];
//             gs[1][j]=0;
//         }
//     }
//     // fi(i, 0, 2)
//     // {
//     //     fi(j, 0, n+1)
//     //     {
//     //         cout<<gs[i][j]<<" ";
//     //     }
//     //     cout<<dl;
//     // }
//     return gs[0][n];
// }
inline ll lcs_BottomUp_Optimization2(string a, string b, ll n, ll m)
{
    memset(gs, 0, sizeof(gs));
    fi(i, 0, m + 1)
    {
        fi(j, 1, n + 1)
        {
            if (b[i] == a[j - 1])
            {
                gs[j]=1+gs[j-1];
            }
            else
            {
                gs[j]=max(gs[j-1], gs[j]);
            }
        }
    }
    return gs[n];
}

inline void solve()
{
    fast();
    ll n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    ll ans = lcs_BottomUp_Optimization2(a, b, n, m);
    cout<<ans<<dl;
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