6.4 Bellman-Ford——解决负权边
核心算法四行：
for (k = 1; k <= n - 1; k++)
	for (i = 1; i <= m; i++)
		if (dis[v[i]] > dis[u[i]] + w[i])
			dis[v[i]] = dis[u[i]] + w[i];
进行n-1轮的原因：在一个含有n个顶点的图中，任意两点之间的最短路径最多包含n-1边。

//检验负权回路
  如果在进行最短路径算法后，仍然有可以松弛的边，那么就是存在负权回路
flag = 0;
for (i = 1; i <= m; i++) 
	if (dis[v[i]] > dis[u[i]] + w[i])
		flag = 1;
if (flag == 1)
	printf("此图含有负权回路");


如果在新一轮的松弛中数组dis没有发生变化，则可以提前跳出循环
#include <iostream>
#include <cstdio>
//n个结点，m条边
using namespace std;
int main() {
	int dis[10], bak[10], n, m, u[10], v[10], w[10], check, flag;
	int inf = 99999999;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &u[i], &v[i], &w[i]);

	for (int i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;

	for (int k = 1; k <= n - 1; k++) {
		for (int i = 1; i <= n; i++)
			bak[i] = dis[i];
		for (int i = 1; i <= m; i++)
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
		check = 0;
		for (int i = 1; i < n; i++)
			if (bak[i] != dis[i]) {
				check = 1;
				break;
			}
		if (cheak == 0)
			break;
	}

	flag = 0;
	for (int i = 1; i <= m; i++)
		if (dis[v[i]] > dis[u[i]] + w[i])
			flag = 1;
		if (flag == 1)
			printf("此图含有负权回路");
		else {
			for (int i = 1; i <= n; i++) 
				printf("%d ", dis[i]);
		}
		return 0;
}