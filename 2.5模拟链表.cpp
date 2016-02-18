2.5 模拟链表
用数组模拟链表，在链表中插入一个数(插入在从小到大应有的顺序中)，然后按顺序输出链表
#include <iostream>
using namespace std;
int main() {
	int data[101];
	int right[101];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> data[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (i != n) {
			right[i] = i + 1;
		} else {
			right[i] = 0;
		}
	}

	int len = n;
	len++;
	cin >> data[len];

	int t = 1;
	while (t != 0) {
		if (data[right[t]] > data[len]) {
			right[len] = right[t];
			right[t] = len;
			break;
		}
		t = right[t];
	}

	t = 1;
	while (t != 0) {
		cout << data[t] << " ";
		t = right[t];
	}

	return 0;
}