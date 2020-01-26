#include <iostream>
#include <queue>
using namespace std;

//[벽 부수고 이동하기 난이도★★](https://www.acmicpc.net/problem/2206)

int N, M;// 세로, 가로
bool maps[1001][1001];
bool check[1001][1001][2]; //0은 안부숨, 1은 부숨
int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };

typedef struct car {
	int x, y;
	int c;
	int wall;
}C;

bool isOut(int x, int y) {
	if (x < 0 || y < 0 || x >= M || y >= N)
		return true;
	return false;
}

int BFS() {
	queue<C> q;
	C start = { 0,0,1,0 };
	check[0][0][0] = true;
	q.push(start);
	while (!q.empty()) {
		C tmp = q.front();
		q.pop();
		if (tmp.x == M - 1 && tmp.y == N - 1) return tmp.c;
		for (int i = 0; i < 4; i++) {
			int tx = tmp.x + dx[i];
			int ty = tmp.y + dy[i];
			int tc = tmp.c + 1;
			if (isOut(tx, ty)) continue;
			if (check[ty][tx][tmp.wall]) continue;
			if (maps[ty][tx]) { //갈수 있다면
				C tnew = { tx,ty,tc,tmp.wall };
				check[ty][tx][tmp.wall] = true;
				q.push(tnew);
			}
			else if (tmp.wall == 0) {
				C tnew = { tx,ty,tc,1 };
				check[ty][tx][1] = true; //들렀다.
				q.push(tnew);
			}
		}
	}
	return -1;
}

int main() {
	char tmp[1001];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++)
			if (tmp[j] == '0')
				maps[i][j] = true;
			else
				maps[i][j] = false;
	}
	cout << BFS() << "\n";
}