/* Check if binary representations of two numbers are anagram */
// Problem Link --> https://www.geeksforgeeks.org/check-binary-representations-two-numbers-anagram/

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

inline string decTObin(int a)
{
    string tmp = "";
    while (a)
    {
        tmp += ((a & 1) ? '1' : '0');
        a /= 2;
    }
    REVERSE(tmp);
    return tmp;
}

inline void solve()
{
    fast();
    int aa, bb;
    cin >> aa >> bb;

    /* using hashmap --> O(n) and constant space since hashmap size is 2 */
    // string a, b;
    // a = decTObin(aa);
    // b = decTObin(bb);
    // if (a.length() < b.length())
    // {
    //     swap(a, b);
    // }
    // vector<int> v(2, 0);
    // fi(i, 0, a.length())
    // {
    //     v[a[i] - 'a']++;
    // }
    // fi(i, 0, b.length())
    // {
    //     if (v[b[i] - 'a'] == 0)
    //     {
    //         cout << "NO" << dl;
    //         return;
    //     }
    //     else
    //     {
    //         v[b[i] - 'a']--;
    //     }
    // }
    // cout << "YES" << dl;

    /* efficient method will be count 1's bit cause one of the numbers has all zero in other number --> constant time O(1) and constant space */
    int a = __builtin_popcount(aa);
    int b = __builtin_popcount(bb);
    if (a != b)
    {
        cout << "NO" << dl;
    }
    else
    {
        cout << "YES" << dl;
    }
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