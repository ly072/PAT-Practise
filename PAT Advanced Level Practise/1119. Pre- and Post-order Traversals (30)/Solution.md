# 1119. Pre- and Post-order Traversals (30)

[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1119)

* ʱ������ 400 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Special 

* ���� CHEN, Yue



Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences, or preorder and inorder traversal sequences. However, if only the postorder and preorder traversal sequences are given, the corresponding tree may no longer be unique.

Now given a pair of postorder and preorder traversal sequences, you are supposed to output the corresponding inorder traversal sequence of the tree. If the tree is not unique, simply output any one of them.

## Input Specification: 

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.

## Output Specification: 

For each test case, first printf in a line "Yes" if the tree is unique, or "No" if not. Then print in the next line the inorder traversal sequence of the corresponding binary tree. If the solution is not unique, any answer would do. It is guaranteed that at least one solution exists. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

## Sample Input 1:

7  
1 2 3 4 6 7 5  
2 6 7 4 5 3 1  

## Sample Output 1:

Yes  
2 1 6 4 7 3 5  

## Sample Input 2:

4  
1 2 3 4  
2 4 3 1  

## Sample Output 2:

No  
2 1 3 4  

## ���⣺

��������ǰ�������������������ж��Ƿ����ȷ��Ψһ�����������������"Yes"�Լ��������������������"No"�벻ȷ������������һ�ŵ����������

## ˼·��

������ǰ�����ת����ο���[1119. Pre- and Post-order Traversals (���S �� blog)](https://www.liuchuo.net/archives/2484)��

ǰ��ĵ�0��Ԫ�����������һ��Ӧ������ͬ�ģ������ĸ�������������һ����ǰ��һ�������������ĸ����������������������ڵ�����£��������ĸ����ҵ��������һ��ǰ���һ����ǰ���е�λ�ã����ڸ��ĺ���һ��λ�ã����п�������������������£��������ĸ���Ҳ��������������������������ĸ�����ʱ�޷�ȷ��Ψһ��������ֻ������κ�һ�֣���������������������ĸ������������һ��ǰ���һ����ǰ���е�λ�����֮�仹�������ܶ�Ԫ�أ������ȷ�����������ĸ�����������������ݹ���⡣

## �ο���

[1119. Pre- and Post-order Traversals (���S �� blog)](https://www.liuchuo.net/archives/2484)


## ���룺

[1119. Pre- and Post-order Traversals(30).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1119.%20Pre-%20and%20Post-order%20Traversals%20(30)/1119.%20Pre-%20and%20Post-order%20Traversals%20(30).cpp)

```cpp
#include <iostream>
using namespace std;

int *pre, *post, unique = 1;

typedef struct node {
	int data;
	node *left, *right;
} *tree;

tree getTree(int preLeft, int preRight, int postLeft,int postRight)
{
	if (preLeft > preRight)
		return NULL;
	tree T = new node;
	T->data = pre[preLeft];
	int left = preLeft + 1, right = left;
	for (int i = left; i <= preRight && pre[i] != post[postRight - 1]; i++)
		right++;
	if (right == left && preLeft != preRight)
		unique = 0;
	T->left = getTree(left, right - 1, postLeft, postLeft + right - left - 1);
	T->right = getTree(right, preRight, postRight - (preRight - right + 1), postRight - 1);
	return T;
}

void in(tree T)
{
	if (T->left) {
		in(T->left);
		putchar(' ');
	}
	printf("%d", T->data);
	if (T->right) {
		putchar(' ');
		in(T->right);
	}
}

int main()
{
	int n;
	cin >> n;
	pre = new int[n], post = new int[n];
	for (int i = 0; i < n; i++)cin >> pre[i];
	for (int i = 0; i < n; i++)cin >> post[i];
	tree T = getTree(0, n - 1, 0, n - 1);
	cout << (unique?"Yes":"No") << endl;
	in(T);
	cout << endl;
    return 0;
}
```