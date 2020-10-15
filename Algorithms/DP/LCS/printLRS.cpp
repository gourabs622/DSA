#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

/*          					GOURAB SARKAR					            */

using namespace std;

typedef long long ll;
typedef long double ld;
#define PI 3.141592653589793238
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define PBO pop_back()
#define permute next_permutation
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define ALLA(arr, sz) arr, arr + sz
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define dl "\n"
#define mm(a, val) memset(a, val, sizeof(a))
#define b_s binary_search
#define u_b upper_bound
#define l_b lower_bound
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ld EPS = 1e-9;
const int N = 1000000005;
const ll NL = 1000000000000000005LL;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 9;
const int mod2 = 998244353;

#define fi(a, b, c) for (int a = b; a < c; ++a)
#define fd(a, b, c) for (int a = c - 1; a >= b; --a)
#define fei(a, b, c) for (int a = b; a <= c; ++a) //for any particular range
#define fed(a, b, c) for (int a = c; a >= b; --a) //for any particular range
#define fs(a, b) for (auto &a : b)                //for loop shortcut

// inline void OPEN()
// {
//     #ifdef ONLINE_JUDGE
//         freopen("input.in", "r", stdin);
//         freopen("output.in", "w", stdout);
//     #endif
// }

// const int maxN = 1e5 + 1;
// vector<int> adj[N];
// vector<bool> vis(N, false);

int gs[1001][1001];

inline string prntLRS(string a, int n, int m) //another recursive way by looking up into table O(n^2)
{
    if (n == 0 || m == 0)
    {
        return string("");
    }
    if (a[n - 1] == a[m - 1] && n != m)
    {
        return prntLRS(a, n - 1, m - 1) + a[n - 1];
    }
    else
    {
        if (gs[n - 1][m] > gs[n][m - 1])
        {
            return prntLRS(a, n - 1, m);
        }
        else
        {
            return prntLRS(a, n, m - 1);
        }
    }
}

inline void solve()
{
    fast();
    int n;
    string s, ss = "";
    cin >> n >> s;
    fi(i, 0, s.length() + 1)
    {
        gs[i][0] = 0;
        gs[0][i] = 0;
    }
    fi(i, 1, s.length() + 1)
    {
        fi(j, 1, s.length() + 1)
        {
            if (s[i - 1] == s[j - 1] && i != j)
            {
                gs[i][j] = 1 + gs[i - 1][j - 1];
            }
            else
            {
                gs[i][j] = max(gs[i - 1][j], gs[i][j - 1]);
            }
        }
    }
    // cout << prntLRS(s, n, n) << dl;
    int i = n, j = n;
    while (i > 0 || j > 0) //printing longest repeating subsequence
    {
        if (s[i - 1] == s[j - 1] & i != j)
        {
            ss += s[i - 1];
            i -= 1;
            j -= 1;
        }
        else
        {
            int k = gs[i][j];
            if (gs[i - 1][j] == k)
            {
                i -= 1;
            }
            else
            {
                j -= 1;
            }
        }
    }
    REVERSE(ss);
    cout << gs[n][n] << dl << ss << dl;
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