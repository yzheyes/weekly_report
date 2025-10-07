#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (a <= 2)
        {
            cout << 1 << '\n';
            continue;
        }
        int f1 = 1, f2 = 1, f = 0;
        for (int i = 3; i <= a; ++i)
        {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        cout << f2 << '\n';
    }
    return 0;
}
