#include <vector>
#include <iostream>
using namespace std;

/*
4 3
1 4 8 10
5 5 5 5 
10 10 10 10
10 10 10 20

*/

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 },sizes = 0;
long long minCost = 999999999;

void Run(int x,int y, vector<vector<int>> land,int height,int Counts,long long currentCost , bool checks[300][300]) {
	if (Counts >= sizes*sizes) { //전체다 돌았을때.
		if (minCost > currentCost)
			minCost = currentCost;
		return;
	}
	checks[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (checks[x + dx[i]][y + dy[i]] || x +dx[i] < 0 || x+dx[i] >= sizes || y+dy[i] < 0 || y+ dy[i] >= sizes)
			continue;
		if (abs(land[x + dx[i]][y + dy[i]] - land[x][y]) <= height)
			Run(x + dx[i], y + dy[i], land, height, Counts + 1, currentCost, checks);
		else
			Run(x + dx[i], y + dy[i], land, height, Counts + 1, currentCost + abs(land[x + dx[i]][y + dy[i]] - land[x][y]), checks);
	}
	checks[x][y] = false;
}

int solution(vector<vector<int>> land, int height) {
	sizes = land.size();
	bool checks[300][300] = { false };

	for (int i = 0; i < sizes; i++) {
		for (int j = 0; j < sizes; j++) {
			Run(i, j, land, height, 1, 0,checks);
		}
	}

	return minCost;
}

int main() {
	int N,tmp,height;
	cin >> N >>height;
	vector<vector<int>> land;
	for (int i = 0; i < N; i++) {
		vector<int> tmps;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			tmps.push_back(tmp);
		}
		land.push_back(tmps);
	}
	cout << solution(land, height);
}