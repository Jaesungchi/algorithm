#include <iostream>;
#include <queue>;
using namespace std;

//https://www.acmicpc.net/problem/5213 과외맨

int N, map[501][1001], visit[501][1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2-1; j += 2) {
			if (i % 2 != 0 && j == 0)
				j++;
			if (i % 2 == 0)
				cin >> map[i][j] >> map[i][j + 1];
			else
				cin >> map[i][j] >> map[i][j + 1];
			visit[i][j] = visit[i][j + 1] = -1;
		}
	}
	queue<int> q;
	q.push(0);
	visit[0][0] = 0;
	while (!q.empty()) {
		int idx = q.front();
		int y = idx / (N * 2), x = idx % (N * 2);
		if (x + 3 < N * 2) { //오른쪽이 더 있는경우
			if (map[y][x + 1] == map[y][x + 2] && visit[y][x + 2] == -1) { //우측의 우측이있는
				q.push(idx + 2);
				visit[y][x + 2] = visit[y][x] + 1;
				visit[y][x + 3] = visit[y][x] + 1;
			}
			if (y - 1 >= 0 && map[y][x + 1] == map[y - 1][x + 1] && visit[y - 1][x + 1] == -1) { //우측위 위쪽
				q.push(idx - 9);
				visit[y - 1][x + 1] = visit[y][x] + 1;
				visit[y - 1][x + 2] = visit[y][x] + 1;
			}
			if (y + 1 < N && map[y][x + 1] == map[y + 1][x + 1] && visit[y + 1][x + 1] == -1) { //우측의 아래쪽
				q.push(idx + 11);
				visit[y + 1][x + 1] = visit[y][x] + 1;
				visit[y + 1][x + 2] = visit[y][x] + 1;
			}
		}
		if (x - 2 >= 0) { //왼쪽이 더 있는경우
			if (map[y][x] == map[y][x - 1] && visit[y][x - 1] == -1) {
				q.push(idx - 2);
				visit[y][x - 2] = visit[y][x] + 1;
				visit[y][x - 1] = visit[y][x] + 1;
			}
			if (y - 1 >= 0 && map[y][x] == map[y - 1][x] && visit[y - 1][x] == -1) {
				q.push(idx - 11);
				visit[y - 1][x - 1] = visit[y][x] + 1;
				visit[y - 1][x] = visit[y][x] + 1;
			}
			if (y + 1 < N && map[y][x] == map[y + 1][x] && visit[y + 1][x] == -1) {
				q.push(idx + 9);
				visit[y + 1][x - 1] = visit[y][x] + 1;
				visit[y + 1][x] = visit[y][x] + 1;
			}
		}
	}
	cout << visit[N - 1][N * 2 - 2];
}