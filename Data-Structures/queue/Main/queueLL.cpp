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

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *front = NULL, *rare = NULL;

inline struct Queue *create(int val)
{
    struct Queue *t = new Queue;
    t->data = val;
    t->next = NULL;
    return t;
}

inline void display()
{
    struct Queue *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

inline void enqueue(int val)
{
    struct Queue *p = create(val);
    if (front == NULL && rare == NULL)
    {
        front = rare = p;
    }
    else
    {
        rare->next = p;
        rare = p;
    }
}

inline int dequeue()
{
    struct Queue *p = front;
    int x = -1;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = front->data;
        if (front == rare)
        {
            front = NULL;
            rare = NULL;
        }
        else
        {
            front = front->next;
        }
        delete (p);
    }
    return x;
}

inline void isEmpty()
{
    if (front == NULL && rare == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue isn't Empty\n");
    }
}

inline void frontvalue()
{
    if (front == NULL && rare == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front value is %d\n", front->data);
    }
}

inline void backvalue()
{
    if (front == NULL && rare == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Back value is %d\n", rare->data);
    }
}

inline int size()
{
    struct Queue *p = front;
    int sz = 0;
    while (p)
    {
        sz++;
        p = p->next;
    }
    return sz;
}

inline void solve()
{
    fast();
    int choice, value, pos;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. IsEmpty\n");
        printf("5. Front\n");
        printf("6. Back\n");
        printf("7. Size\n");
        printf("8. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &value);
            enqueue(value);
            display();
            break;
        case 2:
            printf("Dequeue Value is %d\n", dequeue());
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            frontvalue();
            break;
        case 6:
            backvalue();
            break;
        case 7:
            printf("Size of Queue is %d\n", size());
            break;
        case 8:
            exit(1);
        }
    }
}

int main()
{
    fast();
    // OPEN();
    solve();
    // test
    // {
    //     solve();
    // }

    return 0;
}