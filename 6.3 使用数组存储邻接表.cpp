6.3 使用数组存储邻接表
有n个结点，m条边
用u[i]、v[i]、w[i]存储第i条边从u[i]到v[i]结点且权值为w[i]。
int n, m, i;
int u[6], v[6], w[6];
int first[5], next[5];
cin >> n >> m;
for (i = 1; i <= n; i++) {
	first[i] = -1;
}
for (i = 1; i <= m; i++) {
	cin >> u[i] >> v[i] >> w[i];
	//核心算法语句在下面两句
	next[i] = first[u[i]];
	first[u[i]] = i;
}

找到1号结点的所有出边的方法是：
k = first[1];
while (k != -1) {
	cout << u[k] << v[k] << w[k];
	k = next[k];
}

所以遍历每个顶点的边的算法为：
for (i = 1; i <= n; i++) {
	k = first[i];
	while (k != -1) {
		cout << u[k] << v[k] << w[k];
		k = next[k];
	}
}

该算法遍历每一条边的时间复杂度和空间复杂度都是O(M)
如果一个图是稀疏图的话，M << N^2

