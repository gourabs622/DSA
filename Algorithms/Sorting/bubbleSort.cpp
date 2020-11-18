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

inline void RBS(vector<int> &v, int i)
{
    if (i == 1)
    {
        return;
    }
    fi(k, 0, i - 1)
    {
        if (v[k] > v[k + 1])
        {
            swap(v[k], v[k + 1]);
        }
    }
    RBS(v, i - 1);
}

inline void solve()
{
    fast();
    int n, f = 0;
    cin >> n;
    vector<int> v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }

    /* Naive Approach --> O(n^2) and constant space */
    //Increasing-Order
    // fi(i, 0, n - 1)
    // {
    //     fi(j, 0, n - i - 1)
    //     {
    //         if (v[j] > v[j + 1])
    //         {
    //             swap(v[j], v[j + 1]);
    //             f = 1;
    //         }
    //     }
    //     if (f == 0)
    //     {
    //         break;
    //     }
    // }
    //Decreasing-Order
    // fd(i, 1, n)
    // {
    //     fd(j, 1, n)
    //     {
    //         if (v[j] > v[j - 1])
    //         {
    //             swap(v[j], v[j - 1]);
    //             f = 1;
    //         }
    //     }
    //     if (f == 0)
    //     {
    //         break;
    //     }
    // }
    //Recursive Bubble Sort
    RBS(v, v.size());

    fi(i, 0, n)
    {
        cout << v[i] << " ";
    }
    cout << dl;
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