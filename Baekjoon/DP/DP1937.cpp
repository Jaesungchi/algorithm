#include <iostream>
using namespace std;

//[욕심쟁이 판다 난이도★★★](https://www.acmicpc.net/problem/1937)

int N;
int maps[501][501];
int DP[501][501];
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

int DFS(int x, int y) {
	if (DP[y][x] != 0) return DP[y][x]; //들렀던 곳이면 안감
	int maxTmp = 0,tmp;
	DP[y][x] = 1;
	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k];
		int ty = y + dy[k];
		if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
		if (maps[y][x] >= maps[ty][tx]) continue; //갈수 없는 땅
		tmp = DFS(tx, ty); //이 길은 얼마나 갈 수 있나 본다.
		maxTmp = tmp > maxTmp ? tmp : maxTmp; //갈수 있는 길중에 최고 길만 저장
	}
	DP[y][x] += maxTmp; //최고 길이를 더한다.
	return DP[y][x];
}

int main() {
	int maxs = 0,tmp;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> maps[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			tmp = DFS(j, i);
			maxs = tmp > maxs ? tmp : maxs;
		}
	cout << maxs << "\n";
}