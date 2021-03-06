// 1138. Postorder Traversal (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef struct node {
	int data;
	node * left, *right;
} *tree;

int *pre, *in, index = 0;
tree getTree(int l, int r, int root)
{
	int rootIndex;
	for (int i = l; i <= r; i ++)
		if (in[i] == root) {
			rootIndex = i;
			break;
		}
	tree T = new node;
	T->data = root;
	if (l <= rootIndex - 1)
		T->left = getTree(l, rootIndex - 1, pre[++index]);
	else T->left = NULL;
	if (rootIndex + 1 <= r)
		T->right = getTree(rootIndex + 1, r, pre[++index]);
	else T->right = NULL;
	return T;
}

int flag = 0;
void post(tree T)
{
	if (T->left != NULL)
		post(T->left);
	if (T->right != NULL)
		post(T->right);
	if (flag == 0) {
		printf("%d\n", T->data);
		flag = 1;
	}
	else return;
}

int main()
{
	int n;
	cin >> n;
	pre = new int[n];
	int data;
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	in = new int[n];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	tree T = getTree(0, n - 1, pre[0]);
	post(T);
    return 0;
}

