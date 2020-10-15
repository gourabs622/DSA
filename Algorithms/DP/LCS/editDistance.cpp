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
#define mm(a,b) memset(a,b,sizeof(a))

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

ll gs[101][101];// non optimized
// ll gs[2][101]; //space optimized

inline ll edit_Recursive(string a, string b, ll n, ll m)
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    if (a[n - 1] == b[m - 1])
    {
        return edit_Recursive(a, b, n - 1, m - 1);
    }
    else
    {
        return 1 + min(edit_Recursive(a, b, n - 1, m - 1), min(edit_Recursive(a, b, n - 1, m), edit_Recursive(a, b, n, m - 1)));
    }
}

inline ll edit_TopDown(string a, string b, ll n, ll m)
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    if (gs[n][m] != -1)
    {
        return gs[n][m];
    }
    if (a[n - 1] == b[m - 1])
    {
        gs[n][m] = edit_TopDown(a, b, n - 1, m - 1);
        return gs[n][m];
    }
    else
    {
        gs[n][m] = 1 + min(edit_TopDown(a, b, n - 1, m - 1), min(edit_TopDown(a, b, n - 1, m), edit_TopDown(a, b, n, m - 1)));
        return gs[n][m];
    }
}

inline ll edit_BottomUp_Optimized(string a, string b, ll n, ll m)// space optimized O(2*max(n,m))
{
    mm(gs, 0);
    fi(i, 0, m+1)
    {
        gs[0][i]=i;
    }
    ll ctr=0;
    fi(i, 0, n)
    {
        ctr++;
        gs[1][0]=ctr;
        fi(j, 1, m+1)
        {
            if (a[i]==b[j-1])
            {
                gs[1][j]=gs[0][j-1];
            }
            else {
                gs[1][j]=1+min(gs[0][j-1], min(gs[0][j], gs[1][j-1]));
            }
        }
        fi(j, 0, m+1)
        {
            gs[0][j]=gs[1][j];
        }
    }
    return gs[0][m];
}

inline void solve()
{
    fast();
    ll n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    // cout << edit_Recursive(a, b, n, m) << dl;
    // memset(gs, -1, sizeof(gs));
    // cout << edit_TopDown(a, b, n, m) << dl;
    fi(i, 0, n + 1)
    {
        gs[i][0] = i;
    }
    fi(i, 0, m + 1)
    {
        gs[0][i] = i;
    }
    fi(i, 1, n + 1)
    {
        fi(j, 1, m + 1)
        {
            if (a[i - 1] == b[j - 1])
            {
                gs[i][j] = gs[i - 1][j - 1];
            }
            else
            {
                gs[i][j] = 1 + min(gs[i - 1][j - 1], min(gs[i - 1][j], gs[i][j - 1]));
            }
        }
    }
    fi(i, 0, n + 1)
    {
        fi(j, 0, m + 1)
        {
            cout << gs[i][j] << " ";
        }
        cout << dl;
    }
    cout << gs[n][m] << dl;

    //LCS apply(it throughs wrong answer for some input)
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
    // cout << max(a.length() - gs[n][m], b.length() - gs[n][m]) << dl;
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