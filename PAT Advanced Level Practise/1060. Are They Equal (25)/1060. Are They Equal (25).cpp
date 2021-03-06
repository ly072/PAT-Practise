// 1060. Are They Equal (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>

string standard(string a, int n)
{
	string result = "";
	int flag = 0, count = 0, k = 0;
	while (a[0] == '0') // case : a = "00000000...000xyz..." remove "0"s
		a = a.substr(1);
	if (a[0] == '.') { 
		while (a.length() > 1 && a[1] == '0') {// case : a = "0.000...000xyz..." remove "0"s after the point"."
			a = "." + a.substr(2);
			k--;
		}
		if (a == ".") k = 0; //case "000...000.0000...000"
	}
	for (int i = 0; i < a.length(); i++) {
		if (flag == 0 && a[i] != '.') 
			k++;
		if (a[i] == '.') {
			flag = 1;
			continue;
		}
		if (count++ < n) result += a[i];
	}
	while (result.length() < n)
		result = result + "0";
	return "0." + result + "*10^" + std::to_string(k);
}

int main()
{
	int n;
	string a, b;
	cin >> n >> a >> b;
	a = standard(a, n);
	b = standard(b, n);
	if (a == b) 
		cout << "YES " << a;
	else cout << "NO " << a << " " << b;
    return 0;
}

