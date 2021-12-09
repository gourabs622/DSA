#include <bits/stdc++.h>
using namespace std;

void withArith()
{
    int a, b;
    cin >> a >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << " " << b << endl;
}

void withArith2()
{
    int a, b;
    cin >> a >> b;
    a = a * b;
    b = a / b;
    a = a / b;
    cout << a << " " << b << endl;
}

void withXor()
{
    int a, b;
    cin >> a >> b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b << endl;
}

int main()
{
    // withArith();
    // withArith2();
    // withXor();

    return 0;
}
