//1.3用sort排结构体分数
#include <iostream>
#include <algorithm>
using namespace  std;
struct student {
    char name[21];
    int score;
};

int cmp(student a, student b) {
    return a.score < b.score;
}

int main() {
    student a[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].score;
    }
    sort(a + 1, a + n + 1, cmp); //有n个数，此处必须是a + n + 1
    for (int i = 1; i <= n; i++) {
        cout << a[i].name << " " << a[i].score << endl;
    }
    return 0;
}