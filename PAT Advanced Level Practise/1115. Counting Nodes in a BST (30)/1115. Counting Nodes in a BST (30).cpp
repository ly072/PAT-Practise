// 1115. Counting Nodes in a BST (30).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int *level;

typedef struct node { //Node of BST
	int data;
	node *left, *right;
} *BST;

BST insert(BST tree, int data, int l)
{	/* Inserts an element into the BST, l is the level of the tree on which the node insert */
	if (tree == NULL) {
		tree = new node;
		tree->data = data;
		tree->left = tree->right = NULL;
		level[l]++;
		return tree;
	}
	if (data <= tree->data)
		tree->left = insert(tree->left, data, l + 1); //Inserts on the left, next level
	if (data > tree->data)
		tree->right = insert(tree->right, data, l + 1); //Inserts on the right, next level
	return tree;
}

int main()
{
	int n;
	cin >> n;
	level = new int[n]; //Number of nodes on each level
	fill(level, level + n, 0);
	BST tree = NULL;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		tree = insert(tree, data, 0);
	}
	int maxL = 0;
	for (int i = 0; i < n; i++) 
		if (level[i] == 0) {
			maxL = i;
			break;
		}
	if (maxL == 0)maxL = n;
	printf("%d + %d = %d", level[maxL - 1], level[maxL - 2], level[maxL - 1] + level[maxL - 2]);
    return 0;
}

