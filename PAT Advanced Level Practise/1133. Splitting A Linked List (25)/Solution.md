# 1133. Splitting A Linked List (25)
[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1133)

* ʱ������ 400 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard

* ��Ŀ���� CHEN, Yue

Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18��7��-4��0��5��-6��10��11��-2 and K being 10, you must output -4��-6��-2��7��0��5��10��18��11.

## Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 10^5) which is the total number of nodes, and a positive K (<=1000). The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

*Address Data Next*

where Address is the position of the node, Data is an integer in [-10^5, 10^5], and Next is the position of the next node. It is guaranteed that the list is not empty.

## Output Specification:

For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.

## Sample Input:

00100 9 10  
23333 10 27777  
00000 0 99999  
00100 18 12309  
68237 -6 23333  
33218 -4 00000  
48652 -2 -1  
99999 5 68237  
27777 11 48652  
12309 7 33218  

## Sample Output:  

33218 -4 68237  
68237 -6 48652  
48652 -2 12309  
12309 7 00000  
00000 0 99999  
99999 5 23333  
23333 10 00100  
00100 18 27777  
27777 11 -1  

## ����: 

����һ����̬����,�������������Ӻ����: ���ֵΪ���ķ�����ǰ��֮��Ϊֵ������[0, K]�ڵĽ��(KΪһ�������������<= 1000)��֮��Ϊʣ�µĽ�㡣

## ˼·��

������̬�����������ֵС��0�ġ�������[0��K]�ڵģ��Լ�ʣ�µķֱ��������������ϣ�ͷ��ַ�ֱ�Ϊp0��p1��p2����������������(�����㷨������)��


## ���룺

[1133. Splitting A Linked List (25).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1133.%20Splitting%20A%20Linked%20List%20(25)/1133.%20Splitting%20A%20Linked%20List%20(25).cpp)

```cpp
#include <iostream>
using namespace std;

struct node {
	int ad, data, next;
};

int main()
{
	int head, n, k;
	cin >> head >> n >> k;
	node  list[100000];
	for (int i = 0; i < n; i++) {
		int ad;
		cin >> ad;
		cin >> list[ad].data >> list[ad].next;
	}
	int p0 = -1, tmp0, p1 = -1, tmp1, p2 = -1, tmp2;
	int ad = head;
	while (ad != -1) {
		if (list[ad].data < 0) {
			if (p0 == -1) {
				p0 = ad;
				tmp0 = p0;
			}
			else {
				list[tmp0].next = ad;
				tmp0 = ad;
			}
		}
		else if (list[ad].data <= k) {
			if (p1 == -1) {
				p1 = ad;
				tmp1 = p1;
			}
			else {
				list[tmp1].next = ad;
				tmp1 = ad;
			}
		}
		else {
			if (p2 == -1) {
				p2 = ad;
				tmp2 = p2;
			}
			else {
				list[tmp2].next = ad;
				tmp2 = ad;
			}
		}
		ad = list[ad].next;
	}
	if (p0 != -1) {
		ad = p0;
		while (ad != tmp0) {
			printf("%05d %d ", ad, list[ad].data);
			if (list[ad].next != -1) printf("%05d\n", list[ad].next);
			else cout << "-1" << endl;
			ad = list[ad].next;
		}
		printf("%05d %d ", tmp0, list[tmp0].data);
		if (p1 != -1) printf("%05d\n", p1);
		else if (p2 != -1) printf("%05d\n", p2);
		else cout << "-1" << endl;
	}
	if (p1 != -1) {
		ad = p1;
		while (ad != tmp1) {
			printf("%05d %d ", ad, list[ad].data);
			if (list[ad].next != -1) printf("%05d\n", list[ad].next);
			else cout << "-1" << endl;
			ad = list[ad].next;
		}
		printf("%05d %d ", tmp1, list[tmp1].data);
		if (p2 != -1) printf("%05d\n", p2);
		else cout << "-1" << endl;
	}
	if (p2 != -1) {
		ad = p2;
		while (ad != tmp2) {
			printf("%05d %d ", ad, list[ad].data);
			if (list[ad].next != -1) printf("%05d\n", list[ad].next);
			else cout << "-1" << endl;
			ad = list[ad].next;
		}
		printf("%05d %d ", tmp2, list[tmp2].data);
		cout << "-1" << endl;
	}
	return 0;
}
```