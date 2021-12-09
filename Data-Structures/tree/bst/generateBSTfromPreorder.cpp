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

//we can generate a BST with only preorder traversal given below is the code
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

stack<Node *> sn;

inline struct Node *crtNode(int ele)
{
    struct Node *t;
    t = new Node;
    t->data = ele;
    t->lchild = t->rchild = NULL;
    return t;
}

inline struct Node *createBST(struct Node *t, vector<int> v)
{
    struct Node *p;
    if (t == NULL)
    {
        t = crtNode(v[0]);
        root = t;
    }
    p = root;
    fi(i, 1, v.size())
    {
        if (v[i] < p->data)
        {
            sn.push(p);
            t = crtNode(v[i]);
            p->lchild = t;
            p = t;
        }
        else
        {
            if (sn.empty())
            {
                t = crtNode(v[i]);
                p->rchild = t;
                p = t;
            }
            else if (v[i] < sn.top()->data)
            {
                t = crtNode(v[i]);
                p->rchild = t;
                p = t;
            }
            else
            {
                bool needChange = false;
                while (!sn.empty())
                {
                    p = sn.top();
                    sn.pop();
                    if (sn.empty())
                    {
                        needChange = true;
                        break;
                    }
                    if (v[i] < sn.top()->data)
                    {
                        t = crtNode(v[i]);
                        p->rchild = t;
                        p = t;
                        break;
                    }
                }
                if (needChange)
                {
                    t = crtNode(v[i]);
                    p->rchild = t;
                    p = t;
                }
            }
        }
    }
    return root;
}

inline void inOrderTrav(struct Node *p)
{
    if (p)
    {
        inOrderTrav(p->lchild);
        cout << p->data << " ";
        inOrderTrav(p->rchild);
    }
}

inline void preOrderTrav(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrderTrav(p->lchild);
        preOrderTrav(p->rchild);
    }
}

inline int Height(struct Node *tmp)
{
    if (tmp == NULL)
    {
        return -1;
    }
    return max(Height(tmp->lchild), Height(tmp->rchild)) + 1;
}

inline void solve()
{
    //creating BST from given preorder traversal
    fast();
    int n, ele;
    cin >> n;
    vector<int> v(n);
    fi(i, 0, n)
    {
        cin >> v[i];
    }
    createBST(root, v);
    inOrderTrav(root);
    cout << dl;
    preOrderTrav(root);
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