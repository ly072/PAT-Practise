// 1113. Integer Set Partition (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <algorithm>

int main() 
{
	int n;
	cin >> n;
	int *list = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	sort(list, list + n);
	int center = n / 2;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < center; i++)
		s1 += list[i];
	for (int i = center; i < n; i++)
		s2 += list[i];
	cout << n % 2;
	printf(" %d", s2 - s1);
    return 0;
}

