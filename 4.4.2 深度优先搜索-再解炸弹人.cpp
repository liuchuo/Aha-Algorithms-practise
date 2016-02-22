4.4.2 深度优先搜索-再解炸弹人
#include <iostream>
using namespace std;
char a[20][21];
int book[20][20];
int max, mx, my, n, m;
int getnum(int i, int j) {
	int sum, x, y;
	sum = 0;

	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x--;
	}

	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x++;
	}

	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y--;
	}

	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y++;
	}
	return sum;
}

void dfs(int x, int y) {
	int next[4][2] = {
		{0, 1},
		{0, -1},
		{-1, 0},
		{1, 0};
	}

	sum = getnum(x, y);
	if (sum > max) {
		max = sum;
		mx = x;
		my = y;
	}

	for (int k = 0; k <= 3; k++) {
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1)
			continue;
		if (a[tx][ty] == '.' && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
	return ;
}
int main() {
	int startx, starty;
	cin >> n >> m;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= m - 1; j++) {
			cin >> a[i][j];
		}
	}

	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	dfs(startx, starty);
	printf("将炸弹放置在(%d, %d), 最多可以消灭%d个敌人\n", mx, my, max);
	return 0;
}












