#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

bool compare(pair<int, int>a, pair<int, int> b)
{
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>  graph[10000];//�ڽӱ�
	int gender[10000];//�Ա�
	for (int i = 0; i < m; i++) {
		string a, b;//����idʱһ��Ҫ��string�������޷�����`-0000`��`0000`���Ա�
		cin >> a >> b;
		int v1 = atoi(a.c_str()), v2 = atoi(b.c_str());
		gender[v1] = a[0] == '-' ? 0 : 1;
		if (v1 < 0) v1 = 0 - v1;
		gender[v2] = b[0] == '-' ? 0 : 1;
		if (v2 < 0) v2 = 0 - v2;
		graph[v1].push_back(v2); //v1��v2������
		graph[v2].push_back(v1);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 0) a = 0 - a;
		if (b < 0) b = 0 - b;
		if (a == b) {
			cout << "0" << endl;
			continue;
		}
		vector<pair<int, int>> friends; //����a��b�����Ѷ�
		vector<int> flag[10000]; //flag[id]�洢id��a��ͬ������(��b��)
		for (auto it = graph[a].begin(); it != graph[a].end(); it++) //����a������
			if (gender[*it] == gender[a] && *it != b) { //��������aͬ���Ҳ���b
				for (auto i = graph[*it].begin(); i != graph[*it].end(); i++) //���������ѵ�����
					if (*i != b && *i != a) //����a��b
						flag[*i].push_back(*it); //*it��a�����ѣ�*i��*it�����ѣ�*it��*i��a��ͬ������
			}
		for (auto it = graph[b].begin(); it != graph[b].end(); it++) //����b������
			if (gender[*it] == gender[b] && *it != a && flag[*it].size() > 0) //�Ա���ͬ�Ҳ���a������a��ͬ������(*it��a��ĳЩ���ѵ�����)
				for (auto i = flag[*it].begin(); i != flag[*it].end(); i++) //*i��*it��a��ͬ������
					friends.push_back({*i, *it});//*i��*it������Ϊһ�����Ѷԡ�*i��a�����ѣ�*it��*i�����ѣ�b��*it������
		sort(friends.begin(), friends.end(), compare);
		cout << friends.size() << endl;
		for (auto it = friends.begin(); it != friends.end(); it++) {
			printf("%04d %04d\n", it->first, it->second);
		}
	}
}