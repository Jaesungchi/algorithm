#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

//[최단경로 난이도★★★(다익스트라)](https://www.acmicpc.net/problem/1753)

int V, E; //정점 갯수 V 간선 갯수 E
int K; //시작정점
vector<pair<int,int>> map[20001];
int dist[20001];

int main() {
	int tmp, tmp1, tmp2;
	cin >> V >> E >> K;
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
		if (i == K) dist[i] = 0;
	}
	for (int i = 0; i < E; i++) {
		cin >> tmp >> tmp1 >> tmp2;
		map[tmp].push_back(make_pair(tmp1, tmp2));
	}
	priority_queue<pair<int,int>> q; //우선순위 큐를 이용해 해결한다.
	q.push(make_pair(0,K));
	while (!q.empty()) {
		int index = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (dist[index] < cost) continue;
		for (int i = 0; i < map[index].size(); i++) {
			if (dist[map[index][i].first] > cost + map[index][i].second) {
				dist[map[index][i].first] = cost + map[index][i].second;
				q.push(make_pair(-dist[map[index][i].first], map[index][i].first));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}