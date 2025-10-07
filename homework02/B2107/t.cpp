#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    for (int i = 0; i < m; ++i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (j != n - 1)
                cout << ' ';
            cout << a[j][i];
        }
        cout << '\n';
    }
    return 0;
}
