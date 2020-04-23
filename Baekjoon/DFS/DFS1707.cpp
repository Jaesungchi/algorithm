#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

//[이분 그래프 난이도★★](https://www.acmicpc.net/problem/1707)

vector<int> a[20001];
int color[20001];

void dfs(int start, int c) {
	color[start] = c;
	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];
		if (color[next] == 0)
			dfs(next, 3 - c);
	}
}

void run() {
	int v, e;
	bool result = true;
	cin >> v >> e;
	//정점 초기화
	for (int i = 1; i <= v; i++) {
		a[i].clear();
		color[i] = 0;
	}
	//간선 입력 받는다.
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= v; i++)
		if (color[i] == 0)
			dfs(i, 1);
	for (int i = 1; i <= v; i++)
		for (int k = 0; k < a[i].size(); k++) {
			int j = a[i][k];
			if (color[i] == color[j])
				result = false;
		}
	cout << result ? "YES" : "NO" ;
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