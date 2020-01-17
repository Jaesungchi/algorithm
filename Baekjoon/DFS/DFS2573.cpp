#include <iostream>
using namespace std;

//[빙산 난이도★★](https://www.acmicpc.net/problem/2573)

int R, C; //세로 R 가로 C
int Y = 0; //지나간 년도
int maps[301][301];//지도
bool checks[301][301]; //들렀는지 아닌지 체크
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

bool isAllZero() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (maps[i][j] > 0)
				return false;
	return true;
}

bool compareMapsChecks() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (maps[i][j] > 0 && !checks[i][j]) //잘못된 상황
				return true;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			checks[i][j] = false; //초기화한다.
	return false;
}

void DFS(int x, int y) {
	checks[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (maps[ty][tx] > 0 && !checks[ty][tx])
			DFS(tx, ty);
	}
}

bool isTwoPart() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (maps[i][j] > 0) {
				DFS(j, i);
				if (compareMapsChecks())
					return true;
				return false;
			}
}

void oneYear() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (maps[i][j] == 0) continue; //물은 지나간다.
			int counts = 0;
			for (int z = 0; z < 4; z++) //빼야할 빙하량을 계산
				if (maps[i + dy[z]][j + dx[z]] == 0)
					counts++;
			if (maps[i][j] - counts <= 0) //0보다 작은 값이라면
				maps[i][j] = -1; //일단 -1로 해둔다.
			else
				maps[i][j] -= counts;
		}
	//-1을 0으로 바꾼다.
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (maps[i][j] == -1)
				maps[i][j] = 0;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> maps[i][j];
	while (true) {
		if (isTwoPart())
			break;
		oneYear();
		Y++;
		if (isAllZero()) {
			Y = 0;
			break;
		}
	}
	cout << Y << "\n";
}