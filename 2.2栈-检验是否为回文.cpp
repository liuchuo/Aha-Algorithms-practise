//1.6栈-检验是否为回文
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    int mid = len / 2 - 1;
    char a[101];
    int top = 0;
    for (int i = 0; i <= mid; i++) {
        a[++top] = s[i];
    }
    
    int next;
    if (len % 2 == 0) {
        next = mid + 1;
    } else {
        next = mid + 2;
    }
    
    
    for (int i = next; i <= len - 1; i++) {
        if (s[i] == a[top]) {
            top--;
        }
    }
    if (top == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}