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
    ll t;     \
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

#define fi(a, b, c) for (ll a = b; a < c; ++a)
#define fd(a, b, c) for (ll a = c - 1; a >= b; --a)
#define fei(a, b, c) for (ll a = b; a <= c; ++a) //for any particular range
#define fed(a, b, c) for (ll a = c; a >= b; --a) //for any particular range
#define fs(a, b) for (auto &a : b)               //for loop shortcut

inline string IntToString(ll a)
{
    ostringstream str1;
    str1 << a;
    string geek = str1.str();
    return geek;
}

inline ll StringToInt(string a)
{
    stringstream geek(a);
    ll x = 0;
    geek >> x;
    return x;
}

inline ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

inline ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

inline ll power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = pow(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

inline ll sumDigits(ll n)
{
    return n == 0 ? 0 : n % 10 + sumDigits(n / 10);
}

inline bool isprime(ll n)
{
    vector<bool> prime(n + 1, true);
    // ll prime[n + 1];
    // memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    if (n == 1)
        return false;
    else if (prime[n])
        return true;
    else
        return false;
}

inline bool ispalin(string num)
{
    string t = num;
    reverse(t.begin(), t.end());
    if (t == num)
        return true;
    return false;
}

inline void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            printf("%lld ", i);
            n = n / i;
        }
    }
    if (n > 2)
        printf("%lld ", n);
}

inline ll fact(ll n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

inline ll ncr(ll n, ll r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

inline ll npr(ll n, ll r)
{
    return fact(n) / fact(n - r);
}

inline void Natural_Divisors(ll n)
{
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                printf("%lld ", i);

            else
                printf("%lld %lld ", i, n / i);
        }
    }
}

inline ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;

            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

inline bool isPerfectSquare(long double x)
{
    long double sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}

inline ll Count_primeFactors(ll n)
{
    ll cnt = 0;
    while (n % 2 == 0)
    {
        // printf("%d ", 2);
        cnt++;
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            // printf("%lld ", i);
            cnt++;
            n = n / i;
        }
    }
    if (n > 2)
    {
        // printf("%lld ", n);
        cnt++;
    }
    return cnt;
}

// void checktimer()
// {
//     clock_t start, end;
//     start = clock();
//     //Put Down Your Code Here

//     end = clock();
//     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
//     cout << "Execution time: " << time_taken
//          << " secs";
// }

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
    //write your code below
    string s;
    cin >> s;
    string temp = s;
    int n = s.length();
    fi(i, 0, n)
    {
        if (s[i] == '6')
        {
            s[i] = '5';
        }
        if (temp[i] == '5')
        {
            temp[i] = '6';
        }
    }
    ll fst = StringToInt(s);
    ll scd = StringToInt(temp);
    cout << (fst + scd) << dl;
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