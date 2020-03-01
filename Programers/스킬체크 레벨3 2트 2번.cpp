#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//네트워크가 몇팀으로 연결되었는지 물어보는 문제

int team[201], realN;

void BFS(int starts,int teamNum, vector <vector<int>>com) {
	queue<int> q;
	q.push(starts);
	team[starts] = teamNum;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < realN; i++) {
			if (i == starts) continue;
			if (team[i] != 0) continue;
			if (com[tmp][i] == 0) continue;
			team[i] = teamNum;
			q.push(i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 1;
	realN = n;
	for (int i = 0; i < n; i++) {
		if (team[i] == 0)
			BFS(i, answer++, computers);
	}
	return --answer;
}