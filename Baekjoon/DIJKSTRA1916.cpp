#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000001

//[최소비용 구하기 난이도★](https://www.acmicpc.net/problem/1916)
/*
	다익스트라 쓰면 한방에 끝나는 문제.
*/

vector<pair<int, int>> arr[1001];
int dist[1001];
int N, M;
int s, f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i <= N; i++)
		dist[i] = INF;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}
	cin >> s >> f;
	priority_queue<pair<int, int>> q;
	q.push({ 0,s });
	dist[s] = 0;
	while (!q.empty()) {
		int index = q.top().second;
		int cost = q.top().first;
		q.pop();
		if (index == f)
			continue;
		if (dist[index] < cost) continue;
		for (int i = 0; i < arr[index].size(); i++) {
			if (dist[arr[index][i].first] > cost + arr[index][i].second) {
				dist[arr[index][i].first] = cost + arr[index][i].second;
				q.push(make_pair(dist[arr[index][i].first], arr[index][i].first));
			}
		}
	}
	cout << dist[f] << "\n";
}