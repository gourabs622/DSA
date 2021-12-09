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
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

// queue<Node *> q;

inline void createBST(int ele) //inserting function Iteratively
{
    struct Node *tail = NULL, *p, *temp;
    p = new Node;
    p->data = ele;
    p->lchild = p->rchild = NULL;
    if (root == NULL)
    {
        root = p;
        return;
    }
    temp = root;
    while (temp)
    {
        tail = temp;
        if (temp->data == ele)
        {
            return;
        }
        else if (temp->data < ele)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    if (ele > tail->data)
    {
        tail->rchild = p;
    }
    else
    {
        tail->lchild = p;
    }
}

inline Node *createBST_Recursive(struct Node *temp, int ele) //inserting function Recursively
{
    struct Node *p;
    if (temp == NULL)
    {
        p = new Node;
        p->data = ele;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (temp->data < ele)
    {
        temp->rchild = createBST_Recursive(temp->rchild, ele); //main point
    }
    else
    {
        temp->lchild = createBST_Recursive(temp->lchild, ele); //main point
    }
    return temp;
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

inline bool BST_Search(int ele)
{
    struct Node *temp;
    if (root == NULL)
    {
        return false;
    }
    temp = root;
    while (temp)
    {
        if (temp->data == ele)
        {
            return true;
        }
        else if (temp->data < ele)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    return false;
}

inline bool BST_RSearch(struct Node *temp, int ele)
{
    if (temp == NULL)
    {
        return false;
    }
    if (temp->data == ele)
    {
        return true;
    }
    else if (temp->data < ele)
    {
        return BST_RSearch(temp->rchild, ele);
    }
    else
    {
        return BST_RSearch(temp->lchild, ele);
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

inline struct Node *InPre(struct Node *k)
{
    while (k && k->rchild != NULL)
    {
        k = k->rchild;
    }
    return k;
}

inline struct Node *InSucc(struct Node *k)
{
    while (k && k->lchild != NULL)
    {
        k = k->lchild;
    }
    return k;
}

inline struct Node *Delete(struct Node *tmp, int ele)
{
    struct Node *q; //this will help us to track predecesor and successor
    if (tmp == NULL)
    {
        return NULL;
    }
    if (tmp->lchild == NULL && tmp->rchild == NULL) //deletion process of leaf node
    {
        if (tmp == root)
        {
            root == NULL;
        }
        else if (tmp->data == ele)
        {
            free(tmp);
            return NULL;
        }
        else if (tmp->data > ele)
        {
            tmp->lchild = Delete(tmp->lchild, ele);
        }
        else
        {
            tmp->rchild = Delete(tmp->rchild, ele);
        }
    }
    if (tmp->data == ele)
    {
        if (Height(tmp->lchild) >= Height(tmp->rchild)) //checking if left subtree is greater the we delete from that part
        {
            q = InPre(tmp->lchild);
            tmp->data = q->data;
            tmp->lchild = Delete(tmp->lchild, q->data);
        }
        else //otherwise delete from right subtree
        {
            q = InSucc(tmp->rchild);
            tmp->data = q->data;
            tmp->rchild = Delete(tmp->rchild, q->data);
        }
    }
    else if (tmp->data > ele)
    {
        tmp->lchild = Delete(tmp->lchild, ele);
    }
    else
    {
        tmp->rchild = Delete(tmp->rchild, ele);
    }
    return tmp;
}

inline void solve()
{
    fast();
    int n, ele;
    cin >> n;

    //Iteratively inserting elements in BST
    fi(i, 0, n)
    {
        cin >> ele;
        //Creating a Binary Search tree
        createBST(ele);
    }

    //Recursively inserting elements in BST(we need only function)
    // cin >> ele;
    // root = createBST_Recursive(root, ele);
    // fi(i, 1, n)
    // {
    //     cin >> ele;
    //     createBST_Recursive(root, ele);
    // }

    // Inorder Traversal
    inOrderTrav(root);
    cout << dl;

    //counting height of a tree
    // cout << Height(root) << dl;

    //Searching for a value
    // cin >> ele;
    // if (BST_Search(ele)) //Iterative
    // if (BST_RSearch(root, ele)) //Recursive
    // {
    //     cout << "Element Found" << dl;
    // }
    // else
    // {
    //     cout << "Element is not Found" << dl;
    // }

    //Deleting node from BST
    cin >> ele;
    Delete(root, ele);
    // cout << root->data << dl;

    //Inorder Traversal
    inOrderTrav(root);
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