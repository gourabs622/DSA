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
    int size;
    int top;
    int *s;
};

void create(Stack *st)
{
    printf("Enter the stack size \n");
    scanf("%d", &st->size);
    st->s = new int[st->size];
    st->top = -1;
}

void display(Stack st)
{
    printf("value inside Stack is\n");
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void isFull(Stack st)
{
    if (st.top == st.size - 1)
    {
        // return 1;
        printf("Stack Overflow\n");
    }
    else
    {
        // return 0;
        printf("Stack isn't Full\n");
    }
}

void isEmpty(Stack st)
{
    if (st.top == -1)
    {
        // return 1;
        printf("Stack Underflow\n");
    }
    else
    {
        // return 0;
        printf("Stack isn't Empty\n");
    }
}

void push(Stack *st, int value)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = value;
    }
}

int pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

void peek(Stack st, int pos)
{
    int x = -1;
    int ind = st.top - pos + 1;
    if (ind < 0)
    {
        printf("Position is Invalid\n");
    }
    else
    {
        x = st.s[ind];
    }
    // return x;
    printf("Value at this position is %d\n", x);
}

void stackTop(Stack st)
{
    if (st.top == -1)
    {
        printf("No elements are in Stack %d\n");
        // return -1;
    }
    // return st.s[st.top];
    printf("Value at this position is %d\n", st.s[st.top]);
}

inline void solve()
{
    fast();
    struct Stack st;
    create(&st);
    int choice, value, pos;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Peek\n");
        printf("7. StackTop\n");
        printf("8. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &value);
            push(&st, value);
            display(st);
            break;
        case 2:
            pop(&st);
            display(st);
            break;
        case 3:
            display(st);
            break;
        case 4:
            isEmpty(st);
            break;
        case 5:
            isFull(st);
            break;
        case 6:
            printf("Enter the position\n");
            scanf("%d", &pos);
            peek(st, pos);
            break;
        case 7:
            stackTop(st);
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