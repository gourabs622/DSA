#include <bits/stdc++.h>
using namespace std;

void flipppp()
{
    int a, b;
    cin >> a >> b;
    int t = a;
    int count = 0, m = 1;
    while (t != b)
    {
        if ((m & a) == (m & b))
        {
            m = m << 1;
        }
        else
        {
            count++;
            t = t ^ m;
            m = m << 1;
        }
    }
    cout << count << endl;
}

void flipppp1()
{
    int a, b;
    cin >> a >> b;
    int t = a ^ b;
    int count = 0, m = 1;
    while (t)
    {
        count += t & m;
        t >>= 1;
    }
    cout << count << endl;
}

int main()
{
    flipppp();
    flipppp1();

    return 0;
}
