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

inline ll LCSubseq(string a, string b, ll i, ll j)
{
    if (a == b)
    {
        return a.length();
    }
    if (i == a.length() || j == b.length())
    {
        return 0;
    }
    ll cc = 0;
    if (a[i] == b[j]) // if both the characters matches
    {
        // return 1 + LCSubseq(a, b, i + 1, j + 1);
        cc = 1 + LCSubseq(a, b, i + 1, j + 1);
    }
    ll aa = LCSubseq(a, b, i + 1, j); //taking string a char but not taking string b char at this moment
    ll bb = LCSubseq(a, b, i, j + 1); //taking string b char but not taking string a char at this moment
    // ll cc = LCSubseq(a, b, i + 1, j + 1); //not taking either string a or string b char at this moment
    return max(aa, max(bb, cc));
}

inline void solve()
{
    fast();
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCSubseq(s1, s2, 0, 0) << dl;
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