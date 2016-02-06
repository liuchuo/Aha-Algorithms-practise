//1.2冒泡排序
//输入：n和n个待排序的数
//数组第0位不用比较好写逻辑
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[1000];
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
