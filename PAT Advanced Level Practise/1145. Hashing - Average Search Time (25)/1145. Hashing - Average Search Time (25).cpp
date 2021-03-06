#include <iostream>
using namespace std;
#include <math.h>

int nextPrime(int n)
{
	if (n == 1) return 2;
	if (n <= 3) return n;
	int p = n % 2 ? n : n + 1;
	while (1) {
		int i;
		for (i = sqrt(p); i > 2; i--)
			if (p % i == 0) break;
		if (i == 2) return p;
		p += 2;
	}
}

int main()
{
	int msize, n, m, key;
	cin >> msize >> n >> m;
	int tsize = nextPrime(msize);
	int *hashtable = new int[tsize];
	fill(hashtable, hashtable + tsize, -1);
	for (int i = 0; i < n; i++) {
		cin >> key;
		int flag = 0, increment;
		for (increment = 0; increment < tsize; increment++) {
			int pos = key % tsize + increment * increment;
			if (pos >= tsize) pos %= tsize;
			if (hashtable[pos] == -1) {
				hashtable[pos] = key;
				flag = 1;
				break;
			}
		}
		if (!flag) printf("%d cannot be inserted.\n", key);
	}
	int total = 0;
	for (int i = 0; i < m; i++) {
		cin >> key;
		int increment;
		for (increment = 0; increment < tsize; increment++) {
			int pos = key % tsize + increment * increment;
			if (pos >= tsize) pos %= tsize;
			if (hashtable[pos] == key) 
				break;
			if (hashtable[pos] == -1)
				break;
		}
		total += increment + 1;
	}
	printf("%.1f\n",((float)total)/m);
    return 0;
}

