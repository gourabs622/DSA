#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

/*          					GOURAB SARKAR					            */

using namespace std;

typedef   long long 				ll;
typedef   long double 				ld;
#define   PI 					3.141592653589793238
#define   MP 					make_pair
#define   F 					first
#define   S 					second
#define   PB 					push_back
#define   PBO 					pop_back()
#define   permute 				next_permutation
#define   ALL(v) 				v.begin(), v.end()
#define   SORT(v) 				sort(ALL(v))
#define   REVERSE(v) 				reverse(ALL(v))
#define   ALLA(arr, sz) 			arr, arr + sz
#define   SORTA(arr, sz) 			sort(ALLA(arr, sz))
#define   REVERSEA(arr, sz) 			reverse(ALLA(arr, sz))
#define   dl 					"\n"
#define   mm(a,val)				memset(a,val,sizeof(a))
#define   b_s					binary_search
#define   u_b					upper_bound
#define   l_b					lower_bound
#define   test  \
          int t;     \
          cin >> t; \
          while (t--)
#define   fast()                        \
          ios_base::sync_with_stdio(false); \
          cin.tie(NULL);                    \
          cout.tie(NULL);

const     ld EPS = 				1e-9;
const     int N = 				1000000005;
const     ll NL = 				1000000000000000005LL;
const     int mod = 				1e9+7;
const     int mod1 = 				1e9+9;
const     int mod2 = 				998244353;


#define   fi(a, b, c) 				for(int a = b; a < c; ++a)
#define   fd(a, b, c) 				for(int a = c - 1; a >= b; --a)
#define   fei(a, b, c) 				for(int a = b; a <= c; ++a) //for any particular range
#define   fed(a, b, c) 				for(int a = c; a >= b; --a) //for any particular range
#define   fs(a, b) 				for(auto &a : b)               //for loop shortcut

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

int gs[1001][1001];

inline int LPSubstr_Recursion(string a, int i, int j) {
    if (i>j) {
        return 0;
    }
    else if (i==j) {
        return 1;
    }
    else if (a[i]==a[j]) {
        int res = j-i-1;
        if (res==LPSubstr_Recursion(a, i+1, j-1)) {
            return res+2;
        }
        else {
            return max(LPSubstr_Recursion(a, i+1, j), LPSubstr_Recursion(a, i, j-1));
        }
    }
    else {
        return max(LPSubstr_Recursion(a, i+1, j), LPSubstr_Recursion(a, i, j-1));
    }
}

inline int LPSubstr_TopDown(string a, int i, int j) {
    if (gs[i][j]!=0) {
        return gs[i][j];
    }
    if (i>j) {
        return 0;
    }
    else if (i==j) {
        return 1;
    }
    else if (a[i]==a[j]) {
        int res = j-i-1;
        if (res==LPSubstr_Recursion(a, i+1, j-1)) {
            gs[i][j] = res+2;
            return gs[i][j];
        }
        else {
            gs[i][j]= max(LPSubstr_Recursion(a, i+1, j), LPSubstr_Recursion(a, i, j-1));
            return gs[i][j];
        }
    }
    else {
        gs[i][j]= max(LPSubstr_Recursion(a, i+1, j), LPSubstr_Recursion(a, i, j-1));
        return gs[i][j];
    }
}

inline int LPSubstr_BottomUp(string a) {
    mm(gs, 0);
    fd(i, 0, a.length()+1) {
        fi(j, 0, a.length()+1) {
            if (i>j) {
                gs[i][j]=0;
            }
            else if (i==j) {
                gs[i][j]=1;
            }
            else if (a[i-1]==a[j-1]) {
                int need = j-i-1;
                int len = (gs[i+1][j-1]==need?2+gs[i+1][j-1]:0);
                gs[i][j]=max(len, max(gs[i][j-1], gs[i+1][j]));
            }
            else {
                gs[i][j]=max(gs[i+1][j], gs[i][j-1]);
            }
        }
    }
    return gs[1][a.length()];
}

inline void solve() {
    fast();
    string a;
    cin >> a;
    int ans = LPSubstr_BottomUp(a);
    cout << ans << dl;
    fi(i, 0, a.length()+1) {
        fi(j, 0, a.length()+1) {
            cout<<gs[i][j]<<" ";
        }
        cout<<dl;
    }
}

int main() {
    fast();
    // OPEN();
    // solve();
    test{
        solve();
    }

    return 0;
}