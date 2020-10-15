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

ll gs[1001][10001];

// inline ll targetSum_Recursive(vll v, ll ind, ll req_sum)
// {
//     if (ind == 0 && req_sum != 0)
//     {
//         return 0;
//     }
//     if (req_sum == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return (targetSum_Recursive(v, ind - 1, req_sum - v[ind - 1]) + targetSum_Recursive(v, ind - 1, req_sum));
//     }
// }

// inline ll targetSum_TopDown(vll v, ll ind, ll req_sum)
// {
//     if (ind == 0 && req_sum != 0)
//     {
//         return 0;
//     }
//     if (req_sum == 0)
//     {
//         return 1;
//     }
//     if (gs[ind][req_sum] != -1)
//     {
//         return gs[ind][req_sum];
//     }
//     else
//     {
//         gs[ind][req_sum] = (targetSum_TopDown(v, ind - 1, req_sum - v[ind - 1]) + targetSum_TopDown(v, ind - 1, req_sum));
//         return gs[ind][req_sum];
//     }
// }

inline int findTargetSumWays(vector<int> &nums, int S) //see this
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum < S || (S + sum) % 2 != 0)
        return 0;
    sum = (S + sum) / 2;
    int dp[1001][100001];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= nums[i - 1])
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

inline void solve()
{
    fast();
    int n, t_sum;
    cin >> n >> t_sum;
    vector<int> v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    cout << findTargetSumWays(v, t_sum) << dl;
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