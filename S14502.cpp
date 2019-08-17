#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14502 연구소

int N, M, map[9][9], map2[9][9], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 },MaxSafe = 0;
bool checkM[9][9];

void ResetMap() {
	for(int i = 0 ; i < N ; i++)
		for (int j = 0; j < M; j++) {
			checkM[i][j] = false;
			map[i][j] = map2[i][j];
		}
}

void SaveMap() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map2[i][j] = map[i][j];
}

void PrintMap() {
	cout << "\n";
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}

void CountSafe() {
	int countZero = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				countZero++;
		}
	if (MaxSafe < countZero) {
		MaxSafe = countZero;
		//PrintMap();
		//cout << countZero << "\n";
	}
}

void SpreadMap(int x, int y) {
	checkM[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) //맵을 넘어갔다면
			continue;
		if (checkM[ny][nx]) //이미 들렀던 곳이라면
			continue;
		if (map[ny][nx] != 1) { //빈공간이라면
			SpreadMap(nx, ny);
			map[ny][nx] = 2;
		}
	}
}

void SetWall(int x, int y, int count) {
	if (count == 3) {
		SaveMap();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!checkM[i][j] && map[i][j] == 2)
					SpreadMap(j, i);
		CountSafe();
		ResetMap();
		return;
	}

	if (map[y][x] != 0) { //빈공간이 아니라면
		if (x + 1 <= M)
			SetWall(x + 1, y, count);
		else if (y + 1 <= N)
			SetWall(0, y + 1, count);
		return;
	}

	map[y][x] = 1; //벽을 놓고 넘긴다.
	if (x + 1 <= M)
		SetWall(x + 1, y, count + 1);
	else if (y + 1 <= N)
		SetWall(0, y + 1, count + 1);
	
	map[y][x] = 0; //벽을 없애고 넘긴다.
	if (x + 1 <= M)
		SetWall(x + 1, y, count);
	else if (y + 1 <= N)
		SetWall(0, y + 1, count);
}

int main() {
	cin >> N >> M;
	for(int i = 0 ; i < N ; i ++)
		for (int j = 0;  j < M; j++)
			cin >> map[i][j];
	SetWall(0, 0, 0);

	cout << MaxSafe << "\n";
}