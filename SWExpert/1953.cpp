#include <iostream>
using namespace std;

//SWEA 1953 탈주범 검거
//갔던곳을 더 짧게가는경우를 생각을 못했다 따흑...

int T, N, M, R, C, L,temp; //0 : 위 1 : 왼쪽 2 : 아래 3 : 오른쪽 
int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 },mapC[51][51];
bool map[51][51][5];

int CountOK() {
	int sums = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j][4])
				sums += 1;
		}
	}
	return sums;
}

void dfs(int y, int x, int countS) {
	if (countS == L)
		return;
	map[y][x][4] = true; //방문
	mapC[y][x] = countS;

	for (int i = 0; i < 4; i++) {
		if (y + dy[i] < 0 || y + dy[i] >= N || x + dx[i] < 0 || x + dx[i] >= M)
			continue;
		if (!map[y][x][i]) //갈 수 있는길이 아니라면
			continue;
		if (map[y + dy[i]][x + dx[i]][4]) //갔던 곳이라면
			if(mapC[y+dy[i]][x+dx[i]] < countS)
			continue;
		if (map[y + dy[i]][x + dx[i]][(i + 2) % 4])
			dfs(y + dy[i], x + dx[i], countS+1);
	}
}

void SetMap(int y, int x, int types) {
	for (int i = 0; i < 5; i++)
		map[y][x][i] = false;
	switch (types)
	{
	case 1:
		for (int i = 0; i < 4; i++)
			map[y][x][i] = true;
		break;
	case 2:
		map[y][x][0] = true;
		map[y][x][2] = true;
		break;
	case 3:
		map[y][x][1] = true;
		map[y][x][3] = true;
		break;
	case 4:
		map[y][x][0] = true;
		map[y][x][3] = true;
		break;
	case 5:
		map[y][x][2] = true;
		map[y][x][3] = true;
		break;
	case 6:
		map[y][x][1] = true;
		map[y][x][2] = true;
		break;
	case 7:
		map[y][x][0] = true;
		map[y][x][1] = true;
		break;
	default:
		break;
	}
}

void GetRun(int counts) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> temp;
			SetMap(i, j, temp);
		}
	dfs(R, C, 0);
	cout << "#" << counts << " " << CountOK() <<"\n";
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> R >> C >> L;
		GetRun(i);
	}
}