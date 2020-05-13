#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//[트리의 지름](https://www.acmicpc.net/problem/1967)

int N;

//찾은 제일 먼 인덱스와 얼마인지 돌려준다.
pair<int,int> BFS(int idx, vector<vector<pair<int, int>>> V) {
	int S = 0, most = 1;
	bool chk[10001];
	memset(chk, false, sizeof chk);
	queue<pair<int, int>> q;
	chk[idx] = true;
	q.push(make_pair(idx, 0));
	while (!q.empty()) {
		int tmp = q.front().first;
		int sc = q.front().second;
		q.pop();
		for (int i = 0; i < V[tmp].size(); i++) {
			if (chk[V[tmp][i].first])
				continue;
			chk[V[tmp][i].first] = true;
			int tmpScore = sc + V[tmp][i].second;
			q.push(make_pair(V[tmp][i].first, tmpScore));
			if (S < tmpScore) {
				S = tmpScore;
				most = V[tmp][i].first;
			}
		}
	}
	return make_pair(most, S);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<vector<pair<int, int>>> arr(N+1);
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}
	pair<int, int> tmp = BFS(1, arr);
	tmp = BFS(tmp.first, arr);
	cout << tmp.second << "\n";
}