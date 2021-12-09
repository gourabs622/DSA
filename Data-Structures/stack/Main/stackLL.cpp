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

struct Stack
{
    int data;
    struct Stack *next;
} *top = NULL;

inline struct Stack *create(int val)
{
    struct Stack *t = new Stack;
    t->data = val;
    t->next = NULL;
    return t;
}

inline void display()
{
    struct Stack *p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

inline void push(int val)
{
    struct Stack *p = create(val);
    if (p == NULL)
    {
        printf("Stack is Full\n");
        return;
    }
    if (top == NULL)
    {
        top = p;
    }
    else
    {
        p->next = top;
        top = p;
    }
}

inline int pop()
{
    struct Stack *p = top;
    int x = -1;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        x = top->data;
        top = top->next;
        delete (p);
    }
    return x;
}

inline void isEmpty()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack isn't Empty\n");
    }
}

inline void topValue()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top value is %d\n", top->data);
    }
}

inline int size()
{
    struct Stack *p = top;
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
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. IsEmpty\n");
        printf("5. Top\n");
        printf("6. Size\n");
        printf("7. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &value);
            push(value);
            display();
            break;
        case 2:
            printf("Popped Value is %d\n", pop());
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            topValue();
            break;
        case 6:
            printf("Size of Stack is %d\n", size());
            break;
        case 7:
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