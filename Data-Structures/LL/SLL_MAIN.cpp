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
struct node
{
    int data;
    struct node *next_ptr;
} *head = NULL;

struct node *secLLhead = NULL; //for merging second LL

// struct node *newhead = NULL; //cloning to a LL

struct node *newNode(int n) //Creating a Node
{
    struct node *tt = new node;
    tt->data = n;
    tt->next_ptr = NULL;
    return tt;
}

inline void displayLL()
{
    struct node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next_ptr;
    }
    cout << dl;
}

inline int CountNode()
{
    struct node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next_ptr;
    }
    return cnt;
}

inline int SumALL()
{
    struct node *temp = head;
    int sum = 0;
    while (temp)
    {
        sum += temp->data;
        temp = temp->next_ptr;
    }
    return sum;
}

inline int MaxLL()
{
    struct node *temp = head;
    int mm = INT_MIN;
    while (temp)
    {
        mm = max(mm, temp->data);
        temp = temp->next_ptr;
    }
    return mm;
}

inline int MinLL()
{
    struct node *temp = head;
    int mm = INT_MAX;
    while (temp)
    {
        mm = min(mm, temp->data);
        temp = temp->next_ptr;
    }
    return mm;
}

inline struct node *SearchELE_LL(int ele)
{
    struct node *temp = head;
    while (temp)
    {
        if (ele == temp->data)
        {
            return temp;
        }
        temp = temp->next_ptr;
    }
    return NULL;
}

inline struct node *Improve_SearchELE_LL(int ele)
{
    struct node *q, *temp = head;
    while (temp)
    {
        if (ele == temp->data)
        {
            q->next_ptr = temp->next_ptr;
            temp->next_ptr = head;
            head = temp;
            return temp;
        }
        q = temp;
        temp = temp->next_ptr;
    }
    return NULL;
}

inline void InsertNode(int pos, int ele)
{
    struct node *temp = head, *t = newNode(ele);
    if (pos == 0) //Before Head
    {
        t->next_ptr = head;
        head = t;
    }
    else //After head
    {
        for (int i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next_ptr;
        }
        if (temp)
        {
            t->next_ptr = temp->next_ptr;
            temp->next_ptr = t;
        }
    }
}

inline void InsertAtTheEnd(int ele)
{
    struct node *temp = head, *t = newNode(ele);
    while (temp->next_ptr != NULL) //Important point
    {
        temp = temp->next_ptr;
    }
    temp->next_ptr = t;
    t->next_ptr = NULL;
}

inline void DeleteAlt()
{
    struct node *p = head, *q = head;
    p = p->next_ptr;
    while (p->next_ptr != NULL)
    {
        q->next_ptr = p->next_ptr;
        q = p->next_ptr;
        if (q->next_ptr == NULL)
        {
            return;
        }
        free(p);
        p = q->next_ptr;
    }
    q->next_ptr = NULL;
}

inline void DeleteALL()
{
    struct node *p = head;
    head = head->next_ptr;
    while (head)
    {
        free(p);
        p = head;
        head = head->next_ptr;
    }
}

inline void DeleteNodeLL(int x)
{
    struct node *temp = head, *q = NULL;
    int cnt = 0;
    // --x;
    while (temp->next_ptr != NULL || q->next_ptr != NULL)
    {
        // cout<<"HI"<<dl;
        ++cnt;
        if (cnt == x)
        {
            if (temp == head)
            {
                head = head->next_ptr;
                free(temp);
                return;
            }
            else
            {
                q->next_ptr = temp->next_ptr;
                free(temp);
                return;
            }
        }
        q = temp;
        temp = temp->next_ptr;
    }
}

inline void RemoveDup()
{
    struct node *t = head, *q = head;
    t = t->next_ptr;
    while (t)
    {
        if (t->data != q->data)
        {
            q = t;
            t = t->next_ptr;
        }
        else
        {
            q->next_ptr = t->next_ptr;
            free(t);
            t = q->next_ptr;
        }
    }
}

