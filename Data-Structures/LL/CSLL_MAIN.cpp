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
    int data;
    struct Node *next;
} *head = NULL;

inline void displayCLL()
{
    struct Node *tmp = head;
    do
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    } while (tmp != head);
    cout << dl;
}

inline void RdisplayCLL(struct Node *tmp)
{
    static int flag = 0;
    if (tmp != head || flag != 1)
    {
        flag = 1;
        cout << tmp->data << " ";
        RdisplayCLL(tmp->next);
    }
    flag = 0;
}

inline int cntCLL()
{
    int cnt = 0;
    struct Node *tmp = head;
    do
    {
        cnt++;
        tmp = tmp->next;
    } while (tmp != head);
    return cnt;
}

inline void SortedInsertCLL(int x)
{
    struct Node *tmp = head, *inst = new Node, *back = NULL;
    inst->data = x;
    inst->next = NULL;
    if (head == NULL)
    {
        head = inst;
        head->next = head;
    }
    else
    {
        do
        {
            if (tmp->data >= x)
            {
                if (tmp == head)
                {
                    do
                    {
                        back = tmp;
                        tmp = tmp->next;
                    } while (tmp != head);
                    inst->next = back->next;
                    back->next = inst;
                    head = inst;
                    return;
                }
                else
                {
                    back->next = inst;
                    inst->next = tmp;
                    return;
                }
            }
            back = tmp;
            tmp = tmp->next;
        } while (tmp != head);
        inst->next = back->next;
        back->next = inst;
    }
}

// inline void reverseCLL()//hoini
// {
//     struct Node *p = head, *q = NULL, *r = NULL;
//     if (head->next = head)
//     {
//         return;
//     }
//     else if (p->next->next == head)
//     {
//         p = p->next;
//         head = p;
//     }
//     r = p;
//     r->next = NULL;
//     q = p->next;
//     p = q->next;
//     do
//     {
//         q->next = r;
//         r = q;
//         q = p;
//         p = p->next;
//     } while (p != head);
//     q->next = r;
//     head->next = q;
//     head = q;
// }

inline void solve()
{
    fast();
    int n, ele;
    cin >> n >> ele;
    struct Node *last, *t;
    head = new Node;
    head->data = ele;
    head->next = head;
    last = head;
    fi(i, 1, n)
    {
        cin >> ele;
        t = new Node;
        t->data = ele;
        t->next = last->next;
        last->next = t;
        last = t;
    }

    //display cirLL
    // displayCLL();
    // RdisplayCLL(head);
    // cout << dl;

    //count Nodes in CLL
    // cout << cntCLL() << dl;

    //sorted Insert an element
    // cin >> ele;
    // SortedInsertCLL(ele);
    // displayCLL();

    //reverse CLL
    // reverseCLL();
    // displayCLL();
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