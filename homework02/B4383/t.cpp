#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    long long before = 0, zeros = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x == 1)
        { // 扶苏的行李到了，停止计数
            cout << before << ' ' << zeros << '\n';
            return 0;
        }
        ++before; // 还没到她的行李，计入总数
        if (x == 0)
            ++zeros; // 普通行李计数
    }
    return 0;
}
