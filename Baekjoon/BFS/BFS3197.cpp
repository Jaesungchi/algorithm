#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define TMAX 1501
using namespace std;

//[백조의 호수 난이도★★★★](https://www.acmicpc.net/problem/3197)
//기존 BFS 이용시 시간초과 발생

int R, C;
string map[TMAX];
bool check[TMAX][TMAX];
int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
queue < pair<int, int >> water;
vector<pair<int, int>> duck;


//서로 만났는지 확인하는 함수
int meetTwo() {
	int day = 0;
	queue<pair<int, int>> q;
	q.push(duck[0]);
	check[duck[0].first][duck[0].second] = true;
	while (true) {
		queue<pair<int, int>> nexts;
		while (!q.empty()) {
			pair<int,int> tmp = q.front();
			q.pop();
			if (tmp.first == duck[1].first && tmp.second == duck[1].second)
				return day; //만남.
			for (int i = 0; i < 4; i++) {
				int ty = tmp.second + dy[i];
				int tx = tmp.first + dx[i];
				if (ty < 0 || tx < 0 || ty >= R || tx >= C || check[ty][tx]) continue; //맵을 넘어가면
				check[ty][tx] = true;
				if (map[ty][tx] == 'X') { //빙판이 있다면
					nexts.push({ tx,ty });
					continue;
				}
				q.push({ tx,ty });
			}
		}
		q = nexts;
		int size = water.size();
		while (size--) {
			pair<int, int> tmp = water.front();
			water.pop();
			for (int i = 0; i < 4; i++) {
				int ty = tmp.second + dy[i];
				int tx = tmp.first + dx[i];
				if (ty < 0 || tx < 0 || ty >= R || tx >= C) continue; //맵을 넘어가면
				if (map[ty][tx] == 'X') {
					map[ty][tx] = '.';
					water.push({ tx,ty });
				}
			}
		}
		day++;
	}
	return day;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.')
				water.push({j,i});
			else if (map[i][j] == 'L'){
				duck.push_back({ j,i });
				water.push({ j,i });
			}
		}
	}
	cout << meetTwo() << "\n";
}