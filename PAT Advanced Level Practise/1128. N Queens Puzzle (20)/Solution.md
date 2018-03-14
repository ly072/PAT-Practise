# 1128. N Queens Puzzle (20)
[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1128)
* ʱ������ 300 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard

* ��Ŀ���� CHEN, Yue


The "eight queens puzzle" is the problem of placing eight chess queens on an 8��8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general N queens problem of placing N non-attacking queens on an N��N chessboard. (From Wikipedia - "Eight queens puzzle".)

Here you are NOT asked to solve the puzzles. Instead, you are supposed to judge whether or not a given configuration of the chessboard is a solution. To simplify the representation of a chessboard, let us assume that no two queens will be placed in the same column. Then a configuration can be represented by a simple integer sequence (Q1, Q2, ..., QN), where Qi is the row number of the queen in the i-th column. For example, Figure 1 can be represented by (4, 6, 8, 2, 7, 1, 3, 5) and it is indeed a solution to the 8 queens puzzle; while Figure 2 can be represented by (4, 6, 7, 2, 8, 1, 9, 5, 3) and is NOT a 9 queens' solution.


![](https://raw.githubusercontent.com/jerrykcode/PAT-Practise/master/images/1128_1.jpg)  	
*Figure 1*

![](https://raw.githubusercontent.com/jerrykcode/PAT-Practise/master/images/1128_2.jpg)
*Figure 2*

## Input Specification:

Each input file contains several test cases. The first line gives an integer K (1 < K <= 200). Then K lines follow, each gives a configuration in the format "N Q1 Q2 ... QN", where 4 <= N <= 1000 and it is guaranteed that 1 <= Qi <= N for all i=1, ..., N. The numbers are separated by spaces.

## Output Specification:

For each configuration, if it is a solution to the N queens problem, print "YES" in a line; or "NO" if not.

## Sample Input:
4  
8 4 6 8 2 7 1 3 5  
9 4 6 7 2 8 1 9 5 3  
6 1 5 2 6 4 3  
5 1 3 5 2 4  

## Sample Output:
YES  
NO  
NO  
YES  


## ���⣺

����˼·�ο���[PAT 1128. N Queens Puzzle (20) (���S �� blog)](https://www.liuchuo.net/archives/3796)

����ʺ������еĸ�����������ÿһ������ֻ��һ���ʺ�����ÿһ�еĻʺ����ڵ������������Ƿ�Ϊһ����(û�������ʺ���ͬһ�С�ͬһб����)��

## ˼·��

��int����queensRow�洢ÿһ�еĻʺ����ڵ��������ж���һ��֮ǰ�Ļʺ�������˻ʺ�������ͬ��(queensRow[j] == queensRow[m])����������ͬһб����(abs(queensRow[j] - queensRow[m]) == abs(j - m))��

## �ο���

[PAT 1128. N Queens Puzzle (20) (���S �� blog)](https://www.liuchuo.net/archives/3796)

## ���룺

[1128. N Queens Puzzle (20).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1128.%20N%20Queens%20Puzzle%20(20)/1128.%20N%20Queens%20Puzzle%20(20).cpp)

```cpp
# include <iostream>
using namespace std;

int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		int *queensRow = new int[n];
		int flag = 0;
		for (int j = 0; j < n; j++) {
			cin >> queensRow[j];
			if (flag) continue;
			for (int m = 0; m < j; m++) {
				if (queensRow[m] == queensRow[j]) {
					flag = 1;
					break;
				}
				if (abs(queensRow[j] - queensRow[m]) == abs(j - m)) {
					flag = 1;
					break;
				}
			}
		}
		cout << (flag ? "NO" : "YES") << endl;
	}
	return 0;
}
```

|[1128. N Queens Puzzle (20)](https://www.patest.cn/contests/pat-a-practise/1128)|[C++](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1128.%20N%20Queens%20Puzzle%20(20)/1128.%20N%20Queens%20Puzzle%20(20).cpp)|[Solution](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1128.%20N%20Queens%20Puzzle%20(20)/Solution.md)|

