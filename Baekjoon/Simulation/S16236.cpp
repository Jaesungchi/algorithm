#include <iostream>
#include <queue>
using namespace std;

//[아기 상어 난이도★★](https://www.acmicpc.net/problem/16236)

typedef struct position {
	int x, y;
}P;

int N = 0;
int map[21][21];
int mSize = 2; //상어 크기
int turn = 0; //얼마나 지났는지
int eatCount = 0; //몇마리 먹었는지
P myPosition; //현재 상어 위치
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

//갈수 있다면 거리 반환, 없다면 -1 반환
int canGo(int x, int y) {
	bool check[21][21];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;
	queue<pair<P,int>> q;
	q.push(make_pair(myPosition,0));
	check[myPosition.y][myPosition.x] = true;
	while (!q.empty()) {
		P tmp = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (tmp.x == x && tmp.y == y) return dist; //도착
		for (int i = 0; i < 4; i++) {
			int tx = tmp.x + dx[i];
			int ty = tmp.y + dy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N || check[ty][tx]) continue;
			if (map[ty][tx] > mSize) continue; //나보다 크면 못지나감.
			P new_P = { tx,ty };
			check[ty][tx] = true;
			q.push(make_pair(new_P, dist + 1));
		}
	}
	return -1; //없다.
}

int main() {
	bool flag = true;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				myPosition = { j,i };
				map[i][j] = 0;
			}
		}
	while (flag) {
		flag = false;
		P eatP; //먹을 포지션
		int distance = 987654321; //거리
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//아무것도 없거나, 내 사이즈보다 같거나 크면 넘어감
				if (map[i][j] == 0 || map[i][j] >= mSize) continue;
				int tmp = canGo(j, i);
				if (tmp == -1) continue; //길이없다.
				if (distance > tmp) { //거리가 더 짧다면
					eatP = { j,i };
					distance = tmp;
					flag = true;
				}
			}
		}
		if (flag) {
			eatCount++;
			map[eatP.y][eatP.x] = 0;
			if (eatCount == mSize) { //자기 사이즈만큼 먹었다면
				eatCount = 0;
				mSize++;
			}
			turn += distance; //나와 포지션까지 거리를 체크.
			myPosition = eatP;
		}
	}
	cout << turn << "\n";
}