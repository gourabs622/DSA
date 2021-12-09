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

struct DEQueue
{
    struct DEQueue *prev;
    int data;
    struct DEQueue *next;
} *front = NULL, *rare = NULL;

inline struct DEQueue *create(int val)
{
    struct DEQueue *p = new DEQueue;
    p->data = val;
    p->next = p->prev = NULL;
    return p;
}

inline void display()
{
    struct DEQueue *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

inline void push_front(int val)
{
    struct DEQueue *q = create(val);
    if (front == NULL)
    {
        front = rare = q;
    }
    else
    {
        q->next = front;
        front->prev = q;
        front = q;
    }
}

inline void push_back(int val)
{
    struct DEQueue *q = create(val);
    if (rare == NULL)
    {
        front = rare = q;
    }
    else
    {
        rare->next = q;
        q->prev = rare;
        rare = q;
    }
}

inline int pop_front()
{
    struct DEQueue *p = front;
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
            front = rare = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }
        delete (p);
    }
    return x;
}

inline int pop_back()
{
    struct DEQueue *p = rare;
    int x = -1;
    if (rare == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = rare->data;
        if (front == rare)
        {
            front = rare = NULL;
        }
        else
        {
            rare = rare->prev;
            rare->next = NULL;
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

inline void frontValue()
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

inline void backValue()
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

inline void solve()
{
    fast();
    int choice, value, pos;

    while (1)
    {
        printf("1. Push_Front\n");
        printf("2. Push_Back\n");
        printf("3. Pop_Front\n");
        printf("4. Pop_Back\n");
        printf("5. Display\n");
        printf("6. IsEmpty\n");
        printf("7. Front Value\n");
        printf("8. Back Value\n");
        printf("9. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push in front \n");
            scanf("%d", &value);
            push_front(value);
            display();
            break;
        case 2:
            printf("Enter value to push in back \n");
            scanf("%d", &value);
            push_back(value);
            display();
            break;
        case 3:
            printf("Value popped from front %d\n", pop_front());
            display();
            break;
        case 4:
            printf("Value popped from back %d\n", pop_back());
            display();
            break;
        case 5:
            display();
            break;
        case 6:
            isEmpty();
            break;
        case 7:
            frontValue();
            break;
        case 8:
            backValue();
            break;
        case 9:
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