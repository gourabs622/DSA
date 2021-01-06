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

inline bool bysec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.S < b.S);
}

inline void solve1() //using priority queue without sort the arrangement
{
}

inline void solve() //using Array/Vector with Sort the activities
{
    fast();
    ll n;
    cin >> n;
    vll start(n), finish(n);
    fi(i, 0, n)
    {
        cin >> start[i];
    }
    fi(i, 0, n)
    {
        cin >> finish[i];
    }
    vpl st_fi;
    fi(i, 0, start.size())
    {
        st_fi.PB({start[i], finish[i]});
    }
    // sort(ALL(st_fi), bysec);
    sort(ALL(st_fi), [](auto const &a, auto const &b) { return a.S < b.S; });
    // fi(i, 0, st_fi.size())
    // {
    //     cout << st_fi[i].F << " " << st_fi[i].S << dl;
    // }
    ll take = 1, curr = st_fi[0].S;
    cout << 1 << " ";
    fi(i, 1, st_fi.size())
    {
        if (st_fi[i].F >= curr)
        {
            // take++;
            cout << i + 1 << " ";
            curr = st_fi[i].S;
        }
    }
    cout << dl;
    // cout << take << dl;
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