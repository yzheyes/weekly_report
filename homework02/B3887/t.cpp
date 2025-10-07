#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, cnt41 = 0, cnt63 = 0, mx = 0;
    for (int i = 0; i < 8; ++i)
    {
        cin >> x;
        mx = max(mx, x);
        if (x >= 41)
            ++cnt41;
        if (x >= 63)
            ++cnt63;
    }
    if (mx >= 118)
        cout << 10 << '\n';
    else if (cnt63 >= 4)
        cout << 8 << '\n';
    else if (cnt41 >= 4)
        cout << 3 << '\n';
    else
        cout << 1 << '\n';
    return 0;
}
