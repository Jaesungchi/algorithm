#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//[중량제한 난이도★★★](https://www.acmicpc.net/problem/1939)

int N, M;//2 <= N <= 10000, 1 <= M <= 100000
vector<vector<pair<int, int>>> edge;
int da, db;

//weight의 값으로 순환이 가능한지 확인하는 메소드
bool BFS(int weight) {
	bool check[10001];
	fill_n(check, 10001, false);
	queue<int> q;
	q.push(da);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == db)
			return true;
		for (int i = 0; i < edge[now].size(); i++)
			if (!check[edge[now][i].first] && edge[now][i].second >= weight) {
				q.push(edge[now][i].first);
				check[edge[now][i].first] = true;
			}
	}
	return 0; //가지 못했다.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int biggest = 0, output = 0;
	cin >> N >> M;
	edge.assign(N + 1, vector<pair<int, int>> ());
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
		biggest = max(biggest, c);
	}
	cin >> da >> db;
	//이분탐색을 진행한다.
	int left = 1, right = biggest, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (BFS(mid)) {
			left = mid + 1;
			output = max(output, mid);
		}
		else
			right = mid - 1;
	}
	cout << output;
}