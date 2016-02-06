#include <iostream>
using namespace std;
struct queue {
    int data[1000000];
    int head;
    int tail;
};
int main() {
    queue q;
    q.head = 1;
    q.tail = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q.data[i];
        q.tail++;
    }
    while (q.head < q.tail) {
        cout << q.data[q.head] << " ";
        q.head++;
         
        q.data[q.tail] = q.data[q.head];
        q.tail++;
        q.head++;
    }
    return 0;
}