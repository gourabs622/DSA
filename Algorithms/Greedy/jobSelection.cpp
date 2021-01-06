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
    return (a.S > b.S);
}

inline void solve() //Naive Solution with Time complexity O(n^2)
{
    fast();
    ll n, id, a, b, max_dline = 0, cnt_job = 0;
    cin >> n;
    vpl deadline_profit;
    fi(i, 0, n)
    {
        cin >> id >> a >> b;
        max_dline = max(max_dline, a);
        deadline_profit.PB({a, b});
    }
    // sort(ALL(deadline_profit), [](auto const &a, auto const &b) { return a.S > b.S; });
    sort(ALL(deadline_profit), bysec);
    vll prof(max_dline, 0);
    fi(i, 0, deadline_profit.size())
    {
        ll curr_dline = deadline_profit[i].F;
        fd(j, 0, curr_dline)
        {
            if (prof[j] == 0)
            {
                prof[j] = deadline_profit[i].S;
                cnt_job++;
                break;
            }
        }
    }
    cout << cnt_job << " " << accumulate(ALL(prof), 0) << dl;
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