#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <array>

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

inline void PrimeFact(int n)
{
    vector<int> primefactor;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // int cnt = 0;
            while (n % i == 0)
            {
                primefactor.PB(i);
                // cnt++;
                n /= i;
            }
            // cout << i << "^" << cnt << " ";
        }
    }
    if (n > 1)
    {
        // cout << n << "^" << 1;
        primefactor.PB(n);
    }
    fi(i, 0, primefactor.size())
    {
        cout << primefactor[i] << " ";
    }
    cout << dl;
}

inline void WheelsFact(int n)
{
    vector<int> primefactor;
    // int cnt = 0;
    if (!(n & 1))
    {
        while (n % 2 == 0)
        {
            primefactor.PB(2);
            // cnt++;
            n /= 2;
        }
        // cout << 2 << "^" << cnt << " ";
    }
    for (int i = 3; i * i <= n; i += 2) // 50% no to check
    {
        if (n % i == 0)
        {
            // cnt = 0;
            while (n % i == 0)
            {
                primefactor.PB(i);
                // cnt++;
                n /= i;
            }
            // cout << i << "^" << cnt << " ";
        }
    }
    if (n > 1)
    {
        primefactor.PB(n);
        // cout << n << "^" << 1;
    }
    fi(i, 0, primefactor.size())
    {
        cout << primefactor[i] << " ";
    }
    cout << dl;
}

inline void ExtendedWheelsFact(int n)
{
    vector<int> primefactor;
    // int cnt = 0;
    for (int d : {2, 3, 5})
    {
        if (n % d == 0)
        {
            // cnt = 0;
            while (n % d == 0)
            {
                primefactor.PB(d);
                // cnt++;
                n /= d;
            }
            // cout << d << "^" << cnt << " ";
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    for (int i = 7; i * i <= n; i += increments[i++]) // 33.33% no to check
    {
        if (n % i == 0)
        {
            // cnt = 0;
            while (n % i == 0)
            {
                primefactor.PB(i);
                // cnt++;
                n /= i;
            }
            // cout << i << "^" << cnt << " ";
        }
        if (i == 8)
        {
            i = 0;
        }
    }
    if (n > 1)
    {
        primefactor.PB(n);
        // cout << n << "^" << 1;
    }
    fi(i, 0, primefactor.size())
    {
        cout << primefactor[i] << " ";
    }
    cout << dl;
}

inline void solve()
{
    fast();
    int n;
    cin >> n;
    // PrimeFact(n);
    // WheelsFact(n);
    ExtendedWheelsFact(n);
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