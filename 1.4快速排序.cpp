//1.4快速排序
#include <iostream>
using namespace  std;
int a[101], n;

void quicksort(int left, int right) {
    if (left > right)
        return;
    int temp = a[left];
    int t;
    int i = left;
    int j = right;
    while ( i != j) {
        while (a[j] >= temp && i < j)
            j--;
        while (a[i] <= temp && i < j)
            i++;
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp; //这两句和上面那句int temp = a[left];构成交换语句
    quicksort(left, i - 1);
    quicksort(i + 1, right);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    quicksort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}