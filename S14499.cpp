#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14499

int map[20][20]; //지도를 포인터로 연결해둔다.
int dice[6]; //다이스에는 맨처음엔 0밖에 안적혀 있다.
int x, y; //지도의 좌표
int N, M; //크기 N,M의 지도를 받기 위해 변수 선언	

void rolldice(int roll) {
	int temp = dice[1];
	if (roll == 1) {
		if (x + 1 >= M)
			return;
		x += 1;
		dice[1] = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
	}
	else if (roll == 2) {
		if (x - 1 < 0)
			return;
		x -= 1;
		dice[1] = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[4];
		dice[4] = temp;
	}
	else if (roll == 3) {
		if (y - 1 < 0)
			return;
		y -= 1;
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[0];
		dice[0] = temp;
	}
	else if (roll == 4){
		if (y + 1 >= N)
			return;
		y += 1;
		dice[1] = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[2];
		dice[2] = temp;	
	}
	cout << dice[1] << '\n';
	if (map[y][x] == 0) {
		map[y][x] = dice[3];
	}
	else {
		dice[3] = map[y][x];
		map[y][x] = 0;
	}
}


int main() {							
	int code, way; //명령어
	for (int i = 0; i < 6; i++) {
		dice[i] = 0;
	}
	cin >> N >> M >> y >> x >> code; // c++ 은 앞으로 이렇게

	//지도에다가 데이터를 넣는 코드
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//code번 만큼 이동한다.
	for (int i = 0; i < code; i++) {
		cin >> way;
		rolldice(way);
	}
	return 0;
}