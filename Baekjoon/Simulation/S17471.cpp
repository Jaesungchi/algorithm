#include <iostream>
#include <queue>
#define INT_MAX 999999999
using namespace std;

//https://www.acmicpc.net/problem/17471 //개리맨더링 난이도★★★

int city[11];
bool map[11][11];
bool team[11]; //true 면 1 false면 2팀
int N,minMax = INT_MAX;

//팀을 잘 나누었는지 확인.
bool isGoodTeam() {
	int teams[11] = { 0 },true1 = 0, false1 = 0;
	for (int i = 0; i < N; i++)
		if (team[i]) {
			true1 = i;
			break;
		}
	for (int i = 0; i < N; i++)
		if (!team[i]) {
			false1 = i;
			break;
		}
	//true팀 확인
	queue<int> q;
	q.push(true1);
	teams[true1] = 1;
	while (!q.empty()) {
		int tmp = q.front();
		for (int j = 0; j < N; j++) {
			if (map[tmp][j] && team[j] && teams[j] == 0) {
				teams[j] = 1;
				q.push(j);
			}
		}
		q.pop();
	}
	//false팀 확인
	q.push(false1);
	teams[false1] = 2;
	while (!q.empty()) {
		int tmp = q.front();
		for (int j = 0; j < N; j++) {
			if (map[tmp][j] && !team[j] && teams[j] == 0) {
				teams[j] = 2;
				q.push(j);
			}
		}
		q.pop();
	}
	for (int i = 0; i < N; i++)
		if (teams[i] == 0)
			return false;
	return true;
}

void DFS(int counts) {
	if (counts == N) {
		if (isGoodTeam()) {
			int sum1 = 0, sum2 = 0;
			for (int i = 0; i < N; i++)
				if (team[i])
					sum1 += city[i];
				else
					sum2 += city[i];
			sum1 = sum1 - sum2;
			if (sum1 < 0) 
				sum1 *= -1;
			minMax = minMax > sum1 ? sum1 : minMax;
		}
		return;
	}
	DFS(counts + 1); //false 팀으로 보낸다.
	team[counts] = true;
	DFS(counts + 1); //true 팀으로 보낸다.
	team[counts] = false;
}

int main() {
	int temp,temp2;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> city[i];
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for(int j = 0 ; j < temp; j++){
			cin >> temp2;
			map[i][temp2 - 1] = true;
			map[temp2 - 1][i] = true;
		}
	}
	DFS(0);
	if (minMax == INT_MAX)
		cout << -1;
	else
		cout << minMax;

}