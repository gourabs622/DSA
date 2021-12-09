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

inline ll GenRandom(ll x, ll y)
{
    srand(time(NULL));
    return (x + rand() % (y - x + 1));
}

inline ll RBS(vll v, ll low, ll high, ll ele)
{
    if (low <= high)
    {
        ll mid = GenRandom(low, high);
        if (v[mid] == ele)
        {
            return 1;
        }
        else if (v[mid] > ele)
        {
            return RBS(v, low, high - 1, ele);
        }
        else
        {
            return RBS(v, low + 1, high, ele);
        }
    }
    return -1;
}

inline void solve()
{
    fast();
    ll n, ele;
    cin >> n;
    vll v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    cin >> ele;
    if (RBS(v, 0, v.size() - 1, ele) == -1)
    {
        cout << "Ele is not Present" << dl;
    }
    else
    {
        cout << "Ele is Present" << dl;
    }
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