# 1033. To Fill or Not to Fill (25)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1033)

* ʱ������ 100 ms



* �ڴ����� 65536 kB



* ���볤������ 16000 B



* ������� Standard 

* ��Ŀ���� ZHANG, Guochuan



With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

## Input Specification: 

Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.

## Output Specification: 

For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
## Sample Input 1:
50 1300 12 8  
6.00 1250  
7.00 600  
7.00 150  
7.10 0  
7.20 200  
7.50 400  
7.30 1000  
6.85 300  

## Sample Output 1:

749.17

## Sample Input 2:

50 1300 12 2  
7.10 0  
7.00 600  

## Sample Output 2:

The maximum travel distance = 1200.00  

## ���⣺

��֪���ݵ�ĳ���еľ��룬·�ϵļ���վ���������������ݻ���ÿ��λ��������ʻ�ľ��롣����ÿ������վ�뺼�ݵľ��뼰�ü���վÿ��λ�͵ļ۸񡣳�ʼʱ����û���ͣ���Ӻ��ݵ��˳������������ͷѣ����޷�����������Զ����ʻ�ľ��롣

## ˼·��

�ýṹ��洢����վ�ľ������ͼۣ��ṹ������洢���м���վ���յ�Ҳ��Ϊһ���ͼ�Ϊ0�ļ���վ�洢�������У�������ǵݼ���������0������վ�ľ��벻��0�����޷������Զ��ʻ����Ϊ0�������ڴ˼��͡����������������ʻ�ľ����ǵ�ǰ������maxDist������һ������վ�ľ������maxDist�����ܵ����յ㣬��������maxDist�������бȵ�ǰ����վ���ͼ۵͵ģ������üӵ��Ǹ����͵�ȥ�ӡ���û�и��͵��������Ȼ��maxDist��������͵�ȥ�ӡ���availableDist��ʾ��ǰ�ܹ��ߵ��ľ��롣


## ���룺

[1033. To Fill or Not to Fill (25).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1033.%20To%20Fill%20or%20Not%20to%20Fill%20(25)/1033.%20To%20Fill%20or%20Not%20to%20Fill%20(25).cpp)
```cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <algorithm>

struct node {
	double price, dist;
};

bool compare(node a, node b)
{
	return a.dist < b.dist;
}

int main()
{
	double cmax, d, davg;
	int n;
	cin >> cmax >> d >> davg >> n;
	node *stations = new node[n + 1];
	for (int i = 0; i < n; i++) 
		cin >> stations[i].price >> stations[i].dist;
	stations[n] = {0.0, d};
	sort(stations, stations + n + 1, compare);
	if (stations[0].dist != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double availableDist = 0, totalPrice = 0;
	int currentStation = 0;
	while (1) {
		double maxDist = stations[currentStation].dist + cmax * davg;
		if (currentStation + 1 < n + 1 && stations[currentStation + 1].dist > maxDist) {
			printf("The maximum travel distance = %.2f\n", maxDist);
			return 0;
		}
		int min = currentStation + 1, flag = 0;
		for (int i = currentStation + 1; i < n; i++) {
			if (stations[i].dist > maxDist) break;
			if (stations[i].price < stations[currentStation].price) {
				min = i;
				flag = 1;
				break;
			}
			if (stations[i].price < stations[min].price) 
				min = i;
		}
		if (flag) {
			totalPrice += (stations[min].dist - availableDist) * stations[currentStation].price/davg;
			availableDist = stations[min].dist;
			currentStation = min;
		}
		else {
			if (maxDist >= d) {
				totalPrice += (d - availableDist)*stations[currentStation].price/davg;
				break;
			}
			totalPrice += (maxDist - availableDist)*stations[currentStation].price/davg;
			availableDist = maxDist;
			currentStation = min;
		}
	}//while
	printf("%.2f\n", totalPrice);
    return 0;
}
```