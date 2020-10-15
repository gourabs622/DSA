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
// ll gs[2][1001];// space optimized 1
ll gs[1001];// space optimized 2

// inline ll lcsubstr_Recursive(string a, string b, ll n, ll m, ll cnt)
// {
//     if (n == 0 || m == 0)
//     {
//         return cnt;
//     }
//     if (a[n - 1] == b[m - 1])
//     {
//         return lcsubstr_Recursive(a, b, n - 1, m - 1, cnt + 1);
//     }
//     else
//     {
//         return max(cnt, max(lcsubstr_Recursive(a, b, n - 1, m, 0), lcsubstr_Recursive(a, b, n, m - 1, 0)));
//     }
// }

// inline ll lcsubstr_TopDown(string a, string b, ll n, ll m, ll cnt)
// {
//     if (n == 0 || m == 0)
//     {
//         return cnt;
//     }
//     if (gs[n][m] != -1)
//     {
//         return gs[n][m];
//     }
//     if (a[n - 1] == b[m - 1])
//     {
//         gs[n][m] = lcsubstr_TopDown(a, b, n - 1, m - 1, cnt + 1);
//         return gs[n][m];
//     }
//     else
//     {
//         gs[n][m] = max(cnt, max(lcsubstr_TopDown(a, b, n - 1, m, 0), lcsubstr_TopDown(a, b, n, m - 1, 0)));
//         return gs[n][m];
//     }
// }

// inline ll lcsubstr_TopDown(string a, string b, ll n, ll m, ll result)
// {
//     memset(gs, 0, sizeof(gs));
//     fi(i, 0, n + 1)
//     {
//         gs[i][0] = 0;
//     }
//     fi(i, 0, m + 1)
//     {
//         gs[0][i] = 0;
//     }
//     fi(i, 1, n + 1)
//     {
//         fi(j, 1, m + 1)
//         {
//             if (a[i - 1] == b[j - 1])
//             {
//                 gs[i][j] = 1 + gs[i - 1][j - 1];
//                 result = max(result, gs[i][j]);
//             }
//             else
//             {
//                 gs[i][j] = 0;
//             }
//         }
//     }
//     return result;
// }

// inline ll lcsubstr_BottomUp_Optimized1(string a, string b, ll n, ll m, ll cnt)// space O(2*max(n,m))
// {
//     memset(gs, 0, sizeof(gs));
//     fi(i, 0, n)
//     {
//         fi(j, 1, m+1)
//         {
//             if (a[i]==b[j-1])
//             {
//                 gs[1][j]=1+gs[0][j-1];
//                 cnt=max(cnt, gs[1][j]);
//             }
//             else {
//                 gs[1][j]=0;
//             }
//         }
//         fi(j, 1, m+1)
//         {
//             gs[0][j]=gs[1][j];
//         }
//     }
//     return cnt;
// }

inline ll lcsubstr_BottomUp_Optimized2(string a, string b, ll n, ll m, ll cnt)// space O(max(n,m))
{
    memset(gs, 0, sizeof(gs));
    fi(i, 0, n)
    {
        for (int j=m;j>0;j--)
        {
            if (a[i]==b[j-1])
            {
                gs[j]=1+gs[j-1];
                cnt=max(cnt, gs[j]);
            }
            else {
                gs[j]=0;
            }
        }
        // fi(j, 0, m+1)
        // {
        //     cout<<gs[j]<<" ";
        // }
        // cout<<dl;
    }
    return cnt;
}

inline void solve()
{
    fast();
    ll n, m, result = 0;
    string a, b;
    cin >> n >> m >> a >> b;
    ll ans = lcsubstr_BottomUp_Optimized2(a, b, n, m, 0);
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