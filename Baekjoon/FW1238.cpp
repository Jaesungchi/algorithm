#include <iostream>
#include <algorithm>
using namespace std;

//[파티](https://www.acmicpc.net/problem/1238)

int N, M, X;
int graph[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int start, to, time;
		cin >> start >> to >> time;
		graph[start][to] = time;
	}
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

	int maxTime = 0;
	for (int i = 1; i <= N; i++)
		maxTime = max(maxTime, graph[i][X] + graph[X][i]);
	cout << maxTime << "\n";
}