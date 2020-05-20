#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

//[해킹 난이도★★](https://www.acmicpc.net/problem/10282)

void run() {
	vector<pair<int,int>> arr[10001];
	int dist[10001];
	int n, d, c;
	cin >> n >> d >> c;
	for (int i = 0; i <= n; i++)
		dist[i] = INT32_MAX;
	for (int i = 0; i < d; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		arr[b].push_back({ a,s });
	}
	queue<pair<int,int>> q;
	q.push({ c, 0 });
	dist[c] = 0;
	while (!q.empty()) {
		int pos = q.front().first;
		int tt = q.front().second;
		q.pop();
		if (tt > dist[pos])
			continue;
		for (int i = 0; i < arr[pos].size(); i++) {
			if (dist[arr[pos][i].first] > tt + arr[pos][i].second) {
				dist[arr[pos][i].first] = tt + arr[pos][i].second;
				q.push({ arr[pos][i].first,dist[arr[pos][i].first] });
			}
		}
	}
	int cnt = 0;
	int maxs = 0;
	for (int i = 0; i <= n; i++) {
		if (dist[i] == INT32_MAX)
			continue;
		cnt++;
		maxs = maxs < dist[i] ? dist[i] : maxs;
	}
	cout << cnt << " " << maxs << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		run();
	}
}