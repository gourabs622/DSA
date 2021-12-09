#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;
int main()
{
    int i;
    char c;
    // string s;
    float f;
    double d;
    long long ll;
    // cout << typeof(i) << endl;
    cout << type_name<decltype(i)>() << '\n';
    // cout << typeid(c).name() << endl;
    // cout << typeid(s).name() << endl;
    // cout << typeid(f).name() << endl;
    // cout << typeid(d).name() << endl;
    // cout << typeid(ll).name() << endl;

    return 0;
}