// 1136. A Delayed Palindrome (20).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>

bool isPalindrome(string s)
{
	for (int i = 0; i < s.length() / 2; i++) 
		if (s[i] != s[s.length() - i - 1]) return false;
	return true;
}

string reverse(string s)
{
	string result = "";
	for (int i = s.length() - 1; i >= 0; i--)
		result += s[i];
	return result;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

string add(string a, string b)
{
	string result = "";
	int len = max(a.length(), b.length());
	while (a.length() < len) a = "0" + a;
	while (b.length() < len) b = "0" + b;
	int k = 0;
	for (int i = len - 1; i >= 0; i--) {
		int n = (int)a[i] - (int)'0' + (int)b[i] - (int)'0' + k;
		result = to_string(n % 10) + result;
		k = n / 10;
	}
	if (k != 0) result = to_string(k) + result;
	return result;
}

int main()
{
	string a;
	cin >> a;
	int time = 0;
	while (!isPalindrome(a)) {
		if (time >= 10) {
			cout<<"Not found in 10 iterations.";
			return 0;
		}
		string b = reverse(a);
		string sum = add(a, b);
		cout << a << " + " << b << " = " << sum << endl;
		a = sum;
		time++;
	}
	cout << a << " is a palindromic number.";
    return 0;
}

