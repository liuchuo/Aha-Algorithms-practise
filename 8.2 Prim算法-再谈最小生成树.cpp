8.2 Prim算法-再谈最小生成树
用dis数组来记录生成树到各个顶点的距离，也就是说只需要靠近“生成树”中任意一个“树顶点”就行
1.从任意一个定点开始构造生成树，用book数组来标记哪些顶点已经加入了生成树
2.用数组dis记录生成树到各个定点的距离
3.从数组dis中选出离生成树最近的顶点加入到生成树中
4.重复第3步，直到生成树中有n个顶点为止

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, m;
	int i, j, k;
	int min;
	int t1, t2, t3;
	int e[7][7], dis[7], book[7] = {0};
	int inf = 99999999;
	int count = 0, sum = 0;
	// count用来记录生成树中顶点的个数，sum用来存储路劲之和
	scanf("%d %d", &n, &m);

	//init数组e[7][7];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}

	//scanf all the edge
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		// 无向图，存两遍
		e[t1][t2] = t3;
		e[t2][t1] = t3;
	}

	//init数组dis
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];

	// Prim算法核心
	book[1] = 1;
	count++;
	while(count < n) {
		min = inf;
		for (i = 1; i <= n; i++) {
			if (book[i] == 0 && dis[i] < min) {
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum = sum + dis[j];

		for (k = 1; k <= n; k++) {
			if (book[k] == 0 && dis[k] > e[j][k])
				dis[k] = e[j][k];
		}
	}

	printf("%d", sum);
	
	return 0;
}


