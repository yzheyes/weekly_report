// B3688 [语言月赛202212] 旋转排列
// 循环：右移一位（把最后一个移到开头），打印当前排列；若最后一个等于 n 则结束。

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	if (!(cin >> n)) return 0;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i];

	while (true) {
		// 右旋 1 位：最后一个到最前面
		int last = p.back();
		for (int i = n - 1; i >= 1; --i) p[i] = p[i - 1];
		p[0] = last;

		// 输出当前排列
		for (int i = 0; i < n; ++i) {
			if (i) cout << ' ';
			cout << p[i];
		}
		cout << '\n';

		// 判断是否结束
		if (p.back() == n) break;
	}

	return 0;
}

