# 1143. Lowest Common Ancestor (30)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1143)

* ʱ������ 200 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard

* ��Ŀ���� CHEN, Yue


The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.

A binary search tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given any two nodes in a BST, you are supposed to find their LCA.

## Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers: M (<= 1000), the number of pairs of nodes to be tested; and N (<= 10000), the number of keys in the BST, respectively. In the second line, N distinct integers are given as the preorder traversal sequence of the BST. Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.

## Output Specification:

For each given pair of U and V, print in a line "LCA of U and V is A." if the LCA is found and A is the key. But if A is one of U and V, print "X is an ancestor of Y." where X is A and Y is the other node. If U or V is not found in the BST, print in a line "ERROR: U is not found." or "ERROR: V is not found." or "ERROR: U and V are not found.".

## Sample Input:

6 8  
6 3 1 2 5 4 8 7  
2 5  
8 7  
1 9  
12 -3  
0 8  
99 99  

## Sample Output:

LCA of 2 and 5 is 3.  
8 is an ancestor of 7.  
ERROR: 9 is not found.  
ERROR: 12 and -3 are not found.  
ERROR: 0 is not found.  
ERROR: 99 and 99 are not found.  

## ����: 

�������������BST��ǰ����������Ȼ������M��Ԫ�أ���������BST�д��ڣ��������ǵ�����Ĺ�ͬ���ȡ�


## ˼·��

BST�ɸ���ǰ�����������Ȼ�����ÿһ��Ԫ�أ���BST��������Ӹ������ǵ�·����(�Ӹ���ʼ������ǰ���ΪNULL����˵��Ҫ�ҵ�Ԫ�ز����ڣ�����ǰ������·��vector�У�Ҫ�ҵ�Ԫ�����ȵ�ǰ����ֵС�͵ݹ��������������͵ݹ�����������ȼ��ҵ���)���Ƚ�����Ԫ�ص�·��vector�����е�һ������ͬ��Ԫ�ص�ǰ��һ����Ϊ����Ĺ�ͬ���ȡ�

## ���룺

[1143. Lowest Common Ancestor (30).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1143.%20Lowest%20Common%20Ancestor%20(30)/1143.%20Lowest%20Common%20Ancestor%20(30).cpp)

```cpp
#include <iostream>
using namespace std;
#include <vector>

typedef struct node
{
	int data;
	node *left, *right;
} *tree;

tree getTree(int *pre, int start, int end)
{
	if (start > end) return NULL;
	int root = pre[start];
	int left = start + 1;
	int right = left;
	for (int i = left; i <= end; i++)
	{
		if (pre[i] < root) right++;
	}
	tree T = new node;
	T->data = root;
	T->left = getTree(pre, left, right - 1);
	T->right = getTree(pre, right, end);
	return T;
}

vector<int>path;
void findPath(tree T, int v)
{
	if (T == NULL)
	{
		path.clear(); //empty vector means error
		return;
	}
	path.push_back(T->data);
	if (v == T->data)
		return;
	else if (v < T->data)
		findPath(T->left, v);
	else
		findPath(T->right, v);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int m, n;
	cin >> m >> n;
	int *pre = new int[n];
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	tree T = getTree(pre, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		vector<int> u_path, v_path;
		path.clear();
		findPath(T, u);
		u_path = path;
		path.clear();
		findPath(T, v);
		v_path = path;
		if (v_path.size() == 0 && u_path.size() == 0)
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if (u_path.size() == 0)
			printf("ERROR: %d is not found.\n", u);
		else if (v_path.size() == 0)
			printf("ERROR: %d is not found.\n", v);
		else {
			int i;
			for (i = 0; i < min(u_path.size(), v_path.size()); i++)
				if (u_path[i] != v_path[i]) break;
			int lca = u_path[i - 1];
			if (lca == u)
			{
				printf("%d is an ancestor of %d.\n", u, v);
			}
			else if (lca == v)
			{
				printf("%d is an ancestor of %d.\n", v, u);
			}
			else
			{
				printf("LCA of %d and %d is %d.\n", u, v, lca);
			}
		}
	}
	return 0;
}
```
