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

int gs[10001][10001];

inline void solve()
{
    fast();
    string a, temp;
    cin >> a;
    // temp = a;
    // REVERSE(a);//for lcs
    //method LPS
    fi(i, 0, a.length() + 1)
    {
        fi(j, 0, a.length() + 1)
        {
            if (i == 0 && j == 0)
            {
                gs[i][j] = 0;
            }
            else if (i == j)
            {
                gs[i][j] = 1;
            }
            else if (i > j)
            {
                gs[i][j] = 0;
            }
        }
    }
    fd(i, 0, a.length() - 1)
    {
        fi(j, i + 1, a.length())
        {
            if (a[i] == a[j])
            {
                gs[i + 1][j + 1] = 2 + gs[i + 2][j];
            }
            else
            {
                gs[i + 1][j + 1] = max(gs[i + 1][j], gs[i + 2][j + 1]);
            }
        }
    }
    cout << a.length() - gs[1][a.length()] << dl;

    // //method 2(using lcs logic)
    // fi(i, 0, a.length() + 1)
    // {
    //     gs[i][0] = 0;
    // }
    // fi(i, 0, a.length() + 1)
    // {
    //     gs[0][i] = 0;
    // }
    // fi(i, 1, a.length() + 1)
    // {
    //     fi(j, 1, a.length() + 1)
    //     {
    //         if (temp[i - 1] == a[j - 1])
    //         {
    //             gs[i][j] = 1 + gs[i - 1][j - 1];
    //         }
    //         else
    //         {
    //             gs[i][j] = max(gs[i - 1][j], gs[i][j - 1]);
    //         }
    //     }
    // }
    // cout << a.length() - gs[a.length()][a.length()] << dl;
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