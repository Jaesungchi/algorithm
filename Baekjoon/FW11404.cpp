#include <iostream>
#include <algorithm>
using namespace std;

// [플로이드](https://www.acmicpc.net/problem/11404)

int N, M;
int graph[101][101];

void floyd() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (graph[j][i] == 0)
				continue;
			for (int k = 1; k <= N; k++) {
				if (graph[i][k] == 0 || j == k)
					continue;
				if (graph[j][k] == 0 || graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (graph[a][b] == 0)
			graph[a][b] = c;
		else
			graph[a][b] = min(graph[a][b], c);
	}
	floyd();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << graph[i][j] << " ";
		cout << "\n";
	}
}