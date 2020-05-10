#include <iostream>
#include <vector>
using namespace std;

//[웜홀 난이도★★](https://www.acmicpc.net/problem/1865)
/*
	INT32_MAX를 넣어놨더니 +1이 되니깐 역수가 되어서 자꾸 에러가 났었다.
*/
int N = 0, M = 0, W = 0;

bool run() {
	int t1, t2, t3;
	cin >> N >> M >> W;
	vector<vector<pair<int,int>>> edge(N + 1);
	vector<int> dist(N+1,99999999);
	dist[0] = 0;
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2 >> t3;
		edge[t1].push_back(make_pair(t2, t3));
		edge[t2].push_back(make_pair(t1, t3));
	}
	for (int i = 0; i < W; i++) {
		cin >> t1 >> t2 >> t3;
		edge[t1].push_back(make_pair(t2, t3*-1));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int e = 0; e < edge[j].size(); e++) {
				int from = j;
				int to = edge[from][e].first;
				int weight = edge[from][e].second;
				if (dist[from] + weight < dist[to]) {
					dist[to] = dist[from] + weight;
					if (i == N)
						return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		if (run())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}