5.1.1 图的深度优先搜索
上面讲的深度和广度优先搜索都是对一个矩阵方格纸的。
#include <iostream>
using namespace std;
int book[101];
int sum = 0;
int n, e[101][101];

void dfs(int cur) {
	cout << cur << " "; //输出当前所在顶点的编号，当作是当前遍历到了这个结点
	sum++; //遍历到的节点数目+1
	if (sum == n)
		return ; //如果所有顶点都已经访问过那就直接退出

	for (int i = 1; i <= n; i++) {
		if (e[cur][i] == 1 && book[i] == 0) {
			book[i] = 1;
			dfs(i);
		}
	}
	return ;
}
int main() {
	int m; //m是边的个数，n是结点的个数
	int a, b;//储存每条边的两个结点的临时变量
	//初始化二维矩阵
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999999;
		}

	//读入边
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	book[1] = 1;
	dfs(1); //从结点1开始出发

	return 0;
}