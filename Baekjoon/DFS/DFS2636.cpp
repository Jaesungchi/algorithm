#include <iostream>
using namespace std;

//[치즈 난이도★★](https://www.acmicpc.net/problem/2636)

int maps[101][101];
int N, M;
int dy[4] = { 0,-1,0,1 }, dx[4] = { 1,0,-1,0 };

void printMap() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << maps[i][j] << " ";
		}
		cout << "\n";
	}
}

int countCheeze() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (maps[i][j] == 1)
				cnt++;
	return cnt;
}

void change() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (maps[i][j] == 2)
				maps[i][j] = 3;
}

void melting(int y, int x) {
	bool melt = false;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (maps[ty][tx] == 3)
			melt = true;
	}
	if (melt)
		maps[y][x] = 2;
}

void melt() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (maps[i][j] == 1)
				melting(i, j);
}

void outline(int x,int y) {
	bool again = false;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= M || ty >= N)
			continue;
		if (maps[ty][tx] == 1) {
			again = true;
			continue;
		}
		if (maps[ty][tx] == 0) {
			maps[ty][tx] = 3;
			outline(tx, ty);
		}
	}
	if (!again)
		maps[y][x] = 4;
}

void hot() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (maps[i][j] == 3)
				outline(j, i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maps[i][j];
	for (int i = 0; i < N; i++) {
		maps[i][0] = 3;
		maps[i][M - 1] = 3;
	}
	for (int i = 0; i < M; i++) {
		maps[0][i] = 3;
		maps[N - 1][i] = 3;
	}
	int cnt = 0;
	int save;
	while (true) {
		cnt++;
		save = countCheeze();
		hot();
		melt();
		change();
		if (countCheeze() == 0)
			break;
	}
	cout << cnt << "\n" << save << "\n";
}