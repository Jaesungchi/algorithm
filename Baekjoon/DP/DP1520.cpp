#include <iostream>
using namespace std;

//[내리막 길](https://www.acmicpc.net/problem/1520)

int R, C; //세로 R, 가로 C;
int maps[501][501];
int DP[501][501]; //10억 이하
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int DFS(int x,int y) {
	if (~DP[y][x]) return DP[y][x]; //이미 들린곳이라면
	DP[y][x] = 0; //한번 들린곳.
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= C || ty >= R) continue;
		if (maps[ty][tx] >= maps[y][x]) continue;
		DP[y][x] += DFS(tx,ty);
	}
	return DP[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> maps[i][j];
			DP[i][j] = -1;
		}
	DP[R - 1][C - 1] = 1; //끝은 1개로 통한다.
	cout << DFS(0,0) << "\n";
}