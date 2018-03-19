# 1142. Maximal Clique (25)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1142)

* ʱ������ 400 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard

* ��Ŀ���� CHEN, Yue

A clique is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))

Now it is your job to judge if a given subset of vertices can form a maximal clique.

## Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers Nv (<= 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.

After the graph, there is another positive integer M (<= 100). Then M lines of query follow, each first gives a positive number K (<= Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.

## Output Specification:

For each of the M queries, print in a line "Yes" if the given subset of vertices can form a maximal clique; or if it is a clique but not a maximal clique, print "Not Maximal"; or if it is not a clique at all, print "Not a Clique".

## Sample Input:

8 10  
5 6  
7 8  
6 4  
3 6  
4 5  
2 3  
8 2  
2 7  
5 3  
3 4  
6  
4 5 4 3 6  
3 2 8 7  
2 2 3  
1 1  
3 4 3 6  
3 3 2 1  

## Sample Output:

Yes  
Yes  
Yes  
Yes  
Not Maximal  
Not a Clique  

## ���⣺

����һ��ͼ��Ȼ�����M�����㼯�ϣ��ж������е�ÿһ���Ƿ�Ϊ"Maximal Clique"��

Clique: ���㼯�����κ���������ͬ�Ķ���֮����бߣ���ü���ΪClique

Maximal Clique: ��һ��Clique�м���ͼ�е��κ�һ���������㣬��ʹ�ü��ϲ�������Clique����������ü���ΪMaximal Clique

## ˼·��

�����ƽ⣬���ڼ����е�ÿһ�����㣬�ж����Ƿ��뼯���е�ÿ���������㶼�бߣ�ȷ����Clique֮���ٶ��ڼ���֮���ÿ�����㣬�ж����Ƿ��뼯���еĶ����бߣ������ڼ������һ�����㣬�뼯���ڵ�ÿ�����㶼�бߣ������ö����ļ�����ΪClique������Maximal Clique��

## ���룺

[1142. Maximal Clique (25).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1142.%20Maximal%20Clique%20(25)/1142.%20Maximal%20Clique%20(25).cpp)

```cpp
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int nv, ne;
	cin >> nv >> ne;
	int **graph = new int *[nv];
	for (int i = 0; i < nv; i++)
		graph[i] = new int[nv];
	for (int i = 0; i < ne; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	int m, k, v, flag;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		vector<int> sets;
		int *collected = new int[nv];
		for (int j = 0; j < k; j++)
		{
			cin >> v;
			sets.push_back(v - 1);
			collected[v - 1] = 1;
		}
		flag = 0;
		for (int v = 0; v < sets.size(); v++)
		{
			for (int w = 0; w < sets.size(); w ++)
				if (sets[v] != sets[w] && graph[sets[v]][sets[w]] != 1)
				{
					printf("Not a Clique\n");
					flag = 1;
					break;
				}
			if (flag) break;
		}
		if (flag) continue;
		else
		{
			for (int v = 0; v < nv; v++)
			{
				flag = 0;
				if (collected[v] == 1) continue;
				for (int w = 0; w < sets.size(); w++)
					if (graph[v][sets[w]] != 1)
					{
						flag = 1;
						break;
					}
				if (flag == 1) continue;
				else
				{
					printf("Not Maximal\n");
					flag = 2;
					break;
				}
			}
		}
		if (flag != 2)
			printf("Yes\n");
	}

	return 0;
}
```
