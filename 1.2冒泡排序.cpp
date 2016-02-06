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

//如果要排序的是对应分数的人的名字的话，就用结构体存储名字和分数两个量
#include <iostream>
using namespace  std;
struct student {
    char name[21];
    int score;
};
int main() {
    student a[100], temp;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].score;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j].score > a[j + 1].score) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i].name << " " << a[i].score << endl;
    }
    return 0;
}