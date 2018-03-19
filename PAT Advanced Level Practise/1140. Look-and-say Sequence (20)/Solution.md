# 1140. Look-and-say Sequence (20)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1140)

* ʱ������ 400 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard

* ��Ŀ���� CHEN, Yue

Look-and-say sequence is a sequence of integers as the following:

D, D1, D111, D113, D11231, D112213111, ...
where D is in [0, 9] except 1. The (n+1)st number is a kind of description of the nth number. For example, the 2nd number means that there is one D in the 1st number, and hence it is D1; the 2nd number consists of one D (corresponding to D1) and one 1 (corresponding to 11), therefore the 3rd number is D111; or since the 4th number is D113, it consists of one D, two 1's, and one 3, so the next number must be D11231. This definition works for D = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit D.

## Input Specification:

Each input file contains one test case, which gives D (in [0, 9]) and a positive integer N (<=40), separated by a space.

## Output Specification:

Print in a line the Nth number in a look-and-say sequence of D.

## Sample Input:

1 8  

## Sample Output:

1123123111  

## ���⣺

Look-and-say sequence:

eg:  

1Ϊ��ʼֵ��8�κ��Look-and-say sequence: 

1  
1����1�Σ�  
11  
1����2�Σ�  
12  
1����1�Σ�2����1�Σ�  
1121  
1����2�Σ�2����1�Σ�1����1�Σ�  
122111  
1����1�Σ�2����2�Σ�1����3�Σ�  
112213  
1����2�Σ�2����2�Σ�1����1�Σ�3����1�Σ�  
12221131  
1����1�Σ�2����3�Σ�1����2�Σ�3����1�Σ�1����1�Σ�
1123123111  

����D��N������DΪ��ʼֵ��N�κ��"Look-and-say sequence"

## ˼·��

string result�洢�������ʼ��ΪD���ַ�����ʽ��ѭ��N - 1�Σ�ÿ�ν�result[j](j��ʼΪ0)������һ��string tmp�У�Ȼ��result���󣬼�¼�ж��ٸ�������result[j]��ͬ�ģ��������ӵ�tmp���棬Ȼ��j����Ϊj֮���һ����result[j]��ͬ�ġ�

## ���룺

[1140. Look-and-say Sequence (20).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1140.%20Look-and-say%20Sequence%20(20)/1140.%20Look-and-say%20Sequence%20(20).cpp)

```cpp
#include <iostream>
using namespace std;
#include <string>

int main()
{
	int d, n;
	cin >> d >> n;
	string result = to_string(d);
	for (int i = 1; i < n; i++)
	{
		string tmp = "";
		for (int j = 0; j < result.length();)
		{
			tmp += result[j];
			int k;
			for ( k = j + 1; k < result.length() && result[k] == result[j]; k++);
			tmp += to_string(k - j);
			j = k;
		}
		result = tmp;
	}
	cout << result << endl;
	return 0;
}
```
