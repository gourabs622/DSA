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
const int N = 1000000005;
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

// const int maxN = 1e5 + 1;
// vector<int> adj[N];
// vector<bool> vis(N, false);

const int nn = 101;
int A[nn][nn], I[nn][nn];

inline void multi(int n)
{
    int res[101][101] = {{0}};
    fi(i, 0, n)
    {
        fi(j, 0, n)
        {
            fi(k, 0, n)
            {
                res[i][j] += (A[i][k] * I[k][j]);
            }
        }
    }
    fi(i, 0, n)
    {
        fi(j, 0, n)
        {
            I[i][j] = res[i][j];
        }
    }
}

inline void matrixExpo(int n, int m)
{
    fi(i, 0, m)
    {
        multi(n);
    }
    fi(i, 0, n)
    {
        fi(j, 0, n)
        {
            A[i][j] = I[i][j];
        }
    }
}

inline void makeIdentityMatrix(int n)
{
    fi(i, 0, n)
    {
        fi(j, 0, n)
        {
            if (i == j)
            {
                I[i][j] = 1;
            }
            else
            {
                I[i][j] = 0;
            }
        }
    }
}

inline void printMatrix(int n)
{
    fi(i, 0, n)
    {
        fi(j, 0, n)
        {
            cout << A[i][j] << " ";
        }
        cout << dl;
    }
}

inline void printIdentityMatrix(int n)
{
    fi(i, 0, n)
    {
        fi(j, 0, n)
        {
            cout << I[i][j] << " ";
        }
        cout << dl;
    }
}

inline void solve()
{
    fast();
    int n, m;
    cin >> n >> m;
    fi(i, 0, n)
    {
        fi(j, 0, n)
        {
            cin >> A[i][j];
        }
    }
    makeIdentityMatrix(n);
    matrixExpo(n, m);
    // printIdentityMatrix(n);
    printMatrix(n);
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