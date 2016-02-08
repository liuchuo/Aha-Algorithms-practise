//1.7纸牌游戏-小猫钓鱼
星期天小哼和小哈约在一起玩桌游,他们正在玩一个非常古怪的扑克游戏——“小猫钓 鱼”。游戏的规则是这样的:将一副扑克牌平均分成两份,每人拿一份。小哼先拿出手中的 第一张扑克牌放在桌上,然后小哈也拿出手中的第一张扑克牌,并放在小哼刚打出的扑克牌 的上面,就像这样两人交替出牌。出牌时,如果某人打出的牌与桌上某张牌的牌面相同,即
可将两张相同的牌及其中间所夹的牌全部取走,并依次放到自己手中牌的末尾。当任意一人 手中的牌全部出完时,游戏结束,对手获胜。
假如游戏开始时,小哼手中有 6 张牌,顺序为 2 4 1 2 5 6,小哈手中也有 6 张牌,顺序 为 3 1 3 5 6 4,最终谁会获胜呢?现在你可以拿出纸牌来试一试。接下来请你写一个程序来 自动判断谁将获胜。这里我们做一个约定,小哼和小哈手中牌的牌面只有 1~9。

#include <iostream>
using namespace std;
struct stack {
    int data[10];
    int top;
};

struct queue {
    int data[1000];
    int head;
    int tail;
};

int main() {
    stack s;
    queue q1, q2;
    q1.head = 1; q1.tail = 1;
    q2.head = 1; q2.tail = 1;
    s.top = 0;
    
    for (int i = 1; i <= 6; i++) {
        cin >> q1.data[q1.tail];
        q1.tail++;
    }
    
    for (int i = 1; i <= 6; i++) {
        cin >> q2.data[q2.tail];
        q2.tail++;
    }
    
    int book[10];
    int t;
    
    for (int i = 1; i <= 9; i++) {
        book[i] = 0;
    }
    
    while (q1.head < q1.tail && q2.head < q2.tail) {
        t = q1.data[q1.head];
        if (book[t] == 0) {
            book[t] = 1;
            q1.head++;
            s.top++;
            s.data[s.top] = t;
        } else {
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            while (s.data[s.top] != t) {
                book[s.data[s.top]]=0;//取消标记
                q1.data[q1.tail] = s.data[s.top];
                s.top--;
                q1.tail++;
            }
        }
        
        t = q2.data[q2.head];
        if (book[t] == 0) {
            book[t] = 1;
            q2.head++;
            s.top++;
            s.data[s.top] = t;
        } else {
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            while (s.data[s.top] != t) {
                book[s.data[s.top]]=0;//取消标记
                q2.data[q2.tail] = s.data[s.top];
                s.top--;
                q2.tail++;
            }
        }
    }
    
    if (q1.tail == q1.head) {
        cout << "小哼win!" << endl;
        cout << "小哈当前手中的牌是:" << endl;
        for (int i = q2.head; i <= q2.tail - 1; i++) {
            cout << q2.data[i] << " ";
        }
        
        if (s.top > 0) {
            cout << "桌上剩余的牌是：" << endl;
            for (int i = 1; i <= s.top; i++) {
                cout << s.data[i] << " ";
            }
            cout << endl;
        } else {
            cout << "桌上已经没有牌了" << endl;
        }
    }
    
    if (q2.tail == q2.head) {
        cout << "小哈win!" << endl;
        cout << "小哼当前手中的牌是:" << endl;
        for (int i = q1.head; i <= q1.tail - 1; i++) {
            cout << q1.data[i] << " ";
        }

        cout << endl;
        
        if (s.top > 0) {
            cout << "桌上剩余的牌是：" << endl;
            for (int i = 1; i <= s.top; i++) {
                cout << s.data[i] << " ";
            }
            cout << endl;
        } else {
            cout << "桌上已经没有牌了" << endl;
        }
    }
}