8.1 图的最小生成树-Kruskal算法
判断两个顶点是否已连通：把所有的顶点放入一个并查集中，然后判断两个顶点是否在同一个集合（即是否具有共同的祖先）。
一直选最小权值的边，只要这条边不会构成连通图。直到选了n-1条边退出循环
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge {
	int u;
	int v;
	int w;
};

struct edge e[10];
int n, m;
int f[7] = {0}, sum = 0, count = 0;

int cmp(struct edge a, struct edge b) {
	return a.w < b.w;
}

// 并查集寻找祖先的函数
int getf(int v) {
	if (f[v] != v)
		f[v] = getf(f[v]);
	return f[v];
}

// 并查集合并两个子集合的函数
int merge(int v, int u) {
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2) {
		f[t2] = t1;
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	sort(e, e + m, cmp);

	for (int i = 1; i <= n; i++)
		f[i] = i;

	// kruskal算法核心部分
	// 开始枚举每一条边
	for (int i = 1; i <= m; i++) {
		// 判断一条边的两个顶点是否已经连通，即判断是否已经在同一个集合中
		if (merge(e[i].u, e[i].v)) {
			count++;
			sum = sum + e[i].w;
		}
		// 直到选用了n-1条边之后退出循环
		if (count == n - 1)
			break;
	}


	printf("%d", sum);

	return 0;
}