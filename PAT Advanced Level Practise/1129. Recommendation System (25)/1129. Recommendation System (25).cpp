// 1129. Recommendation System (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <set>

struct node {
  int value, num;
  bool operator < (const node a) const {
    return num != a.num ? num > a.num : value < a.value;
  }
};

int main()
{
  int n, k;
  cin >> n >> k;
  set<node> s;
  int *num = new int[n];
  fill(num, num + n, 0);
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    value--;
    int index = 0;
    if (i == 0) goto Insert;
    printf("%d:", value + 1);
    for (auto it = s.begin(); it != s.end() && index < k; it++, index++) 
      printf(" %d", it->value + 1);
    cout << endl;
  Insert: {
    auto it = s.find({ value, num[value] });
    if (it != s.end())
      s.erase(it);
    s.insert({ value, ++num[value] });
    }
  }
    return 0;
}

