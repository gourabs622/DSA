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
    int size;
    int front;
    int rare;
    int *Q;
};

inline void create(struct DEQueue *q)
{
    printf("Enter the array size ");
    scanf("%d", &q->size);
    q->front = q->rare = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

inline void display(struct DEQueue q)
{
    fi(i, q.front + 1, q.rare + 1)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

inline void push_front(struct DEQueue *q, int val)
{
    if (q->front == -1)
    {
        printf("can't be insert element at front\n");
    }
    else
    {
        q->Q[q->front] = val;
        q->front--;
    }
}

inline void push_back(struct DEQueue *q, int val)
{
    if (q->rare == q->size - 1)
    {
        printf("can't be insert element at back\n");
    }
    else
    {
        q->rare++;
        q->Q[q->rare] = val;
    }
}

inline int pop_front(struct DEQueue *q)
{
    int x = -1;
    if (q->rare == q->front)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

inline int pop_back(struct DEQueue *q)
{
    int x = -1;
    if (q->rare == q->front)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        x = q->Q[q->rare];
        q->rare--;
    }
    return x;
}

inline void isEmpty(struct DEQueue q)
{
    if (q.front == q.rare)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue isn't Empty\n");
    }
}

inline void isFull(struct DEQueue q)
{
    if (q.rare == q.size - 1 && q.front == -1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Queue isn't Full\n");
    }
}

inline void front(struct DEQueue q)
{
    if (q.front == q.rare)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front value is %d\n", q.Q[q.front + 1]);
    }
}

inline void back(struct DEQueue q)
{
    if (q.front == q.rare)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Back value is %d\n", q.Q[q.rare]);
    }
}

inline void solve()
{
    fast();
    struct DEQueue q;
    create(&q);
    int choice, value, pos;

    while (1)
    {
        printf("1. Push_Front\n");
        printf("2. Push_Back\n");
        printf("3. Pop_Front\n");
        printf("4. Pop_Back\n");
        printf("5. Display\n");
        printf("6. IsEmpty\n");
        printf("7. IsFull\n");
        printf("8. Front\n");
        printf("9. Back\n");
        printf("10. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &value);
            push_front(&q, value);
            display(q);
            break;
        case 2:
            printf("Enter the value\n");
            scanf("%d", &value);
            push_back(&q, value);
            display(q);
            break;
        case 3:
            printf("Dequeue Value is %d\n", pop_front(&q));
            display(q);
            break;
        case 4:
            printf("Dequeue Value is %d\n", pop_back(&q));
            display(q);
            break;
        case 5:
            display(q);
            break;
        case 6:
            isEmpty(q);
            break;
        case 7:
            isFull(q);
            break;
        case 8:
            front(q);
            break;
        case 9:
            back(q);
            break;
        case 10:
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