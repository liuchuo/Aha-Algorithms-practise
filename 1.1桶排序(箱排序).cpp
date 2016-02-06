//桶排序（箱排序）
#include <iostream>
using namespace std;
int main() {
    int a[10] = {0};
    int temp;
    for (int i = 0; i < 10; i++) {
        cin >> temp;
        a[temp]++;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= a[i]; j++) {
            cout << i << " ";
        }
    }
    return 0;
}