inline void reverseLL()
{
    struct node *p, *q, *r;
    p = head;
    q = r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next_ptr;
        q->next_ptr = r;
    }
    head = q;
}

inline void MergeLL()
{
    struct node *traversing, *becomeHead;
    if (head->data <= secLLhead->data)
    {
        traversing = becomeHead = head;
        head = head->next_ptr;
    }
    else
    {
        traversing = becomeHead = secLLhead;
        secLLhead = secLLhead->next_ptr;
    }
    traversing->next_ptr = NULL;
    while (head != NULL && secLLhead != NULL)
    {
        if (head->data <= secLLhead->data)
        {
            traversing->next_ptr = head;
            traversing = head;
            head = head->next_ptr;
        }
        else
        {
            traversing->next_ptr = secLLhead;
            traversing = secLLhead;
            secLLhead = secLLhead->next_ptr;
        }
        traversing->next_ptr = NULL;
    }
    while (head != NULL)
    {
        traversing->next_ptr = head;
        traversing = head;
        head = head->next_ptr;
        traversing->next_ptr = NULL;
    }
    while (secLLhead != NULL)
    {
        traversing->next_ptr = secLLhead;
        traversing = secLLhead;
        secLLhead = secLLhead->next_ptr;
        traversing->next_ptr = NULL;
    }
    head = becomeHead;
}

inline void pairSwap()
{
    //using vector
    // vector<int> v;
    // struct node *t = head;
    // while (t)
    // {
    //     v.push_back(t->data);
    //     t = t->next_ptr;
    // }
    // fi(i, 0, v.size())
    // {
    //     if (i == v.size() - 1)
    //     {
    //         break;
    //     }
    //     swap(v[i], v[i + 1]);
    //     i++;
    // }
    // t = head;
    // int i = 0;
    // while (t)
    // {
    //     t->data = v[i++];
    //     t = t->next_ptr;
    // }

    //using constant space
    struct node *p, *q;
    p = q = head;
    q = q->next_ptr;
    while (p != NULL && q != NULL)
    {
        swap(p->data, q->data);
        p = q->next_ptr;
        if (p == NULL)
        {
            break;
        }
        q = p->next_ptr;
    }
}

inline void rotateLL(int k)
{
    struct node *last = head;
    while (last->next_ptr != NULL)
    {
        last = last->next_ptr;
    }
    struct node *pos = head;
    int cnt = 0;
    while (pos->next_ptr != NULL)
    {
        ++cnt;
        if (cnt == k)
        {
            break;
        }
        pos = pos->next_ptr;
    }
    last->next_ptr = head;
    head = pos->next_ptr;
    pos->next_ptr = NULL;
}

// inline struct node *findIntersection()//hoini
// {
//     struct node *head3 = NULL, *t = head, *p = secLLhead;
//     while (t || p)
//     {
//         if (t->data == p->data)
//         {
//             struct node *n = newNode(t->data);
//             head3 = n;
//             t = t->next_ptr;
//             p = p->next_ptr;
//             break;
//         }
//         else
//         {
//             if (t->data < p->data)
//             {
//                 t = t->next_ptr;
//             }
//             else
//             {
//                 p = p->next_ptr;
//             }
//         }
//     }
//     if (head3 == NULL)
//     {
//         return head3;
//     }
// node *temp = head3;
// while (t || p)
// {
//     if (t->data == p->data)
//     {
//         node *n = newNode(t->data);
//         temp->next_ptr = n;
//         temp = n;
//         t = t->next_ptr;
//         p = p->next_ptr;
//         break;
//     }
//     else
//     {
//         if (t->data < p->data)
//         {
//             t = t->next_ptr;
//         }
//         else
//         {
//             p = p->next_ptr;
//         }
//     }
// }
// temp->next_ptr = NULL;
// return head3;
// }

