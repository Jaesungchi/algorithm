#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

//[보물섬 난이도★★](https://www.acmicpc.net/problem/2589)

int N, R;
string arr[51];
int check[51][51];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

int bfs(int y, int x) {
	memset(check, 0, sizeof(check));
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	int maxs = 0;
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		int cnt = check[y][x];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || tx >= R || ty < 0 || ty >= N)
				continue;
			if (arr[ty][tx] == 'W' || check[ty][tx] > 0)
				continue;
			check[ty][tx] = cnt + 1;
			maxs = max(check[ty][tx], maxs);
			q.push(make_pair(ty, tx));
		}
	}
	return maxs;
}

int main() {
	int maxs = 0;
	cin >> N >> R;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < R; j++)
			if (arr[i][j] == 'L')
				maxs = max(maxs,bfs(i, j));
	cout << maxs <<"\n";
}