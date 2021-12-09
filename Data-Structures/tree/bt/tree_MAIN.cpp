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

struct Node
{
    struct Node *lchind;
    int data;
    struct Node *rchind;
};

struct Node *root = NULL;

queue<Node *> q;

inline void createTree()
{
    struct Node *p, *t;
    int ele;
    // cout << "Enter root data-> "; // cout and cin are not working properly
    // cin >> ele;
    printf("Enter root data-> ");
    scanf("%d", &ele);
    root = new Node;
    root->data = ele;
    root->lchind = root->rchind = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        // cout << "Enter left_child data of -> " << p->data;
        // cin >> ele;
        printf("Enter left_child data of %d-> ", p->data);
        scanf("%d", &ele);
        if (ele != -1)
        {
            t = new Node;
            t->data = ele;
            t->lchind = t->rchind = NULL;
            p->lchind = t;
            q.push(t);
        }
        // cout << "Enter right_child data of -> " << p->data;
        // cin >> ele;
        printf("Enter right_child data of %d-> ", p->data);
        scanf("%d", &ele);
        if (ele != -1)
        {
            t = new Node;
            t->data = ele;
            t->lchind = t->rchind = NULL;
            p->rchind = t;
            q.push(t);
        }
    }
}

inline void preOrderTrav(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrderTrav(p->lchind);
        preOrderTrav(p->rchind);
    }
}
inline void inOrderTrav(struct Node *p)
{
    if (p)
    {
        inOrderTrav(p->lchind);
        cout << p->data << " ";
        inOrderTrav(p->rchind);
    }
}
inline void postOrderTrav(struct Node *p)
{
    if (p)
    {
        postOrderTrav(p->lchind);
        postOrderTrav(p->rchind);
        cout << p->data << " ";
    }
}

inline void solve()
{
    fast();
    //Creating a Tree
    createTree();

    /* Tree Traversals */
    //Preorder Traversals
    preOrderTrav(root);
    cout << dl;

    //Preorder Traversals
    inOrderTrav(root);
    cout << dl;

    //Preorder Traversals
    postOrderTrav(root);
    cout << dl;

    //Preorder Traversals
    // levelOrderTrav(root);
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