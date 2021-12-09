#include <bits/stdc++.h>
using namespace std;
int a[200] = {0};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int start = 2;
        int length = 1;
        a[0] = 1;
        int counter = 1;
        int num = 0;
        while (start <= n)
        {
            counter = 0;
            while (counter < length)
            {
                a[counter] = a[counter] * start;
                a[counter] = a[counter] + num;
                num = a[counter] / 10;
                a[counter] = a[counter] % 10;
                counter++;
            }
            while (num != 0)
            {
                a[length] = num % 10;
                num = num / 10;
                length++;
            }
            start++;
        }
        for (int i = length - 1; i >= 0; i--)
        {
            printf("%d", a[i]);
        }
        printf("\n");
    }

    return 0;
}