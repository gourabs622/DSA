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

inline bool IteBinarySearch(vector<int> v, int key)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == key)
        {
            return true;
        }
        else if (v[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

inline bool RecBinarySearch(vector<int> v, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == key)
        {
            return true;
        }
        else if (v[mid] < key)
        {
            return RecBinarySearch(v, mid + 1, high, key);
        }
        else
        {
            return RecBinarySearch(v, low, mid - 1, key);
        }
    }
    return false;
}

inline void solve()
{
    fast();
    int n, ele;
    cin >> n;
    vector<int> v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    cin >> ele;

    /* Simple Binary Search Algo --> O(logn) and constant space */
    // bool found = IteBinarySearch(v, ele); //iterative approach
    // bool found = RecBinarySearch(v, 0, n - 1, ele); //recursive approach
    // if (found)
    // {
    //     cout << "Element Found" << dl;
    // }
    // else
    // {
    //     cout << "Element Not Found" << dl;
    // }

    /* More efficient with less no of comparisons --> max-O(logn) and constant space */
    int low = 0, high = n - 1;
    while (high - low > 1) //main point
    {
        // int mid = (low + high) / 2;
        int mid = low + (high - low) / 2;
        if (v[mid] <= ele)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] == ele)
    {
        cout << "Element Found at index " << low << dl;
        return;
    }
    if (v[high] == ele)
    {
        cout << "Element Found at index " << high << dl;
        return;
    }
    cout << "Element Not Found" << dl;
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