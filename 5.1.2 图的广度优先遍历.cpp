5.1.2 图的广度优先遍历
#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int book[101] = {0};
	int e[101][101];

	//init matrix
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999999;
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	int que[10001];
	int head = 1;
	int tail = 1;

	que[tail] = 1;
	tail++;
	book[1] = 1;

	int cur;
	while (head < tail) {
		cur = que[head];
		for (int i = 1; i <= n; i++) {
			if (e[cur][i] == 1 && book[i] == 0) {
				que[tail] = 1;
				tail++;
				book[i] = 1;
			}

			if (tail > n)
				break;
		}
		head++;
	}

	for (int i = 1; i < tail; i++)
		cout << que[i] << " ";

	return 0;
}