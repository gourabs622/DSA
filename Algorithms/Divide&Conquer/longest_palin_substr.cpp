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

inline ll LPSubstr(string a, ll i, ll j)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return 1;
    }
    ll c1 = 0;
    if (a[i] == a[j])
    {
        ll rem = j - i - 1;
        if (rem == LPSubstr(a, i + 1, j - 1)) //checks if the remaining in between characters are also palindrome or not
        {
            c1 = 2 + rem;
        }
    }
    ll c2 = LPSubstr(a, i + 1, j);
    ll c3 = LPSubstr(a, i, j - 1);
    return max(c1, max(c2, c3));
}

inline void solve()
{
    fast();
    string s;
    cin >> s;
    cout << LPSubstr(s, 0, s.length() - 1) << dl;
}

int main()
{
    fast();
    // OPEN();
    solve();
    // test
    // {
    //     solve();
    // }

    return 0;
}