/* Generate all binary permutations such that there are more or equal 1’s than 0’s before every point in all permutations */
// Problem Link --> https://www.geeksforgeeks.org/generate-binary-permutations-1s-0s-every-point-permutations/

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

inline void solve()
{
    fast();
    int len, length;
    cin >> len;
    length = len;

    /* using queue DS to generate all bin string -> max-O(n * lengthOfString) and constant space */
    if (len == 1)
    {
        cout << 1 << dl;
        return;
    }
    else if (len == 2)
    {
        cout << 11 << " " << 10 << dl;
        return;
    }
    else if (len == 3)
    {
        cout << 111 << " " << 110 << " " << 101 << dl;
        return;
    }
    len = pow(2, len) - 1;
    queue<string> q;
    q.push("1");
    vector<string> vs;
    while (len)
    {
        int onecnt = 0, zerocnt = 0;
        string s1, s2;
        s1 = q.front();
        // cout << s1 << dl;
        fi(i, 0, s1.length())
        {
            (s1[i] == '1') ? onecnt++ : zerocnt++;
            if (zerocnt > onecnt)
            {
                goto LABELL;
            }
        }
        if (onecnt >= zerocnt && s1.length() == length)
        {
            vs.PB(s1);
        }
    LABELL:
        q.pop();
        s2 = s1;
        s1 += '0';
        s2 += '1';
        q.push(s1);
        q.push(s2);
        len--;
    }
    SORT(vs);
    REVERSE(vs);
    fi(i, 0, vs.size())
    {
        cout << vs[i] << " ";
    }
    cout << dl;
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