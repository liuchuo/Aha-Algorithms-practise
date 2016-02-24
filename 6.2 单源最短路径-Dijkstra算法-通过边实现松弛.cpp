4.2 单源最短路径-Dijkstra算法-通过边实现松弛
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

	int dis[10];
	for (int i = 1; i <= n; i++) {
		dis[i] = e[1][i];
	}

	int book[10];
	for (int i = 1; i <= n; i++) {
		book[i] = 0;
	}
	book[1] = 1;// book == 0 表示是估计值，book == 1 表示是确定值

	//Dijkstra算法核心语句
	for (int i = 1; i <= n - 1; i++) {
		min = 99999999;
		for (int j = 1; j <= n; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1; //在所有估计值中找到最小的值，把它标记为确定值

		for (int v = 1; v <= n; v++) {
			if (e[u][v] < 99999999) {
				if (dis[u] + e[u][v] < dis[v])
					dis[v] = dis[u] + e[u][v];
			}
		}//通过这个确定值为中转点更新别的所有值的最短路径(松弛别的两个顶点连接的边)
	}

	//print result
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";

	return 0;
}