4.5.2 深度优先搜索-宝岛探险
#include <iostream>
using namespace std;
int a[51][51];
int book[51][51];//全局变量自动全部初始化为0
int n, m;
int sum = 0;

int next[4][2] = {
	{1, 0};
	{0, 1};
	{-1, 0};
	{0, -1}
};

void dfs(int x, int y) {
	int tx, ty;
	for (int k = 0; k <= 3; k++) {
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || tx > n || ty < 1 || ty > m)
			continue;
		if (a[tx][ty] > 0 && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			sum++;
			dfs(tx, ty);
		}
	}
	return ;
}

int main() {
	int startx, starty;
	cin >> n >> m >> startx >> starty;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	dfs(startx, starty);
	cout << sum;
	
	return 0;
}