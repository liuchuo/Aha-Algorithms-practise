7.3 并查集
并查集通过一个一维数组来实现，其本质是维护一个森林
并查集也称为不相交集数据结构
#include <iostream>
#include <cstdio>
using namespace std;
int f[1000] = {0};
int n, m, k, sum = 0;

void init() {
	for (int i = 1; i <= n; i++)
		f[i] = i;
}

//递归找父结点的过程
int getf(int v) {
	if(f[v] == v)
		return v;
	else {
		f[v] = getf(f[v]);
		return f[v];
	}
}

// 合并两个子集合的函数
void merge(int v, int u) {
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2) {
		f[t2] = t1;
	}
}

int main() {
	int x, y;
	scanf("%d %d", &n, &m);
	init();
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	// 扫描有多少个独立的犯罪团伙
	for(int i = 1; i <= n; i++) {
		if (f[i] == i)
			sum++;
	}

	return 0;
}
