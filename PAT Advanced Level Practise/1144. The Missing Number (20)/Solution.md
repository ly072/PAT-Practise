# 1144. The Missing Number (20)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1144)

* ʱ������ 150 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard 

* ��Ŀ���� CHEN, Yue



Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list. 

## Input Specification: 

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 10^5). Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int. 

## Output Specification: 

Print in a line the smallest positive integer that is missing from the input list.

## Sample Input: 

10  
5 -25 9 6 1 3 4 2 5 17  

## Sample Output:

7  

## ˼·��

��map������г��ֹ�������������1��ʼ�����������һ��û�г��ֹ�����������

## ���룺

[1144. The Missing Number (20).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1144.%20The%20Missing%20Number%20(20)/1144.%20The%20Missing%20Number%20(20).cpp)

```cpp
#include <iostream>
using namespace std;
#include <map>

int main()
{
  int n, m;
  cin >> n;
  map<int, int> list;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (m > 0)list[m] = 1;
  }
  int index = 0;
  while ( ++ index)
    if (list[index] == 0) {
      cout << index;
      return 0;
    }
  return 0;
}
```

