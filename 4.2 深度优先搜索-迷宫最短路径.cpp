4.2 深度优先搜索-迷宫最短路径
#include <iostream>
using namespace std;
int a[51][51];
int book[51][51];
int p, q;
int n, m;
int min = 999999;
void dfs(int x, int y, int step) {
	int next[4][2] = {
		{0, 1},
		{1, 0},
		{-1, 0},
		{0, -1}
	};
	int tx, ty;
	if (x == p && y = q) {
		if (step < min) {
			min = step;
		}
		return;
	}

	for (int k = 0; k <= 3; k++) {
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || ty < 1 || tx > m || ty > n)
			continue;
		if (a[tx][ty] == 0 && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> p >> q;
	int startx, starty;
	cin >> startx >> starty;
	book[startx][starty] = 1;
	dfs(startx, starty, 1);
	cout << min;
	return 0;
}

