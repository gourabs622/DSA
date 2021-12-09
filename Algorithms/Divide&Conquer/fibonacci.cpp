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

inline ll FiboFormula(ll n) //Time Complexity - O(1) but upto 92 terms
{
    double pp = (1 + sqrt(5)) / 2;
    return round(pow(pp, n) / sqrt(5));
}

inline ll FiboR(ll n) //Time Complexity - O(Exponential)
{
    if (n < 2)
    {
        return n;
    }
    return FiboR(n - 1) + FiboR(n - 2);
}
inline ll FiboI(ll n) //Time Complexity - O(n)
{
    ll res = 0, first = 0, sec = 1;
    fi(i, 0, n)
    {
        if (i < 2)
        {
            res += i;
            // cout << res << " ";
        }
        else
        {
            first = sec;
            sec = res;
            res = (first + sec);
            // cout << first << " ";
        }
    }
    return res;
}

inline void solve()
{
    fast();
    ll n;
    cin >> n;
    cout << FiboFormula(n) << dl;
    // cout << FiboR(n) << dl;
    // cout << FiboI(n) << dl;
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