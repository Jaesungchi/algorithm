#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };

int n; //25이하. 25*25;
int answer = INT_MAX;
vector<vector<int>> rboard;

void DFS(int y, int x, int dir,int cost) {
	if (y == n - 1 && x == n - 1) {
		answer = min(answer, cost);
		return;
	}
	//뒤로 가지않게 조심.
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (ty < 0 || tx < 0 || tx >= n || ty >= n)
			continue;
		if (rboard[ty][tx] == 1)
			continue;
		if (dir == i || dir == -1) { //
			if (rboard[ty][tx] == 0 || rboard[ty][tx] >= cost + 100) {
				rboard[ty][tx] = cost + 100;
				DFS(ty, tx, i, cost + 100);
			}
		}
		else {
			if (rboard[ty][tx] == 0 || rboard[ty][tx] >= cost + 600) {
				rboard[ty][tx] = cost + 600;
				DFS(ty, tx, i, cost + 600);
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	n = board.size();
	rboard.assign(board.begin(), board.end());
	rboard[0][0] = 2;
	DFS(0, 0, -1, 0);
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<int>> vvi;
	vector<int> vi;
	vi.push_back(0);
	vi.push_back(0);
	vi.push_back(1);
	vi.push_back(0);
	vvi.push_back(vi);
	vi.clear();
	vi.push_back(0);
	vi.push_back(0);
	vi.push_back(0);
	vi.push_back(0);
	vvi.push_back(vi);
	vi.clear();
	vi.push_back(0);
	vi.push_back(1);
	vi.push_back(0);
	vi.push_back(1);
	vvi.push_back(vi);
	vi.clear();
	vi.push_back(1);
	vi.push_back(0);
	vi.push_back(0);
	vi.push_back(0);
	vvi.push_back(vi);

	cout << solution(vvi);
}