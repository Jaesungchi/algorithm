#include <iostream>
#include <queue>
#include <string>
using namespace std;

//[Puyo Puyo 난이도★★](https://www.acmicpc.net/problem/11559)

string map[12];
bool visit[12][6];
int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
int turn = 0;

void initVisit() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visit[i][j] = false;
}

//뿌요가 동시에 터진다.
bool bomb() {
	bool flag = false;
	initVisit();
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == '.' || visit[i][j]) continue;
			queue<pair<int, int>> q;
			queue<pair<int, int>> save;
			q.push(make_pair(i, j));
			visit[i][j] = true;
			while (!q.empty()) {
				pair<int, int> tmp = q.front();
				q.pop();
				save.push(tmp);
				for (int k = 0; k < 4; k++) {
					int tx = tmp.second + dx[k];
					int ty = tmp.first + dy[k];
					if (tx < 0 || ty < 0 || tx >= 6 || ty >= 12) continue;
					if (map[ty][tx] == '.' || map[i][j] != map[ty][tx] || visit[ty][tx]) continue;
					visit[ty][tx] = true;
					q.push(make_pair(ty, tx));
				}
			}
			if (save.size() >= 4) {
				flag = true;
				while (!save.empty()) {
					map[save.front().first][save.front().second] = '.';
					save.pop();
				}
			}
		}
	}
	return flag;
}

void downMap() {
	//세로 줄 단위로 본다.
	for (int i = 0; i < 6; i++) {
		bool flag = false;
		for (int j = 0; j < 12; j++)
			if (map[j][i] != '.')
				flag = true;
		if (!flag) continue; //하나도 글자가 없으면 넘어감.
		for (int j = 11; j >= 0; j--) { //거꾸로 올라감
			if (map[j][i] != '.') continue; // 넘어감.
			int k = j;
			for(;k >= 0; k--)
				if (map[k][i] != '.') {
					map[j][i] = map[k][i];
					map[k][i] = '.';
					break;
 				}
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++)
		cin >> map[i];
	while (bomb()) {
		turn++;
		downMap();
	}
	cout << turn << "\n";
}