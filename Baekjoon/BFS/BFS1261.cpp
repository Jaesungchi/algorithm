#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

//[알고스팟 난이도★](https://www.acmicpc.net/problem/1261)

int N, M; 
string arr[101];
int chk[101][101];
int dy[4] = { 0,0,-1,1 }, dx[4] = { -1,1,0,0 };

int BFS() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			chk[i][j] = 987654321;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	chk[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first.second;
		int y = q.front().first.first;
		int cnt = q.front().second;
		q.pop();
		if (x == M - 1 && y == N - 1)
			continue;
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= M || ty >= N)
				continue;
			int tCnt = arr[ty][tx] == '1' ? cnt + 1 : cnt;
			if (chk[ty][tx] > tCnt) {
				chk[ty][tx] = tCnt;
				q.push(make_pair(make_pair(ty, tx), tCnt));
			}
		}
	}
	return chk[N-1][M-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << BFS() << "\n";
}