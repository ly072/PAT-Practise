#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

vector<int> best;
int max_factor_sum = 0;
vector<int> tmp;
int n, k, p;

void dfs(int factor, int factor_sum,int sum, int level) {
	if (sum > n) return;
	if (level == k) {
		if (sum != n) return;
		if (factor_sum > max_factor_sum) {
			best = tmp;
			max_factor_sum = factor_sum;
		}
		return;
	}
	for (int i = factor; i >= 1; i--) {
		tmp.push_back(i);
		dfs(i, factor_sum + i,sum + pow(i, p),  level + 1);
		tmp.pop_back();
	}
}

int main()
{
	cin >> n >> k >> p;
	dfs(n/k, 0, 0, 0);
	if (best.size() == 0) {
		cout << "Impossible";
		return 0;
	}
	printf("%d = ", n);
	for (auto it = best.begin(); it != best.end(); it++) {
		if (it != best.begin()) printf(" + ");
		printf("%d^%d", *it, p);
	}
}