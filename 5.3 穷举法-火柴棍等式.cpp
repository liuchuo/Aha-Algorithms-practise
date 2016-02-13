5.3 穷举法-火柴棍等式
m根火柴棍可以拼出多少种A+B=C的等式？
下面是各个数字或者符号需要的火柴数
火柴必须全部用掉  m <= 24
0 -> 6  1 -> 2  2 -> 5
3 -> 5  4 -> 4  5 -> 5
6 -> 6  7 -> 3  8 -> 7
9 -> 6  + -> 2  = -> 2

#include <iostream>
using namespace std;
int func(int x) {
	int num = 0;
	int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	while (x / 10 != 0) {
		num += a[x % 10];
		x = x / 10;
	}
	return sum;
}
int main() {
	int m;
	int count = 0;
	cin >> m;
	int a, b, c;
	for (a = 0; a <= 1111; a++) {
		for (b = 0; b <= 1111; b++) {
			c = a + b;
			if (func(a) + func(b) + func(c) == m - 4) {
				cout << a << "+" << b << "=" << c << endl;
				count++;
			}
		}
	}
	cout << "共有" << count << "种" << endl;
	return 0;
}
