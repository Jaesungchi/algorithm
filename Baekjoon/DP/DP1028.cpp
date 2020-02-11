#include <iostream>
#include <string>
#include <algorithm>
#define TO_NE 0
#define TO_NW 1
#define TO_SE 2
#define TO_SW 3
using namespace std;

//[다이아몬드 광산 난이도★★★](https://www.acmicpc.net/problem/1028)
// = 하나 빠져서 계속 틀렸다...

int N, M;
string map[751];
int DP[751][751][4];
int maxs = 0;
int dy[4] = { -1,-1,1,1 }, dx[4] = { 1,-1,1,-1 };

bool outMap(int y, int x) {
	if (x < 0 || y < 0 || x >= M || y >= N)
		return true; //탈출한경우.
	return false;
}

void getLength(int y, int x, int dir) {
	//dir이 아래방향이면 dir을 뒤집어서 반대방향을 확인한다.
	int myUpx = x + dx[dir > TO_NW ? dir == TO_SW ? TO_NE : TO_NW : dir];
	int myUpy = y + dy[dir > TO_NW ? dir == TO_SW ? TO_NE : TO_NW : dir];

	if (!outMap(myUpy, myUpx) && map[myUpy][myUpx] == '1') {
		if (dir < TO_SE)
			DP[y][x][dir] = DP[myUpy][myUpx][dir] + 1;
		else if (dir > TO_NW)
			DP[y][x][dir] = DP[myUpy][myUpx][dir] - 1;
		return;
	}
	int sum = 0;
	int tx = x + dx[dir];
	int ty = y + dy[dir];
	while (!outMap(ty, tx) && map[ty][tx] == '1') {
		sum++;
		tx += dx[dir];
		ty += dy[dir];
	}
	DP[y][x][dir] = sum;
}

int getDia(int y, int x) {
	int sizes = 0;
	int maxSize = min(DP[y][x][TO_SE], DP[y][x][TO_SW]); //제일 아래로 많이 내려가는 것을 찾는다.
	while (maxSize >= 0) {
		sizes = maxSize--;
		//왼쪽으로 내려간거 확인.
		if (outMap(y + sizes, x - sizes)) continue;
		if (DP[y + sizes][x - sizes][TO_SE] < sizes) continue; //작아서그만큼 못간다면.
		//오른쪽으로 확인
		if (outMap(y + sizes, x + sizes))continue;
		if (DP[y + sizes][x + sizes][TO_SW] < sizes) continue; //작아서 못감.
		break; //여기 까지 온거면 가능한경우.
	}
	return sizes + 1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	//각 다이아몬드별 최대 길이를 구함
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == '1')
				for (int k = 0; k < 4; k++)
					getLength(i, j, k);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == '1')
				maxs = max(maxs, getDia(i, j));
	cout << maxs << "\n";
}