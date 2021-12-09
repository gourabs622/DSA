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

/**********************In C style**********************/
struct Node
{
    int data;
    struct Node *pxn;
};
// struct Node *head = NULL; //head pointer is Global

inline struct Node *newNode(int key)
{
    struct Node *tt = new Node;
    tt->data = key;
    tt->pxn = NULL;
    return tt;
}

inline struct Node *XOR(struct Node *a, struct Node *b)
{
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

inline struct Node *insert(struct Node *head, int data)
{
    struct Node *mainNode = newNode(data);
    mainNode->pxn = head;
    if (head != NULL)
    {
        head->pxn = XOR(mainNode, head->pxn);
    }
    head = mainNode;
    return head;
}

inline void printList(struct Node *head)
{
    struct Node *trav = head, *prev = NULL, *curr = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = XOR(prev, trav->pxn);
        prev = curr;
        curr = trav;
    }
    cout << dl;
    trav = prev;
    while (trav)
    {
        cout << trav->data << " ";
        trav = XOR(curr, trav->pxn);
        curr = prev;
        prev = trav;
    }
    cout << dl;
}

// inline void deleteXORLL()/not working
// {
//     struct Node *trav = head, *prev = NULL, *curr = head;
//     while (trav)
//     {
//         trav = XOR(prev, trav->pxn);
//         prev = curr;
//         curr = trav;
//         delete (prev);
//     }
// }

inline void solve()
{
    fast();
    struct Node *head = NULL;
    int n, ele;
    cin >> n;
    fi(i, 0, n)
    {
        cin >> ele;
        head = insert(head, ele);
    }
    printList(head);
    // deleteXORLL();
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