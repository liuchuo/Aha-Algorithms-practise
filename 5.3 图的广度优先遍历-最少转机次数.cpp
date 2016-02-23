5.3 图的广度优先遍历-最少转机次数
#include <iostream>
using namespace std;
sturct note {
	int x;
	int s;
};

int main() {
	struct que[2501];
	int e[51][51] = {0};
	int book[51] = {0};
	int n, m, start, end;
	cin >> n >> m >> start >> end;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999999;
		}
	}

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	int head = 1;
	int tail = 1;
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[1] = 1;

	int cur;
	int flag = 0;
	while (head < tail) {
		cur = que[head].x;
		for (int i = 1; i <= n; i++) {
			if (e[cur][i] != 99999999 && book[i] == 0) {
				que[tail].x = i;
				que[tail].s = que[head].s + 1;
				tail++;
				book[i] = 1;
			}
			if (que[tail].x == end) {
				flag = 1;
				break;//这个break跳出了for循环 到达了下面一个break处
			}
		}
		if (flag == 1)
			break; //一旦广度优先遍历的一个结点就是终点，那么直接退出大循环，整个遍历过程结束
		head++;
	}

	cout << que[tail - 1].s;
	return 0;
}
