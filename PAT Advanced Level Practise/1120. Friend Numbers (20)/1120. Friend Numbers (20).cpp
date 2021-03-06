// 1120. Friend Numbers (20).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
# include <string>
#include <set>
#include <algorithm>

int main()
{
	int n, sum;
	cin >> n;
	set<int> id;
	string number;
	for (int i = 0; i < n; i++) {
		cin >> number;
		sum = 0;
		for (int j = 0; j < number.length(); j++) 
			sum += (int)number[j] - (int)'0';
		id.insert(sum);
	}
	cout << id.size() << endl;
	for (auto it = id.begin(); it != id.end(); it++) {
		if (it != id.begin()) putchar(' ');
		cout << *it;
	}
    return 0;
}

