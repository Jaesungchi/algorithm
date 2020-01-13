#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool map[1001][1001];
bool checks[1001];

void resetChecks() {
	for (int i = 0; i <= N; i++)
		checks[i] = false;
}

void DFS(int start) {
	checks[start] = true;
	cout << start << " ";
	for (int i = 1; i <= N; i++) {
		if (checks[i]) continue;
		if (map[start][i])
			DFS(i);
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	checks[start] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";
		for (int i = 1; i <= N; i++) {
			if (checks[i]) continue;
			if (map[tmp][i]) {
				q.push(i);
				checks[i] = true;
			}
		}
	}
}

int main() {
	int starts, t1, t2;
	cin >> N >> M >> starts;
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		map[t1][t2] = true;
		map[t2][t1] = true;
	}
	DFS(starts);
	cout << "\n";
	resetChecks();
	BFS(starts);
	cout << "\n";
}