# 1052. Linked List Sorting (25)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1052)

* ʱ������ 400 ms



* �ڴ����� 65536 kB



* ���볤������ 16000 B



* ������� Standard 

* ��Ŀ���� CHEN, Yue



A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

## Input Specification: 

Each input file contains one test case. For each case, the first line contains a positive N (< 10^5) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

*Address Key Next*

where Address is the address of the node in memory, Key is an integer in [-10^5, 10^5], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

## Output Specification: 

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

## Sample Input:  
5 00001  
11111 100 -1  
00001 0 22222  
33333 100000 11111  
12345 -1 33333  
22222 1000 12345  

## Sample Output:  
5 12345  
12345 -1 00001  
00001 0 11111  
11111 100 22222  
22222 1000 33333  
33333 100000 -1  

## ���⣺

�ṹ�庬�е�ַ(5λ����)��ֵkey����һ���ṹ��ĵ�ַnext��-1��ʾNULL�����뾲̬�����ͷ��ַ����ÿ���ṹ��ĵ�ַ��key��next(ÿ���ṹ�岻һ������������)�������key����������

## ˼·��

�ṹ�������±��ʾ��ַ�洢��̬������ͷ��ַ��ʼ���������ϵĽ�����vector����vector��Ԫ��������������ʱ�ṹ���nextҪ��Ϊ������next����vector����һ���ṹ��ĵ�ַ��ע���������޽��ʱҪ���"0 -1\n"��

## ���룺

[1052. Linked List Sorting (25).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1052.%20Linked%20List%20Sorting%20(25)/1052.%20Linked%20List%20Sorting%20(25).cpp)

```cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct node {
	int ad, key, next;
};

bool compare(node a, node b)
{
	return a.key < b.key;
}

int main()
{
	node memory[100000];
	int n, head_ad, flag = 0;
	cin >> n >> head_ad;
	vector<node> list;
	for (int i = 0; i < n; i++) {
		int ad, key, next;
		cin >> ad >> key >> next;
		if (ad == head_ad) flag = 1;
		memory[ad] = { ad, key, next };
	}
	if (flag == 0) {
		printf("0 -1\n");
		return 0;
	}
	int ad = head_ad;
	while (ad != -1) {
		list.push_back(memory[ad]);
		ad = memory[ad].next;
	}
	sort(list.begin(), list.end(), compare);
	printf("%d %05d\n", list.size(), list[0].ad);
	for (int i = 0; i < list.size(); i++) {
		printf("%05d %d ", list[i].ad, list[i].key);
		if (i + 1 < list.size()) printf("%05d\n", list[i + 1].ad);
		else printf("-1\n");
	}
    return 0;
}
```