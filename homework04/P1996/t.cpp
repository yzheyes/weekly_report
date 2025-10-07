// P1996 约瑟夫问题
// n, m <= 100，使用队列模拟报数出圈，输出出圈顺序。

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	if (!(cin >> n >> m)) return 0;

	queue<int> q;
	for (int i = 1; i <= n; ++i) q.push(i);

	vector<int> out;
	int cnt = 0;
	while (!q.empty()) {
		++cnt;
		int x = q.front(); q.pop();
		if (cnt == m) {
			out.push_back(x);
			cnt = 0;
		} else {
			q.push(x);
		}
	}

	for (size_t i = 0; i < out.size(); ++i) {
		if (i) cout << ' ';
		cout << out[i];
	}
	cout << '\n';
	return 0;
}

