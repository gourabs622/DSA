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
    ll n, k, st = 0, curr_sum = 0, max_len = INT_MIN;
    cin >> n >> k;
    vector<ll> v(n);
    unordered_map<ll, pair<ll, ll>> u;
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    fi(i, 0, n)
    {
        curr_sum += v[i];
        if (curr_sum == k)
        {
            max_len = max(max_len, (i + 1) * 1LL);
        }
        if (u[curr_sum - k].S != 0)
        {
            ll kk = (i - u[curr_sum - k].F);
            max_len = max(max_len, kk);
        }
        if (u[curr_sum].S == 0)
        {
            u[curr_sum].F = i;
            u[curr_sum].S = 1;
        }
    }
    // for (auto it = u.begin(); it != u.end(); it++)
    // {
    //     cout << it->F << " " << it->S.F << " " << it->S.S << dl;
    // }
    cout << (max_len == INT_MIN ? 0 : max_len) << dl;
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