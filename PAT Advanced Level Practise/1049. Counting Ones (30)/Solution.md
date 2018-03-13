# 1049. Counting Ones (30)
[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1049)
* ʱ������ 100 ms
* �ڴ����� 65536 kB
* ���볤������ 16000 B
* ������� Standard
* ��Ŀ���� CHEN, Yue
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

## Input Specification:

Each input file contains one test case which gives the positive N (<=230).

## Output Specification:

For each test case, print the number of 1's in one line.

## Sample Input:
12
## Sample Output:
5

## ˼·��

����ο���[1049. Counting Ones (30) (���S �� blog)](https://www.liuchuo.net/archives/2305)

## ���룺

[1049. Counting Ones (30)](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1049.%20Counting%20Ones%20(30)/1049.%20Counting%20Ones%20(30).cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
	int n, left = 0, right = 0, a = 1, current = 1, result = 0;
	cin >> n;
	while (n / a) {
		left = n / (a * 10);
		current = (n / a) % 10;
		right = n % a;
		if (current == 0) result += left * a;
		else if (current == 1) result += left * a + right + 1;
		else result += (left + 1) * a;
		a *= 10;
	}
	cout << result;
	return 0;
}
```