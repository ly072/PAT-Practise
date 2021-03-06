// 1108. Finding Average (20).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>

int main()
{
	int n;
	cin >> n;
	int k = 0;
	double total = 0.0;
	for (int i = 0; i < n; i++) {
		string number;
		cin >> number;
		int flag = 0, count = 0;
		double n;
		for (int j = 0; j < number.length(); j++) {
			if (flag) count++;
			if (isdigit(number[j])) continue;
			if (number[j] == '-' && j == 0) continue;
			if (number[j] == '.' && j != 0 && flag == 0) {
				flag = 1;
				continue;
			}
			goto ERROR;
		}
		if (count > 2) goto ERROR;
		n = atof(number.c_str());
		//cout << number.c_str() << endl;
		//printf("%f\n", n);
		if (n < -1000 || n > 1000) goto ERROR;
		k++;
		total += n;
		continue;
	ERROR: {
		cout << "ERROR: " << number << " is not a legal number" << endl;
		}
	}
	if (k == 1) printf("The average of %d number is ", k);
	else printf("The average of %d numbers is ", k);
	if (k) printf("%.2f\n", total/k);
	else printf("Undefined\n");
    return 0;
}

