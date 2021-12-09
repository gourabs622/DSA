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
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL; //head pointer is Global

inline struct Node *newNode(int key)
{
    struct Node *tt = new Node;
    tt->prev = NULL;
    tt->data = key;
    tt->next = NULL;
    return tt;
}

inline void displayDLL()
{
    struct Node *temp = head;
    while (temp)
    {
        // cout << temp << " " << temp->prev << " " << temp->data << " " << temp->next << dl;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << dl;
}

inline void InsertNode(int pos, int ele)
{
    struct Node *temp = head, *t = newNode(ele);
    if (head == NULL)
    {
        head = t;
        return;
    }
    if (pos == 0) //Before Head
    {
        t->next = head;
        head->prev = t;
        head = t;
    }
    else //After head
    {
        for (int i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            t->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = t;
            temp->next = t;
            t->prev = temp;
        }
        // else if (temp == NULL)
        // {
        //     temp=temp->prev;
        //     t->next = temp->next;
        //     if (temp->next != NULL)
        //         temp->next->prev = t;
        //     temp->next = t;
        //     t->prev = temp;
        // }
    }
}

// inline void InsertNode(int pos, int ele) //special case
// {
//     struct Node *tmp = head, *t = newNode(ele);
//     for (int i = 0; i < pos && tmp; i++)
//     {
//         tmp = tmp->next;
//     }
//     if (tmp)
//     {
//         t->next = tmp->next;
//         t->prev = tmp;
//         if (tmp->next != NULL)
//             tmp->next->prev = t;
//         tmp->next = t;
//     }
// }

inline void reverseDLL() //using sliding pointers
{
    struct Node *p, *q, *r;
    p = head;
    q = r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->prev = p;
        q->next = r;
    }
    head = q;
}

inline void deleteNodeDLL(int pos)
{
    struct Node *tmp = head;
    --pos;
    for (int i = 0; i < pos && tmp; i++)
    {
        tmp = tmp->next;
    }
    if (tmp == head)
    {
        head = head->next;
        tmp->next = NULL;
        head->prev = NULL;
        delete (tmp);
    }
    else if (tmp->next == NULL)
    {
        tmp->prev->next = NULL;
        delete (tmp);
    }
    else
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete (tmp);
    }
}

inline void rotateDLL(int pos)
{
    struct Node *tmp = head, *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    for (int i = 0; i < pos && tmp; i++)
    {
        tmp = tmp->next;
    }
    // cout << tmp->data << dl;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    last->next = head;
    head->prev = last;
    head = tmp;
}

inline void insert_in_SORTED_DLL(int ele)
{
    struct Node *tmp = head, *t = newNode(ele), *q = NULL;
    while (tmp)
    {
        if (tmp->data >= ele)
        {
            break;
        }
        q = tmp;
        tmp = tmp->next;
    }
    if (tmp == head)
    {
        t->next = head;
        head->prev = t;
        head = t;
    }
    else if (tmp == NULL)
    {
        // tmp = tmp->prev;
        q->next = t;
        t->prev = q;
    }
    else
    {
        tmp->prev->next = t;
        t->prev = tmp->prev;
        t->next = tmp;
        tmp->prev = t;
    }
}

inline void solve()
{
    fast();
    int n, ele;
    cin >> n >> ele;
    struct Node *tail, *temp;
    head = newNode(ele);
    tail = head;
    fi(i, 1, n)
    {
        cin >> ele;
        temp = newNode(ele);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    //display the DLL
    // displayDLL();

    //inserting in DLL
    // int pos;
    // cin >> pos >> ele;
    // InsertNode(pos, ele);
    // displayDLL();

    //reverse DLL
    // reverseDLL();
    // displayDLL();

    //delete Node DLL
    // int pos;
    // cin >> pos;
    // deleteNodeDLL(pos);
    // displayDLL();

    //rotateDLL
    // int pos;
    // cin >> pos;
    // rotateDLL(pos);
    // displayDLL();

    //insert in DLL
    // cin >> ele;
    // insert_in_SORTED_DLL(ele);
    // displayDLL();
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