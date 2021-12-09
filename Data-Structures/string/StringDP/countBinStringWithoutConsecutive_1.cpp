/* Count number of binary strings without consecutive 1’s */
// Problem Link --> https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

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

inline void solve()
{
    fast();
    int n;
    cin >> n;

    /* using DP --> O(n) and O(n) space */
    /* Intuition --> since length 1 strings are always consucutive so we store 1 as answer
       then see length 2 has 3 strings, length 3 has 5 string, length 4 has 8 string, so this become a series pattern called
       Fibonacci series. a[0]=1 && b[0]=1 the recurrence soln a[i]=a[i-1]+b[i-1] && b[i]=a[i-1]
       initially 1 1
            -->  2 1 --> this is you have to think cause rest of the series will be fibonacci
                 3 2
                 5 3
                 8 5
                 13 8
                 ......... its a fibonacci series --> 1 1 2 3 5 8 13 21 ...... */
    int a[101], b[101];
    a[0] = b[0] = 1;
    fi(i, 1, n + 1)
    {
        a[i] = ((a[i - 1] % mod) + (b[i - 1] % mod)) % mod;
        b[i] = (a[i - 1] % mod);
    }
    cout << (a[n] % mod) << dl;
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