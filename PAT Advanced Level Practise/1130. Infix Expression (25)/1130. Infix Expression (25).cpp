// 1130. Infix Expression (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>

struct node {
	string data;
	int left, right;
};

int flag = 0;
string getExpression(node *tree, int root)
{
	string result = "", left, right;
	if (tree[root].left != -1) {
		left = getExpression(tree, tree[root].left); //Get the expression of the left child
		if (flag) { // If a pair of parentheses is needed
			left = "(" + left + ")";
			flag = 0; //Sets "flag" back to 0
		}
		result += left;
	}
	result += tree[root].data; 
	if (tree[root].right != -1) {
		right = getExpression(tree, tree[root].right); //Get the expression of the right child
		if (flag) { // If a pair of parentheses is needed
			right = "(" + right + ")";
			flag = 0; //Sets "flag" back to 0
		}
		result += right;
	}
	if (result != tree[root].data) flag = 1; //If the expression contains not only the data in the root but also the expression in its children
												// then a pair of parentheses is needed
	return result;
}

int main()
{
	int n;
	cin >> n;
	node *tree = new node[n];
	int *flag = new int[n];
	for (int i = 0; i < n; i++) {
		string data;
		int left, right;
		cin >> data >> left >> right;
		if (left != -1) left--; //Inputs indexed from 1 ~ N while in the array they indexed from 0 ~ N - 1
		if (right != -1) right--;
		tree[i] = { data, left, right };
		if (left != -1) flag[left] = 1; //The left child appeared as a child of another node
		if (right != -1) flag[right] = 1; //So do the right child
	}
	int root;
	for (int i = 0; i < n ; i++)
		if (flag[i] != 1) {
			root = i; //Root can never be a child
			break;
		}
	cout << getExpression(tree, root);
    return 0;
}

