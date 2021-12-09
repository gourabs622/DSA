#include <bits/stdc++.h>
using namespace std;

void addwithxor()
{
    int a, b;
    cin >> a >> b;
    while (b > 0)
    {
        int c = a & b;
        a = a ^ b;
        b = c << 1;
    }
    cout << a << endl;
}

void subwithxor()
{
    int a, b;
    cin >> a >> b;
    while (b > 0)
    {
        int c = (~a) & b;
        a = a ^ b;
        b = c << 1;
    }
    cout << a << endl;
}

int main()
{
    addwithxor();
    subwithxor();

    return 0;
}
