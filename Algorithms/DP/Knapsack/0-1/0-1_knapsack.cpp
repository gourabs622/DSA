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

// ll gs[1001][1001]; // for non optimized
// ll gs[2][1001]; // space optimized 1
ll gs[1001]; // space optimized 2

// inline ll knapsackRecursive(vll prof, vll wt, ll tot_size, ll capacity)
// {
//     if (tot_size == 0 || capacity <= 0)
//     {
//         return 0;
//     }
//     if (wt[tot_size - 1] > capacity)
//     {
//         return knapsackRecursive(prof, wt, tot_size - 1, capacity);
//     }
//     else
//     {
//         return max(prof[tot_size - 1] + knapsackRecursive(prof, wt, tot_size - 1, capacity - wt[tot_size - 1]), knapsackRecursive(prof, wt, tot_size - 1, capacity));
//     }
// }

// inline ll knapsackTopDown(vll prof, vll wt, ll tot_size, ll capacity)
// {
//     if (tot_size == 0 || capacity <= 0)
//     {
//         return 0;
//     }
//     if (gs[tot_size][capacity] != -1)
//     {
//         return gs[tot_size][capacity];
//     }
//     if (wt[tot_size - 1] > capacity)
//     {
//         gs[tot_size][capacity] = knapsackTopDown(prof, wt, tot_size - 1, capacity);
//         return gs[tot_size][capacity];
//     }
//     else
//     {
//         gs[tot_size][capacity] = max(prof[tot_size - 1] + knapsackTopDown(prof, wt, tot_size - 1, capacity - wt[tot_size - 1]), knapsackTopDown(prof, wt, tot_size - 1, capacity));
//         return gs[tot_size][capacity];
//     }
// }

// inline void knapsackBottomUp(vll prof, vll wt, ll capacity)
// {
//     ll tot_size = prof.size();
//     fi(i, 0, tot_size + 1)
//     {
//         fi(j, 0, capacity + 1)
//         {
//             if (i == 0 || j == 0)
//             {
//                 gs[i][j] = 0;
//             }
//             // else
//             // {
//             //     gs[i][j] = -1;
//             // }
//         }
//     }
//     fi(i, 1, tot_size + 1)
//     {
//         fi(j, 1, capacity + 1)
//         {
//             if (wt[i - 1] > j)
//             {
//                 gs[i][j] = gs[i - 1][j];
//             }
//             else
//             {
//                 gs[i][j] = max(prof[i - 1] + gs[i - 1][j - wt[i - 1]], gs[i - 1][j]);
//             }
//         }
//     }
//     cout << gs[tot_size][capacity] << dl;
// }

// inline void knapsackBottomUp_Optimized_1(vll prof, vll wt, ll capacity)// space optimization --> O(2*capacity)
// {
//     ll tot_size = prof.size();
//     memset(gs, 0, sizeof(gs));
//     fi(i, 0, tot_size)
//     {
//         fi(j, 1, capacity+1)
//         {
//             if (wt[i]<=j)
//             {
//                 gs[1][j]=max(prof[i]+gs[0][j-wt[i]], gs[0][j]);
//             }
//             else {
//                 gs[1][j]=gs[0][j];
//             }
//         }
//         fi(j, 1, capacity+1)
//         {
//             gs[0][j]=gs[1][j];
//         }
//     }
//     cout<<gs[0][capacity]<<dl;
// }

inline void knapsackBottomUp_Optimized_2(vll prof, vll wt, ll capacity)// space optimization --> O(capacity)
{
    ll tot_size = prof.size();
    memset(gs, 0, sizeof(gs));
    fi(i, 0, tot_size)
    {
        for (int j=capacity;j>=wt[i];j--)
        {
            gs[j]=max(prof[i]+gs[j-wt[i]], gs[j]);
        }
    }
    cout<<gs[capacity]<<dl;
}

inline void solve()
{
    fast();
    ll tot_size, capacity;
    cin >> tot_size >> capacity;
    vll prof(tot_size), wt(tot_size);
    fi(i, 0, tot_size)
    {
        cin >> prof[i];
    }
    fi(i, 0, tot_size)
    {
        cin >> wt[i];
    }
    knapsackBottomUp_Optimized_2(prof, wt, capacity);
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