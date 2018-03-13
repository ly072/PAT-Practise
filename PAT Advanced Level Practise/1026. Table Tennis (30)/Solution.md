# 1026. Table Tennis (30)
[ԭ���ַ](https://www.patest.cn/contests/pat-a-practise/1026)


* ʱ������ 400 ms

* �ڴ����� 65536 kB

* ���볤������ 16000 B

* ������� Standard 

* ��Ŀ���� CHEN, Yue



A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.

## Input Specification: 

Each input file contains one test case. For each case, the first line contains an integer N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.

## Output Specification: 

For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.

## Sample Input:  

9  
20:52:00 10 0  
08:00:00 20 0  
08:02:00 30 0  
20:51:00 10 0  
08:10:00 5 0  
08:12:00 10 1  
20:50:00 10 0  
08:01:30 15 1  
20:53:00 10 1  
3 1  
2  

## Sample Output:

08:00:00 08:00:00 0  
08:01:30 08:01:30 0  
08:02:00 08:02:00 0  
08:12:00 08:16:30 5  
08:10:00 08:20:00 10  
20:50:00 20:50:00 0  
20:51:00 20:51:00 0  
20:52:00 20:52:00 0  
3 3 2  

## ������˼·��

�������ṹ��ֱ�洢��Һ��������ṹ������洢������Һ�����������Ұ�����ʱ��������򣬶�ÿ����ң�

* 1������Ҳ���vip��
	* ���ڸ���ҵ���ʱ�п�׿�������Ƿ�Ϊvip����ȥ�ÿ�׿
	* ��û�п�׿�����ҵ�����ճ������ӣ�����׿����vip����ȵ����ճ�ʱȥ�棻����׿��vip�����ڸ����֮����û��vip����ڸ�׿�ճ�ǰ����������׿��vip�棬�����������ȥ������ճ�������
* 2���������vip ��
	* ���п�vip׿��ȥ��vip׿
	* û�п�vip׿�����пյķ�vip׿��ȥ�ÿյķ�vip׿
	* û�п�׿���ҵ�����ճ������ӣ��ȵ����ճ�ʱȥ��
ע�����ж����׿����ȥ�����С��

���ӽṹ����һ����Աint available_time������׿�ճ���ʱ�䣬�ж�һ�������Ƿ�Ϊ��׿��������available_time�Ƿ�С����ҵ���ʱ�䡣һ����ҵ�ĳ׿ȥ�棬��׿��available_timeҪ����������ʱ�䡣

�����vipʱ�����ҿ�vip׿����������Ŀ�׿��������һ��ο���[1026. Table Tennis (30)-���S �� blog](https://www.liuchuo.net/archives/2955)


## �ο���


[1026. Table Tennis (30)-���S �� blog](https://www.liuchuo.net/archives/2955)

## ���룺

[1026. Table Tennis (30).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1026.%20Table%20Tennis%20(30)/1026.%20Table%20Tennis%20(30).cpp)


```cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

struct pnode {
	int arriving_time, playing_time, serving_time, vip_tag;
} * players;

struct tnode {
	int available_time, serving_number, vip_tag;
} * tables;

bool compare(pnode a, pnode b)
{
	return a.arriving_time < b.arriving_time;
}

bool compare1(pnode a, pnode b)
{
	return a.serving_time < b.serving_time;
}

void play(int player_id, int table_id)
{
	players[player_id].serving_time = max(players[player_id].arriving_time, tables[table_id].available_time);
	if (players[player_id].arriving_time > tables[table_id].available_time)
		tables[table_id].available_time = players[player_id].serving_time;
	tables[table_id].available_time += players[player_id].playing_time;
	if (players[player_id].serving_time < 21 * 3600) tables[table_id].serving_number++;
}

void waitAndPlay(int n_players, int n_tables)
{
	for (int player_id = 0; player_id < n_players; player_id++) {
		if (players[player_id].serving_time != 0) continue;
		int table_id = 0;
		if (players[player_id].vip_tag == 0) {
			int flag = 0;
			for (int i = 0; i < n_tables; i++) {
				if (tables[i].available_time < tables[table_id].available_time)
					table_id = i;
				if (tables[i].available_time <= players[player_id].arriving_time) {
					table_id = i;
					flag = 1;
					break;
				}
			}
			if (flag || tables[table_id].vip_tag == 0)
				play(player_id, table_id);
			else {
				for (int i = player_id + 1; i < n_players; i++) {
					if (players[i].arriving_time > tables[table_id].available_time) break;
					if (players[i].vip_tag == 1 && players[i].serving_time == 0) { //vip exist
						play(i, table_id);
						flag = 1;
						player_id--;
						break;
					}
				}
				if (!flag) //no vip
					play(player_id, table_id);
			}
		}//if player is not vip
		else { //player is vip
			int flag = 0, table = -1, viptable = -1;
			for (int i = 0; i < n_tables; i++) {
				if (tables[i].available_time < tables[table_id].available_time)
					table_id = i;
				if (tables[i].vip_tag == 1 && tables[i].available_time <= players[player_id].arriving_time) {
					viptable = i;
					break;
				}
				if (tables[i].vip_tag == 0 && tables[i].available_time <= players[player_id].arriving_time && flag == 0) {
					table = i;
					flag = 1;
				}
			}
			if (viptable != -1) table_id = viptable;
			else if (table != -1) table_id = table;
			play(player_id, table_id);
		}
	}
}

void print_time_string(int time)
{
	int hh, mm, ss;
	hh = time / 3600;
	time %= 3600;
	mm = time / 60;
	time %= 60;
	ss = time;
	printf("%02d:%02d:%02d", hh, mm, ss);
}

int main()
{
	int n, m, k;
	cin >> n;
	players = new pnode[n];
	for (int i = 0; i < n; i++) {
		int hh, mm, ss, playing_minutes, tag;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &playing_minutes, &tag);
		playing_minutes = min(playing_minutes, 120);
		players[i] = { hh * 3600 + mm * 60 + ss, playing_minutes * 60,0, tag };
	}
	sort(players, players + n, compare);
	cin >> m >> k;
	tables = new tnode[m];
	for (int i = 0; i < m; i++)
		tables[i] = { 8 * 3600, 0 , 0};
	for (int i = 0; i < k; i++) {
		int table;
		cin >> table;
		tables[table - 1].vip_tag = 1;
	}
	waitAndPlay(n, m);
	sort(players, players + n, compare1);
	for (int i = 0; i < n; i++) {
		if (players[i].serving_time >= 21 * 3600) break;
		print_time_string(players[i].arriving_time);
		printf(" ");
		print_time_string(players[i].serving_time);
		printf(" %d\n", (int)((players[i].serving_time - players[i].arriving_time)/60.0 + 0.5));
	}
	for (int i = 0; i < m; i++) {
		if (i != 0) putchar(' ');
		cout << tables[i].serving_number;
	}
    return 0;
}
```