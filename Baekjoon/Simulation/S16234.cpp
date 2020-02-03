#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

//[인구 이동 난이도 ★★](https://www.acmicpc.net/problem/16234)

int N, L, R; //사이즈 N, 최소 L 최대 R
int map[51][51]; //인구를 갖고 있는 맵
int area[51][51]; //서로 소속하는지 알아보는 경우
int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
int counts = 0; //인구이동이 일어난 횟수.

/*
	BFS로 각 지역끼리 어디까지 연결되어있는지 확인
	연결 된 지역은 vector에 넣어 바로 접근 할 수 있게함.
	BFS가 끝나면 지역 인구수 / vector.size()로 인구수 구함
	vector에 있는 지역들은 인구수 적용.
*/

void resetArea() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			area[i][j] = 0;
}

//이게 false면 변화가 없음.
bool BFS(int y, int x,int teamNum) {
	int sum = 0;
	bool flag = false;
	vector<pair<int, int>> team;
	queue<pair<int, int>> q;
	area[y][x] = teamNum;
	q.push(make_pair(y, x));
	//지역을 나눈다.
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		sum += map[yy][xx];
		team.push_back(make_pair(yy, xx));
		for (int i = 0; i < 4; i++) {
			int ty = yy + dy[i];
			int tx = xx + dx[i];
			if (ty < 0 || tx < 0 || ty >= N || tx >= N || area[ty][tx] != 0) continue;
			int gab = abs(map[yy][xx] - map[ty][tx]);
			if (gab < L || gab > R) continue;
			area[ty][tx] = teamNum;
			flag = true;
			q.push(make_pair(ty, tx));
		}
	}
	if(!flag) //벽이 없다면 종료됨.
		return flag;
	sum /= team.size();//사이즈로 나눔.
	for (int i = 0; i < team.size(); i++)
		map[team[i].first][team[i].second] = sum;
	return true;
}

int main() {
	int teamCount = 0;
	bool flag = true;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	while (flag) {
		flag = false;
		teamCount = 0;
		resetArea();
		counts++;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (area[i][j] == 0)
					flag = (BFS(i, j, ++teamCount)) || flag; //하나라도 true면 true
	}
	cout << counts - 1 << "\n";
}