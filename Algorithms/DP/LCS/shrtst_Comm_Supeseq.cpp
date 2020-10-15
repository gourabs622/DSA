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

// int gs[101][101];
int gs[2][101];

// inline int SCSuperSeq(string a, string b, int i, int j)
// {
//     if (i == a.length())
//     {
//         return b.length() - j;
//     }
//     if (j == b.length())
//     {
//         return a.length() - i;
//     }
//     if (a[i] == b[j])
//     {
//         return 1 + SCSuperSeq(a, b, i + 1, j + 1);
//     }
//     else
//     {
//         return min(1 + SCSuperSeq(a, b, i + 1, j), 1 + SCSuperSeq(a, b, i, j + 1));
//     }
// }

// inline int SCSuperSeq_TopDown(string a, string b, int i, int j)
// {
//     if (i == a.length())
//     {
//         return b.length() - j;
//     }
//     if (j == b.length())
//     {
//         return a.length() - i;
//     }
//     if (gs[i][j] != -1)
//     {
//         return gs[i][j];
//     }
//     if (a[i] == b[j])
//     {
//         return gs[i][j] = 1 + SCSuperSeq(a, b, i + 1, j + 1);
//     }
//     else
//     {
//         return gs[i][j] = 1 + min(SCSuperSeq(a, b, i + 1, j), SCSuperSeq(a, b, i, j + 1));
//         // return gs[i][j] = min(1 + SCSuperSeq(a, b, i + 1, j), 1 + SCSuperSeq(a, b, i, j + 1));
//     }
// }

inline int SCSuperSeq_BottomUp_Optimized(string a, string b, int n, int m)// space O(2*max(n,m)) linear
{
    mm(gs, 0);
    int ctr = 0;
    fi(i, 0, m+1)
    {
        gs[0][i]=i;
    }
    fi(i, 0, n)
    {
        ctr++;
        gs[1][0]=ctr;
        fi(j, 1, m+1)
        {
            if (a[i]==b[j-1])
            {
                gs[1][j]=1+gs[0][j-1];
            }
            else {
                gs[1][j]=1+min(gs[0][j], gs[1][j-1]);
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
    string a, b;
    cin >> a >> b;
    // cout << SCSuperSeq(a, b, 0, 0) << dl;
    // mm(gs, -1);
    // cout << SCSuperSeq_TopDown(a, b, 0, 0) << dl;
    // fi(i, 0, a.length() + 1)
    // {
    //     gs[i][0] = i;
    // }
    // fi(i, 0, b.length() + 1)
    // {
    //     gs[0][i] = i;
    // }
    // fi(i, 1, a.length() + 1)
    // {
    //     fi(j, 1, b.length() + 1)
    //     {
    //         if (a[i - 1] == b[j - 1])
    //         {
    //             gs[i][j] = 1 + gs[i - 1][j - 1];
    //         }
    //         else
    //         {
    //             gs[i][j] = min(1 + gs[i - 1][j], 1 + gs[i][j - 1]);
    //         }
    //     }
    // }
    // cout << gs[a.length()][b.length()] << dl;

    //LCS code
    // fi(i, 0, a.length() + 1)
    // {
    //     gs[i][0] = 0;
    // }
    // fi(i, 0, b.length() + 1)
    // {
    //     gs[0][i] = 0;
    // }
    // fi(i, 1, a.length() + 1)
    // {
    //     fi(j, 1, b.length() + 1)
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
    // cout << (a.length() + b.length()) - gs[a.length()][b.length()] << dl;
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