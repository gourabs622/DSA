#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

/*          					GOURAB SARKAR					            */

using namespace std;

typedef long long ll;
typedef long double ld;
#define PI 3.141592653589793238
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define PBO pop_back()
#define permute next_permutation
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define ALLA(arr, sz) arr, arr + sz
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define dl "\n"
#define mm(a, val) memset(a, val, sizeof(a))
#define b_s binary_search
#define u_b upper_bound
#define l_b lower_bound
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ld EPS = 1e-9;
const int N = 1e6 + 7;
const ll NL = 1000000000000000005LL;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 9;
const int mod2 = 998244353;

#define fi(a, b, c) for (int a = b; a < c; ++a)
#define fd(a, b, c) for (int a = c - 1; a >= b; --a)
#define fei(a, b, c) for (int a = b; a <= c; ++a) //for any particular range
#define fed(a, b, c) for (int a = c; a >= b; --a) //for any particular range
#define fs(a, b) for (auto &a : b)                //for loop shortcut

// inline void OPEN()
// {
//     #ifdef ONLINE_JUDGE
//         freopen("input.in", "r", stdin);
//         freopen("output.in", "w", stdout);
//     #endif
// }

//Graph
//Adj Matrix
const int maxN = 1e4 + 1, maxM = 1e4 + 1;
int adjt[maxN][maxM] = {0};
vector<bool> vist(maxN, false);
queue<int> q;

//Adj List
vector<int> adj[N];
vector<bool> vis(N, false);
queue<int> qq;

inline void bfsAM(int i, int n)
{
    cout << i << " ";
    vist[i] = true;
    q.push(i);
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        fi(j, 0, n)
        {
            if (adjt[val][j] == 1 && vist[j] == false)
            {
                cout << j << " ";
                vist[j] = true;
                q.push(j);
            }
        }
    }
}

inline void bfsAL(int i)
{
    cout << i << " ";
    vis[i] = true;
    qq.push(i);
    while (!qq.empty())
    {
        int val = qq.front();
        qq.pop();
        for (auto it = adj[val].begin(); it != adj[val].end(); it++)
        {
            if (vis[*it] == false)
            {
                cout << *it << " ";
                vis[*it] = true;
                qq.push(*it);
            }
        }
    }
}

inline void AM() //for adjacency matrix
{
    int n, e;
    cin >> n >> e;
    fi(i, 0, e)
    {
        int u, v;
        cin >> u >> v;
        adjt[u][v] = 1;
        adjt[v][u] = 1;
    }
    // fi(i, 0, n)
    // {
    //     fi(j, 0, n)
    //     {
    //         cout << adjt[i][j] << " ";
    //     }
    //     cout << dl;
    // }
    bfsAM(1, n);
}

inline void AL() //for Adjacency List
{
    int n, e;
    cin >> n >> e;
    fi(i, 0, e)
    {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    // fi(i, 0, n)
    // {
    //     for (auto it = adj[i].begin(); it != adj[i].end(); it++)
    //     {
    //         cout << *it << " ";
    //     }
    //     cout << dl;
    // }
    bfsAL(1);
}

inline void solve()
{
    fast();
    // AM();
    AL();
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