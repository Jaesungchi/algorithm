#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

//[암벽등반 난이도★★](https://www.acmicpc.net/problem/2412)

int n, T; // 1 <= n <= 50,000 1<= t <= 200,000
vector<pair<int, int>> arr;
bool chk[50001];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (b.second == a.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> T;
	arr.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		arr.push_back(make_pair(t1, t2));
	}
	sort(arr.begin(), arr.end(), compare);

	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = arr[q.front().first].first, y = arr[q.front().first].second;
		int tc = q.front().second;
		q.pop();
		if (y == T) {
			cout << tc << "\n";
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			int nx = arr[i].first, ny = arr[i].second;
			if (chk[i])
				continue;
			if (abs(nx - x) <= 2 && abs(ny - y) <= 2) {
				q.push(make_pair(i, tc + 1));
				chk[i] = true;
			}
			else if (abs(ny - y) > 2 && abs(nx - x)) //정렬해서 y값이 넘으면 끝.
				break;
		}
	}
	cout << "-1" << "\n";
	return 0;
}