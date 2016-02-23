4.5.1 广度优先搜索-宝岛探险
广度优先搜索是建立一个队列数组，两个指针head和tail
#include <iostream>
using namespace std;
struct note {
	int x;
	int y;
};

int main() {
	struct note que[2501];
	int head = 1;
	int tail = 1;
	int n, m;
	cin >> n >> m;

	int startx, starty;
	cin >> startx >> starty;

	int a[51][51];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	int book[51][51] = {0};

	que[tail].x = startx;
	que[tail].y = starty;
	tail++;

	book[startx][starty] = 1;

	int next[4][2] = {
		{1, 0};
		{0, 1};
		{-1, 0};
		{0, -1}
	};

	while (head < tail) {
		for (int k = 0; k <= 3; k++) {
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx < 1 || tx > n || ty < 1 || ty > m)
				continue;

			if (a[tx][ty] > 0 && book[tx][ty] == 0) {
				sum++;
				book[tx][ty] = 1;

				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;
	}

	cout << sum;
	return 0;
}