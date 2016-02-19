4.1深度优先搜索-xxx + xxx = xxx
#include <iostream>
#include <cstdio>
using namespace std;

int a[10];
int book[10];
int total = 0;

int dfs(int step) {
	if (step == 10) {
		total++;
		if ((a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6]) == (a[7] * 100 + a[8] * 10 + a[9])) {
			printf("%d%d%d + %d%d%d = %d%d%d", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (book[i] == 0) {
			a[step] = 1; 
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
}
int main() {
	dfs(1);
	cout << "total = " << total << endl;
    return 0;
}