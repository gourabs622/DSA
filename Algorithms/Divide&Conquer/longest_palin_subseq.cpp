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

bool checkPalindrome(string a)
{
    string temp = a;
    REVERSE(temp);
    return (temp == a);
}

// string tt = "";

inline ll LPSubseq(string a, ll i, ll j)
{
    if (checkPalindrome(a))
    {
        return a.length();
    }
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return 1;
    }
    ll aa = 0;
    if (a[i] == a[j])
    {
        aa = 2 + LPSubseq(a, i + 1, j - 1); //if the first and last comp chars are equal
    }
    ll bb = LPSubseq(a, i + 1, j); //if not equal then either take the 1st one and ignore 2nd
    ll cc = LPSubseq(a, i, j - 1); //if not equal then either take the 2nd one and ignore 1st
    return max(aa, max(bb, cc));
}

inline void solve()
{
    fast();
    string s1;
    cin >> s1;
    cout << LPSubseq(s1, 0, s1.length() - 1) << dl;
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