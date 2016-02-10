2.4 链表.指针概念
malloc(4)//从内存中申请分配4个字节大小的内存空间
malloc(sizeof(int))//还可以使用 sizeof(int)获取 int 类型所占用的字节数
int *p;
p = (int *)malloc(sizeof(int));//想要操作这个空间，就需要用一个指针来指向这个空间
malloc 函数的返回类型是 void * 类型。void * 表示未确定类型的指针。在 C 和 C++中,
void * 类型可以强制转换为任何其他类型的指针。上面代码中我们将其强制转化 为整型指针,
以便告诉计算机这里的 4 个字节作为一个整体用来存放整数。

指针就是用来存储内存地址的,为什么要分不同类型的指针呢?因为指针变量存储的是一个内存空间的首地址(第一个字节的地址),
但是这个空间占用了多少个字节,用来存储什么类型的数,则是由指针的类型来标明的。这样系统才知道应该取多少个连续内存作为一个数据。

链表结构：
struct node {
	int data;
	struct node *next;
};

建立链表:
struct node *head;
head = NULL;

创建一个结点，并用临时指针指向这个结点:
struct node *p;
p = (struct node *)malloc(sizeof(struct node));

int t;
cin >> t;
p->data = t;
p->next = NULL;


创建一个链表全过程：
#include <iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};

int main() {
	struct node *head, *p, *q, *t;
	int n, a;
	cin >> n;
	head = NULL;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		}else {
			q->next = p;
		}

		q = p;
	}

	//在链表中插入一个结点(按顺序)
	int b;
	cin >> b;
	t = head;
	while (t != NULL) {
		if (t->next->data > a) {
			p = (struct node *)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;
		}
		t = t->next;
	}
	
	//输出链表的值：
	t = head;
	while (t != NULL) {
		cout << t->data;
		t = t->next;
	}
	return 0;
}