/**********************In C++ style********************/
// class node
// {
// public:
//     int data;
//     node *next_ptr;
// };

inline void solve()
{
    fast();
    int n, ele;
    cin >> n >> ele;
    struct node *tail, *temp;
    head = newNode(ele);
    tail = head;
    fi(i, 1, n)
    {
        cin >> ele;
        temp = newNode(ele);
        tail->next_ptr = temp;
        tail = temp;
    }

    //Displaying LL
    // displayLL();

    //Count Nodes in LL
    // cout << CountNode() << dl;

    //Sum of all elements in LL
    // cout << SumALL() << dl;

    //Max element in LL
    // cout << MaxLL() << dl;

    //Min element in LL
    // cout << MinLL() << dl;

    //Searching for an element in LL
    // int elem;
    // cin >> elem;
    // struct node *hhh = SearchELE_LL(elem);
    // cout << (hhh == NULL ? "Not Present" : "Present") << dl;

    //Improving Searching for an element in LL by move to head (Something Wrong)
    // int element;
    // cin >> element;
    // struct node *hh = Improve_SearchELE_LL(element);
    // cout << (hh == NULL ? "Not Present" : "Present") << dl;
    // displayLL();

    //Inserting New Node
    // int elee, pos;
    // cin >> pos >> elee;
    // InsertNode(pos, elee);
    // displayLL();

    //Inserting At the End
    // int elee;
    // cin >> elee;
    // InsertAtTheEnd(elee);
    // displayLL();

    //Delete Altenative Nodes
    // DeleteAlt();
    // displayLL();

    //Clone to a given LL
    // newhead = head;
    // struct node *lastclone = head, *move, *tt = newhead;
    // lastclone = lastclone->next_ptr;
    // while (lastclone)
    // {
    //     move = newNode(lastclone->data);
    //     tt->next_ptr = move;
    //     tt = move;
    //     lastclone = lastclone->next_ptr;
    // }
    // tt = newhead;
    // while (tt)
    // {
    //     cout << tt->data << " ";
    //     tt = tt->next_ptr;
    // }

    //Delete LL
    // DeleteALL();
    // if (head == NULL)
    // {
    //     cout << "LL deleted" << dl;
    // }

    //Delete Node LL
    // int pos;
    // cin >> pos;
    // DeleteNodeLL(pos);
    // displayLL();

    // Remove Duplicates from LL
    // RemoveDup();
    // displayLL();

    //Reversing a LL
    // reverseLL();
    // displayLL();

    //Merging two sorted LL
    // int m, ele2;
    // cin >> m >> ele2;
    // struct node *secLLtail, *secLLtemp;
    // secLLhead = newNode(ele2);
    // secLLtail = secLLhead;
    // fi(i, 1, m)
    // {
    //     cin >> ele2;
    //     secLLtemp = newNode(ele2);
    //     secLLtail->next_ptr = secLLtemp;
    //     secLLtail = secLLtemp;
    // }
    // MergeLL();
    // displayLL();

    //Pairwise Swap
    // pairSwap();
    // displayLL();

    //Rotate LL
    // int pos;
    // cin >> pos;
    // rotateLL(pos);
    // displayLL();

    //Intersection of LL//hoini
    // int m, ele2;
    // cin >> m >> ele2;
    // struct node *secLLtail, *secLLtemp;
    // secLLhead = newNode(ele2);
    // secLLtail = secLLhead;
    // fi(i, 1, m)
    // {
    //     cin >> ele2;
    //     secLLtemp = newNode(ele2);
    //     secLLtail->next_ptr = secLLtemp;
    //     secLLtail = secLLtemp;
    // }
    // struct node *head3 = findIntersection();
    // struct node *tmp = head3;
    // while (tmp)
    // {
    //     cout << tmp->data << " ";
    //     tmp = tmp->next_ptr;
    // }
    // cout << dl;

    DeleteALL();
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