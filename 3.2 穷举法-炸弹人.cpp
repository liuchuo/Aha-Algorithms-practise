3.2 穷举法-炸弹人
#include <iostream>
using namespace std;
int main() {
	char a[20][21];
	int sum, map = 0;
	int n, m;
	cout << "请输入行、列：";
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int x, y;
	int p, q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				sum = 0;
				x = i;
				y = j;

				while (a[x][y] != '#') {
					if (a[x][y] == 'G') {
						sum++;
					}
					x--;
				}

				x = i;
				y = j;
				while (a[x][y] != '#') {
					if (a[x][y] == 'G') {
						sum++;
					}
					y--;
				}

				x = i;
				y = j;
				while (a[x][y] != '#') {
					if (a[x][y] == 'G') {
						sum++;
					}
					x++;
				}

				x = i;
				y = j;
				while (a[x][y] != '#') {
					if (a[x][y] == 'G') {
						sum++;
					}
					y++;
				}

				if (sum > map) {
					map = sum;
					p = i;
					q = j;
				}
			}
		}
	}
	cout << "炸弹放在" << "(" << p << "," << q << ")处，" << "最多可以消灭" << map << "个敌人" << endl;
	return 0;
}