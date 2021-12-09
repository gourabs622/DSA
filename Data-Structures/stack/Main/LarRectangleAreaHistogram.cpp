/* Maximum Rectangular Area in a Histogram */

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
    ll n;
    cin >> n;
    vector<ll> v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }

    /* using stack and maintain right smaller and left smaller array --> O(n) and O(n) space */
    stack<pair<ll, ll>> s, p;
    vector<ll> left, right;
    //for left smaller element and store the index
    s.push({INT_MAX, -1});
    fi(i, 0, n)
    {
        while (s.top().F != INT_MAX && v[i] <= s.top().F)
        {
            s.pop();
        }
        left.PB(s.top().S);
        s.push({v[i], i});
    }
    // fi(i, 0, left.size())
    // {
    //     cout << left[i] << " ";
    // }
    // cout << dl;

    //for right smaller element and store the index
    p.push({INT_MAX, n});
    fd(i, 0, n)
    {
        while (p.top().F != INT_MAX && v[i] <= p.top().F)
        {
            p.pop();
        }
        right.PB(p.top().S);
        p.push({v[i], i});
    }
    REVERSE(right);
    // fi(i, 0, right.size())
    // {
    //     cout << right[i] << " ";
    // }
    // cout << dl;

    //calculating max square
    ll maxSQ = 0;
    fi(i, 0, n)
    {
        maxSQ = max(maxSQ, (labs(left[i] - right[i]) - 1) * v[i]);
    }
    cout << maxSQ << dl;
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