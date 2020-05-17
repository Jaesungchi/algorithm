#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

//[인터넷 설치 난이도★★★](https://www.acmicpc.net/problem/1800)
/*
	이분탐색 느낌으로다가 바꿔야지 시간초과가 나지 않는다.
*/

vector<pair<int, int>> arr[1010];
int dist[1010];
int N, P, K;

bool chk(int x) {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0, 1 });
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	while (pq.size()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[now] < cost) continue;
		for (auto i : arr[now]) {
			int nxt = i.first;
			int nxtCost = cost + (i.second > x);
			if (nxtCost < dist[nxt]) {
				dist[nxt] = nxtCost;
				pq.push({ -nxtCost, nxt });
			}
		}
	}

	return dist[N] <= K;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> P >> K;
	for (int i = 0; i < P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}
	int output = -1;
	int left = 0, right = 1e7;
	while (left <= right) {
		int mid = left + right >> 1;
		if (chk(mid)) {
			output = mid;
			right = mid - 1;
		}
		else 
			left = mid + 1;
	}
	cout << output << "\n";
}