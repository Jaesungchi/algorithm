#include <iostream>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/14500 테트로미노
//그려서 좌표화 시켜서 하니깐 머리는 별로 안쓰고 할 수 있었는데 코드 가 김.

int map[501][501];
int N, M ,m_max = 0,sums = 0;

void Max() {
	m_max = m_max > sums ? m_max : sums;
	sums = 0;
}

void NiumTet(int y, int x) {
	int dx[4] = { 0,1,0,0 }, dy[4] = { 0,0,1,2 };
	if (x + 1 < M && y + 2 < N) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dy[i]][x + dx[i]];
		Max();
	}
	if (x - 1  >= 0 && y + 2 < N) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dy[i]][x - dx[i]];
		Max();
	}
	if (x + 1 < M && y - 2 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dy[i]][x + dx[i]];
		Max();
	}
	if (x - 1 >= 0 && y - 2 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dy[i]][x - dx[i]];
		Max();
	}
	if (x - 2 >= 0 && y - 1 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dx[i]][x - dy[i]];
		Max();
	}
	if (x + 2 < M && y - 1 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dx[i]][x + dy[i]];
		Max();
	}
	if (x - 2 >= 0 && y + 1 < N) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dx[i]][x - dy[i]];
		Max();
	}
	if (x + 2 < M && y + 1 < N) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dx[i]][x + dy[i]];
		Max();
	}
}

void LLLTet(int y, int x) {
	int dx[4] = { 0,0,1,1 }, dy[4] = { 0,1,1,2 };
	if (y - 2 >= 0 && x - 1 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dy[i]][x - dx[i]];
		Max();
	}
	if (y + 2 < N && x - 1 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dy[i]][x - dx[i]];
		Max();
	}
	if (y + 2 < N && x + 1 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dy[i]][x + dx[i]];
		Max();
	}
	if (y - 2 >= 0 && x + 1 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dy[i]][x + dx[i]];
		Max();
	}
	if (y - 1 >= 0 && x - 2 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dx[i]][x - dy[i]];
		Max();
	}
	if (y + 1 < N && x - 2 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dx[i]][x - dy[i]];
		Max();
	}
	if (y + 1 < N && x + 2 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dx[i]][x + dy[i]];
		Max();
	}
	if (y - 1 >= 0 && x + 2 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dx[i]][x + dy[i]];
		Max();
	}
}

void FUCTet(int y, int x) {
	int dx[4] = { 0,-1,1,0 }, dy[4] = { 0,0,0,1 };
	if (y - 1 >= 0 && x - 1 >= 0 && y + 1 < N) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dx[i]][x - dy[i]];
		Max();
	}
	if (y - 1 >= 0 && x + 1 < M && y + 1 < N) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dx[i]][x + dy[i]];
		Max();
	}
	if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dy[i]][x + dx[i]];
		Max();
	}
	if (x - 1 >= 0 && y + 1 < N && x + 1 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dy[i]][x + dx[i]];
		Max();
	}
}

void BoxTet(int y, int x) {
	int dx[4] = { 0,1,0,1 }, dy[4] = { 0,0,1,1 };
	if (y - 1 >= 0 && x - 1 >= 0) {
		for (int i = 0; i < 4 ; i++)
			sums += map[y - dy[i]][x - dx[i]];
		Max();
	}
	if (y - 1 >= 0 && x + 1 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y - dy[i]][x + dx[i]];
		Max();
	}
	if (y + 1 < N && x + 1 < M) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dy[i]][x + dx[i]];
		Max();
	}
	if (y + 1 < N && x - 1 >= 0) {
		for (int i = 0; i < 4; i++)
			sums += map[y + dy[i]][x - dx[i]];
		Max();
	}
}

void BarTet(int y, int x) {
	if (y - 3 >= 0) { //위로 갈 수 있다면
		for (int i = 0; i < 4; i++)
			sums += map[y - i][x];
		Max();
	}
	if (y + 3 < N) { //아래로 갈 수 있다면
		for (int i = 0; i < 4; i++)
			sums += map[y + i][x];
		Max();
	}
	if (x - 3 >= 0) { //왼쪽으로 갈 수 있다면
		for (int i = 0; i < 4; i++)
			sums += map[y][x-i];
		Max();
	}
	if (x + 3 >= 0) { //왼쪽으로 갈 수 있다면
		for (int i = 0; i < 4; i++)
			sums += map[y][x+i];
		Max();
	}
}

void SwitchTetromino(int selects,int y, int x) {
	switch (selects)
	{
	case 0:
		BarTet(y, x);
		break;
	case 1:
		BoxTet(y, x);
		break;
	case 2:
		NiumTet(y, x);
		break;
	case 3:
		LLLTet(y, x);
		break;
	case 4:
		FUCTet(y, x);
		break;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < 5; k++)
				SwitchTetromino(k,i,j);
	cout << m_max;
}