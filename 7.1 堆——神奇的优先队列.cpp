7.1 堆——神奇的优先队列
#include <iostream>
#include <algorithm>//听说swap函数在里面=_=
using namespace std;
int h[101];//用来存放堆的数组
int n;//堆的大小

//向下调整函数
void siftdown(int i) {
	int t, flag = 0;//flag用来标记是否需要继续向下调整
	while (i * 2 <= n && flag == 0) {
		// 判断它和左儿子的关系，并用t记录值较小的结点编号
		if (h[i] > h[i * 2])
			t = i * 2;
		else
			t = i;

		如果它有右儿子，再对右儿子进行讨论
		if (i * 2 + 1 <= n) {
			if (h[t] > h[i * 2 + 1]) //是t和右儿子比较，因为t是结点和左儿子之间最大的哪一个
				t = i * 2 + 1;
		}
		if (t != i) {
			swap(h[t], h[i]);
			i = t;
		} else {
			flag = 1;
		}
	}
}

// 建立堆的函数
// 从最后一个非叶子结点到第1个结点依次进行调整
void creat {
	for (int i = n / 2; i >= 1; i--) {
		siftdown(i);
	}
}

// 删除最大的元素
int deletemax() {
	int t;
	t = h[1];//用一个临时变量记录堆定点的值
	h[1] = h[n];//将堆的最后一个点赋值到堆顶
	n--;//堆的元素减少1
	siftdown(1);
	return t;
}

int main() {
	int num;
	//读入要排序的数字的个数
	scanf("%d", num);

	for (int i = 1; i <= num; i++)
		scanf("%d", &h[i]);
	n = num;

	creat();

	for (i = 1; i <= num; i++)
		printf("%d ", deletemax());

	return 0;
}