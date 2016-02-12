3.1 穷举法
xxx + xxx = xxx
x填入1~9数字，使得等式成立，数字不得重复
直接判断abcdefghi互相不相等的方法太繁琐，可以用book数组标记
如果这个数字出现过了，那么就把这个数字对应的book值标记为1
那么根据1~9下标的数组是否都标记为1(sum的值是否等于9)来判断abcdefghi是否两两不相等
用数组a[i]表示1~9会更简便易读。
#include <iostream>
using namespace std;
int main() {
	int a[10];
	int sum;
	int book[10];
	int total = 0;

	for (a[1] = 1; a[1] <= 9; a[1]++)
		for (a[2] = 1; a[2] <= 9; a[2]++)
			for (a[3] = 1; a[3] <= 9; a[3]++)
				for (a[4] = 1; a[4] <= 9; a[4]++)
					for (a[5] = 1; a[5] <= 9; a[5]++)
						for (a[6] = 1; a[6] <= 9; a[6]++)
							for (a[7] = 1; a[7] <= 9; a[7]++)
								for (a[8] = 1; a[8] <= 9; a[8]++)
									for (a[9] = 1; a[9] <= 9; a[9]++) {
										
										for (int i = 1; i <= 9; i++) {
											book[i] = 0;
										}

										for (int i = 1; i <= 9; i++) {
											book[a[i]] = 1;
										}

										sum = 0;
										for (int i = 1; i <= 9; i++) {
											sum += book[i];
										}
										if (sum == 9 && (a[1] * 100 + a[2] * 10 + a[3]) + (a[4] * 100 + a[5] * 10 + a[6]) == (a[7] * 100 + a[8] * 10 + a[9]) ) {
											total++;
											cout << a[1] << a[2] << a[3] << "+" << a[4] << a[5] << a[6] << "=" << a[7] << a[8] << a[9] << endl;
										}
									}
	cout << "total = " << total / 2 << endl;
	return 0;
}