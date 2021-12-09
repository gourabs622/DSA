#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, sum = 0;
    cin >> x;
    while (x > 0)
    {
        sum = sum + (x & 1);
        x = x >> 1;
    }
    cout << sum << endl;
    return 0;
}