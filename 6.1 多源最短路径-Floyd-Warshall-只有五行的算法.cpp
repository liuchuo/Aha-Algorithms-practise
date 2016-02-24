6.1 多源最短路径-Floyd-Warshall-只有五行的算法
#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int e[10][10];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999999;
		}
	}

	int t1, t2, t3;
	for (int i = 1; i <= m; i++) {
		cin >> t1 >> t2 >> t3;
		e[t1][t2] = t3;
	}

	//Floyd-Warshall算法核心语句
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];

	//k为中转结点，第一个k循环，表示允许所有的点进行中转

	//print result
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << e[i][j];
		}
		cout << endl;
	}
	return 0;
}