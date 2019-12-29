#include <iostream>
using namespace std;

//2105 디저트가게
//백트래킹을 활용한 재귀 문제
//생각보다 쉬우면서 어렵다.

int map[20][20], T, N, m_max = 0, dx[4] = { -1,1,1,-1 }, dy[4] = { 1,1,-1,-1 };
bool visited[101];

struct Point {
	int y, x, count;
	int startY, startX;
	int countCurve;
};

void ResetVisited() {
	for(int i = 0; i < 101; i++)
		visited[i] = false;
}

bool Welcome(int y, int y1, int x, int x1) {
	if (y == y1 && x == x1)
		return true;
	return false;
}

void dfs(Point cur) {
	if (cur.startX == cur.x && cur.startY == cur.y && cur.count != 1) {
		if (m_max < cur.count)
			m_max = cur.count-1;
		return;
	}
	visited[map[cur.y][cur.x]]= true;
	if (cur.countCurve >= 4)
		return;
	for (int i = 0; i < 2; i++) {
		if (cur.x + dx[cur.countCurve+i] >= 0 && cur.x + dx[cur.countCurve + i] < N && cur.y + dy[cur.countCurve + i] >= 0 && cur.y + dy[cur.countCurve + i] < N) {
			if (!visited[map[cur.y + dy[cur.countCurve + i]][cur.x + dx[cur.countCurve + i]]] || Welcome(cur.y + dy[cur.countCurve + i], cur.startY, cur.x + dx[cur.countCurve + i], cur.startX)) {
				Point newCur = { cur.y + dy[cur.countCurve + i],cur.x + dx[cur.countCurve + i],cur.count + 1,cur.startY,cur.startX,cur.countCurve + i };
				dfs(newCur);
			}
		}
	}
	visited[map[cur.y][cur.x]] = false;
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		m_max = 0;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cin >> map[j][k];
		for (int j = 0; j < N-2; j++)
			for (int k = 1; k < N-1; k++) {
				ResetVisited();
				Point cur = { j,k,1,j,k,0 };
				dfs(cur);
			}
		if (m_max == 0)
			m_max = -1;
		cout << "#" << i << " " << m_max << "\n";
	}
}