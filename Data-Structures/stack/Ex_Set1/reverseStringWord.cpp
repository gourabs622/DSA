#include <bits/stdc++.h>
using namespace std;

void solve()
{
    //code
    string s;
    cin >> s;
    s += '.';
    vector<string> vs;
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '.')
        {
            temp += s[i];
        }
        else
        {
            vs.push_back(temp);
            temp.clear();
        }
    }
    reverse(vs.begin(), vs.end());
    // for (int i = 0; i < vs.size(); i++)
    // {
    //     cout << vs[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < vs.size() - 1; i++)
    {
        cout << vs[i] << '.';
    }
    cout << vs[vs.size() - 1] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}