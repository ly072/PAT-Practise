# 1134. Vertex Cover (25)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1134)

* ʱ������ 600 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard

* ��Ŀ���� CHEN, Yue

A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.

## Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 10^4), being the total numbers of vertices and the edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N-1) of the two ends of the edge.

After the graph, a positive integer K (<= 100) is given, which is the number of queries. Then K lines of queries follow, each in the format:

*Nv v[1] v[2] ... v[Nv]*

where Nv is the number of vertices in the set, and v[i]'s are the indices of the vertices.


## Output Specification:

For each query, print in a line "Yes" if the set is a vertex cover, or "No" if not.

## Sample Input:

10 11  
8 7  
6 8  
4 5  
8 4  
8 1  
1 2  
1 4  
9 8  
9 1  
1 0  
2 4  
5  
4 0 3 8 4  
6 6 1 7 5 4 9  
3 1 8 4  
2 2 8  
7 9 8 7 6 5 4 2  

## Sample Output:

No  
Yes  
Yes  
No  
No  

## ����: 

����һ��ͼ,��һ�����㼯ʹ���бߵ�����������������һ���ڼ�����,��˶��㼯��Ϊһ��"Vertex Cover"������һ��ͼ���Լ�K�����㼯�ϣ��ж������Ƿ�Ϊ"Vertex Cover"��

## ˼·��

��vector<pair<int, int>>�洢ÿ���ߣ�����ÿһ�����㼯�ϣ���int * collected = new int[n]���飬Ԫ�س�ʼ��Ϊ0�����ڶ��㼯���е�ÿһ�����㣬����collectedֵ���Ϊ1��Ȼ��������еıߣ����бߵ����������collectedֵ��Ϊ0����˱ߵ��������㶼���ڶ��㼯���У�����"Vertex Cover"��


## ���룺

[1134. Vertex Cover (25).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1134.%20Vertex%20Cover%20(25)/1134.%20Vertex%20Cover%20(25).cpp)

```cpp
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n, m, k;
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges.push_back({v1, v2});
	}
	cin >> k;
	int *collected = new int[n];
	for (int i = 0; i < k; i++) {
		fill(collected, collected + n, 0);
		int nv, v, flag = 0;
		cin >> nv;
		for (int j = 0; j < nv; j++) {
			cin >> v;
			collected[v] = 1;
		}
		for (auto it = edges.begin(); it != edges.end(); it++) 
			if (!collected[it->first] && !collected[it->second]) {
				cout << "No" << endl;
				flag = 1;
				break;
			}
		if (flag == 0)
			cout << "Yes" << endl;
	}
	return 0;
}
```