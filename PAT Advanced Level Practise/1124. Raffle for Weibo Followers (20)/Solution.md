# 1124. Raffle for Weibo Followers (20)
[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1124)


* ʱ������ 400 ms



* �ڴ����� 65536 kB



* ���볤������ 16000 B



* ������� Standard 

* ��Ŀ���� CHEN, Yue



John got a full mark on PAT. He was so happy that he decided to hold a raffle���齱�� for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.

## Input Specification: 

Each input file contains one test case. For each case, the first line gives three positive integers M (<= 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John's post.

Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.

## Output Specification: 

For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print "Keep going..." instead. 
## Sample Input 1:  
9 3 2  
Imgonnawin!  
PickMe  
PickMeMeMeee  
LookHere  
Imgonnawin!  
TryAgainAgain  
TryAgainAgain  
Imgonnawin!  
TryAgainAgain  

## Sample Output 1:  
PickMe  
Imgonnawin!  
TryAgainAgain  

## Sample Input 2:  
2 3 5  
Imgonnawin!  
PickMe  

## Sample Output 2:  
Keep going...  

## ���⣺

΢���齱����M��ת���У�ÿN���еĵ�S��Ϊ�н��ߣ���ÿ�˲���ת���˼������ֻ���н�һ�Σ�������һ�������й�������Ӧ������������M��N��S��������ת�����˵��ǳƣ���������н����˵��ǳƣ���û�����н��������"Keep going...  "��

## ˼·��

��map<string, int>�ж�һ�����Ƿ��й�����i��1��ʼ���������ǳƣ��� i >= S && (i - S)%N == 0 ʱ����i���˼�Ϊĳ��N�����еĵ�S����������û���й������������������i--,m-- ���������ˡ�


## ���룺


[1124. Raffle for Weibo Followers (20).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1124.%20Raffle%20for%20Weibo%20Followers%20(20)/1124.%20Raffle%20for%20Weibo%20Followers%20(20).cpp)


```cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <map>

int main()
{
	int m, n, s;
	cin >> m >> n >> s;
	map<string, int>flag;
	int tag = 0;
	for (int i = 1; i <= m; i++) {
		string name;
		cin >> name;
		if (i >= s && (i - s) % n == 0) {
			if (flag[name] == 0) {
				cout << name << endl;
				tag = 1;
				flag[name] = 1;
			}
			else {
				i--;
				m--;
			}
		}
	}
	if (tag == 0) cout << "Keep going..." << endl;
    return 0;
}
```
