#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
using namespace std;

//[벽 부수고 이동하기4 난이도★★](https://www.acmicpc.net/problem/16946)
//쉽게 접근했어 해결함. 마지막 %10 을 빼먹어서 틀림

int N, M; // 1<= N, M <= 1000
int map[1001][1001];
int saveMap[1001][1001];
vector<int> saveCount;
int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };

void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << map[i][j];
		cout << "\n";
	}
}

void countMap(int y, int x) {
	set<int> sets;
	int sum = 1; //자기 자신자리
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (tx < 0 || ty < 0 || tx >= M || ty >= N) continue;
		if (map[ty][tx] == 1) continue;
		sets.insert(saveMap[ty][tx]);
	}
	for(set<int>::iterator iter = sets.begin();iter != sets.end();iter++)
		sum += saveCount[*iter];
	map[y][x] = sum%10;
}

void run(int y, int x) {
	int counts = 0,index = saveCount.size();
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	saveMap[y][x] = index;
	while (!q.empty()) {
		int rx = q.front().second;
		int ry = q.front().first;
		q.pop();
		counts++;
		for (int i = 0; i < 4; i++) {
			int tx = rx + dx[i];
			int ty = ry + dy[i];
			if (tx < 0 || ty < 0 || tx >= M || ty >= N) continue;
			if (map[ty][tx] == 1 || saveMap[ty][tx] != 0) continue; //이미 있는땅
			saveMap[ty][tx] = index;
			q.push(make_pair(ty, tx));
		}
	}
	saveCount.push_back(counts);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	saveCount.push_back(0); //size하나를 늘리기 위해.
	string tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
	//빈칸마다 갈 수 있는 사이즈를 계산한다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0 && saveMap[i][j] == 0)
				run(i, j);
	//상하좌우를 더한다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1)
				countMap(i, j);
	printMap();
}