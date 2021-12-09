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

inline bool backspaceCompare(string S, string T)
{
    stack<char> sc;
    stack<char> sct;
    fi(i, 0, S.length())
    {
        if (S[i] == '#')
        {
            if (!sc.empty())
            {
                sc.pop();
            }
        }
        else
        {
            sc.push(S[i]);
        }
    }
    fi(i, 0, T.length())
    {
        if (T[i] == '#')
        {
            if (!sct.empty())
            {
                sct.pop();
            }
        }
        else
        {
            sct.push(T[i]);
        }
    }
    string fst = "", scd = "";
    while (!sc.empty())
    {
        fst += sc.top();
        sc.pop();
    }
    while (!sct.empty())
    {
        scd += sct.top();
        sct.pop();
    }
    if (fst == scd)
    {
        return true;
    }
    return false;
}

inline void solve()
{
    string fst, scd;
    cin >> fst >> scd;
    (backspaceCompare(fst, scd)) ? cout << "true" << dl : cout << "false" << dl;
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