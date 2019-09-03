#include <iostream>
#define MAX_SIZE 51
using namespace std;

//https://www.acmicpc.net/problem/17070 파이프 옮기기 1

int maps[MAX_SIZE][MAX_SIZE], N; //처음의 끝은 (1,2) 방향은 2 이다.
int dc[3] = { 1,1,0 }, dr[3] = { 0,1,1 },c_Size = 0;
bool CheckMap[MAX_SIZE][MAX_SIZE];

//파이프는 총 3 방향
//그에따른 dc,dr 설정

bool CheckGood(int r, int c) {
	for (int i = 0; i < 3; i++) { 
		int mr = r + dr[i];
		int mc = c + dc[i];
		if (mr <= 0 || mr > N || mc <= 0 || mc > N) //맵을 넘어가면.
			return false;
		if (CheckMap[mr][mc] || maps[mr][mc] == 1) //이미 파이프가 있거나 벽인 경우
			return false;
	}
	return true;
}

void dfs(int r,int c,int dir) {
	if (r == N && c == N) { //목적지에 도달하면
		c_Size++; //값을 추가한다.
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 2)
			continue;
		if (dir == 2 && i == 0)
			continue;
		int mr = r + dr[i];
		int mc = c + dc[i];
		if (mr <= 0 || mr > N || mc <= 0 || mc > N) //맵을 넘어가면.
			continue;
		if (CheckMap[mr][mc] || maps[mr][mc] == 1) //이미 파이프가 있거나 벽인 경우
			continue;
		if (i == 1) { //대각선인 경우 그양 옆을 다 확인해야함.
			if (!CheckGood(r, c))
				continue;
		}
		CheckMap[mr][mc] = true;
		dfs(mr, mc, i);
		CheckMap[mr][mc] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	CheckMap[1][1] = true;
	CheckMap[1][2] = true;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> maps[i][j];

	dfs(1, 2, 0);

	cout << c_Size << "\n";
}