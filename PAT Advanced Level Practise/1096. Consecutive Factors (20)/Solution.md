# 1096. Consecutive Factors (20)
[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1096)

* ʱ������ 400 ms
* �ڴ����� 65536 kB
* ���볤������ 16000 B
* ������� Standard
* ��Ŀ���� CHEN, Yue

Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

## Input Specification:

Each input file contains one test case, which gives the integer N (1<N<2^31).

## Output Specification:

For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.

## Sample Input:
630  

## Sample Output:
3  
5*6*7  

## ���⣺

����������N(1<N<2^31)����N����������������У����Ӳ�����1��

## ˼·��

����˼·�ο� http://blog.csdn.net/tuzigg123/article/details/47175673

���Ӵ�2��ʼ��̽��ֱ��sqrt(N)����ÿһ����̽������factor��ֻҪN % factor == 0��������һ�����ܵ����ӣ�N��ΪN / factor��factor++����̽�������ӣ���N % factor != 0ʱֹͣ��̽�����ӣ�������������������¡�

## �ο���

csdn��http://blog.csdn.net/tuzigg123/article/details/47175673

## ���룺

[1096. Consecutive Factors (20).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1096.%20Consecutive%20Factors%20(20)/1096.%20Consecutive%20Factors%20(20).cpp)

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

int main()
{
	int n;
	cin >> n;
	vector<int> best, tmp;
	for (int i = 2; i < sqrt(n); i++) {
		int m = n, factor = i;
		tmp.clear();
		while (1) {
			if (m % factor != 0) 
				break;
			tmp.push_back(factor);
			m /= factor;
			factor++;
		}
		if (tmp.size() > best.size())
			best = tmp;
	}
	if (best.size() == 0) {
		cout << "1" << endl << n;
		return 0;
	}
	cout << best.size() << endl;
	for (auto it = best.begin(); it != best.end(); it++) {
		if (it != best.begin()) cout << "*";
		cout << *it;
	}
	return 0;
}
```