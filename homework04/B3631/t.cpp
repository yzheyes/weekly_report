// B3631 单向链表
// 维护一个仅含值 1 的初始链表，支持：
// 1 x y: 在 x 后插入 y
// 2 x: 查询 x 的后继（若无则输出 0）
// 3 x: 删除 x 的后继（若无则忽略）
// 数值范围 1..1e6，操作数 <= 1e5，所有数字始终互不相同。

#include <iostream>
using namespace std;

static int nxt[1000005]; // nxt[v] 表示 v 的后继；0 表示无后继

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	if (!(cin >> q)) return 0;

	// 初始只有一个元素 1，默认 nxt[1] = 0；其他均为 0
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int x, y; cin >> x >> y;
			// 将 y 插入到 x 后面
			nxt[y] = nxt[x];
			nxt[x] = y;
		} else if (op == 2) {
			int x; cin >> x;
			cout << nxt[x] << '\n';
		} else if (op == 3) {
			int x; cin >> x;
			// 删除 x 的后继（若存在）
			int y = nxt[x];
			if (y != 0) {
				nxt[x] = nxt[y];
				// 不必清零 nxt[y]，因为题意保证数字不再重复使用
			}
		}
	}

	return 0;
}

