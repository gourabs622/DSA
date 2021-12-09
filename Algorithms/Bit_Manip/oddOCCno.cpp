#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int r = 0;
    for (int i = 0; i < v.size(); i++)
    {
        r = r ^ v[i];
    }
    cout << r << endl;

    return 0;
}