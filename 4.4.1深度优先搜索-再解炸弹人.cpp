4.4.1 深度优先搜索-再解炸弹人
#include <iostream>
using namespace std;

struct note {
	int x;
	int y;
};

struct note que[401];

char a[20][20];
int book[20][20] = {0};

int head = 1;
int tail = 1;

int getnum(int i, int j) {
	int sum, x, y;
	sum = 0;

	//向上统计可以消灭的敌人数
	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x--;
	}

	//向下统计可以消灭的敌人数
	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x++;
	}

	//向左统计可以消灭的敌人数
	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y--;
	}

	//向右统计可以消灭的敌人数
	x = i;
	y = j;
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y++;
	}

	return sum;
}

int main() {
	int sum, max = 0, mx, my, n, m, startx, starty, tx, ty;
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;

	sum = getnum(startx, starty);

	int next[4][2] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}
	};

	cin >> n >> m >> startx >> starty;

	for (int i = 0; i <= n - 1; i++)
		cin >> a[i];

	while (head < tail) {

		for (int k = 0; k <= 3; k++) {
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx < 0 || ty > n - 1 || ty < 0 || ty > m - 1)
				continue;

			if (a[tx][ty] == '.' && book[tx][ty] == 0) {
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

				sum = getnum(startx, starty);

				if (sum > max) {
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
		//枚举完当前点的四个方向之后，head++;
		head++;
	}

	cout << "将炸弹放置在(" << mx << "," << my << ")处，可以消灭" << max << "个敌人";

	return 0;
}