#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<string> lines(n);
    for (int i = 0; i < n; ++i)
        cin >> lines[i];

    // 解析为数值网格，并统计频次
    vector<vector<int>> grid(n);
    int m = (int)lines[0].size() / 2;
    vector<int> cnt(256, 0);

    auto hex2byte = [](char c) -> int
    {
        if ('0' <= c && c <= '9')
            return c - '0';
        if ('a' <= c && c <= 'f')
            return c - 'a' + 10;
        if ('A' <= c && c <= 'F')
            return c - 'A' + 10;
        return 0;
    };

    for (int i = 0; i < n; ++i)
    {
        const string &s = lines[i];
        vector<int> row;
        row.reserve(s.size() / 2);
        for (int j = 0; j < (int)s.size(); j += 2)
        {
            int v = (hex2byte(s[j]) << 4) | hex2byte(s[j + 1]);
            row.push_back(v);
            cnt[v]++;
        }
        grid[i] = move(row);
    }

    // 选出 Top-16 灰阶：按(次数降序, 值升序)
    vector<int> vals(256);
    iota(vals.begin(), vals.end(), 0);
    sort(vals.begin(), vals.end(), [&](int a, int b)
         {
        if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
        return a < b; });

    vector<int> chosen(16);
    for (int i = 0; i < 16; ++i)
        chosen[i] = vals[i];

    // 灰阶 -> 编号 映射（不在Top16的置为-1）
    vector<int> id(256, -1);
    for (int i = 0; i < 16; ++i)
        id[chosen[i]] = i;

    // 输出第1行：32个十六进制字符（按编号顺序的原灰阶，两位大写）
    auto toHex2 = [](int x) -> string
    {
        static const char *hex = "0123456789ABCDEF";
        string s;
        s.push_back(hex[(x >> 4) & 0xF]);
        s.push_back(hex[x & 0xF]);
        return s;
    };
    for (int i = 0; i < 16; ++i)
    {
        cout << toHex2(chosen[i]);
    }
    cout << "\n";

    // 输出压缩后的图像：每像素1位十六进制字符（编号0..F）
    auto oneHex = [](int x) -> char
    {
        static const char *hex = "0123456789ABCDEF";
        return hex[x & 0xF];
    };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int v = grid[i][j];
            int code = id[v];
            if (code == -1)
            {
                // 找最近的：|v - chosen[k]| 最小；若并列，选编号更小
                int bestCode = 0;
                int bestDist = abs(v - chosen[0]);
                for (int k = 1; k < 16; ++k)
                {
                    int d = abs(v - chosen[k]);
                    if (d < bestDist)
                    {
                        bestDist = d;
                        bestCode = k;
                    }
                    // 并列不更新（保持编号更小的优先）
                }
                code = bestCode;
            }
            cout << oneHex(code);
        }
        cout << "\n";
    }

    return 0;
}
