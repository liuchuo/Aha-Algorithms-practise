7.2 堆排序——更好的方法
堆用数组存储
#include <iostream>
#include <algorithm>
using namespace std;
int h[101];
int n;

void siftdown(int i) {
	int t, flag = 0;
	while (i * 2 <= n flag == 0) {
		if (h[i] < h[i * 2])
			t = i * 2;
		else
			t = i;
		if (i * 2 + 1 <= n) {
			if (h[t] < h[2 * i + 1])
				t = i * 2 + 1;
		}
		if(t != i) {
		swap(h[t], h[i]); //交换两个结点的值
		i = t; //更新i为刚才与它交换的儿子结点的编号，便于接下来继续向下调整
		} else {
			flag = 1;
		}
	}
}

//维护堆
void creat() {
	int i;
	for (i = n / 2; i >= 1; i--) {
		siftdown(i);
	}
}

//堆排序
void heapsort() {
	while(n > 1) {
		swap(h[1], h[n]);
		n--;
		siftdown(1);
	}
}

int main() {
	int i, num;
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
		scanf("%d", &h[i]);
	n = num;

	//建堆
	creat();
	//堆排序
	heapsort();
	//print
	for(i = 1; i <= num; i++)
		printf("%d ",h[i]);

	return 0;
}