#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15683 //감시

int map[9][9], tempMap[9][9];
int N, M, CameraCount = 0;
int cameraState[8][4]; //0은 북쪽 1은 동쪽 2는 남쪽 3은 서쪽으로 통일.
int minBlind = 999999;

void ResetMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			map[i][j] = tempMap[i][j];
	}
}

void CheckBlind() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				sum += 1;
		}
	}
	if (minBlind > sum) {
		minBlind = sum;
	}
	ResetMap();
}


void GetGround(int i, int j, int dir) {
	switch (dir) {
	case 0: // 북쪽을 쐈을때
		for (int k = 0; k < 8; k++) {
			if (i - k >= 0 && map[i - k][j] != 6)
				map[i - k][j] = 9;
			else
				break;
		}
		break;
	case 1: //동쪽을 쐈을때
		for (int k = 0; k < 8; k++) {
			if (j + k < M && map[i][j + k] != 6)
				map[i][j + k] = 9;
			else
				break;
		}
		break;
	case 2: //남쪽을 쐈을때
		for (int k = 0; k < 8; k++) {
			if (i + k < N && map[i + k][j] != 6)
				map[i + k][j] = 9;
			else
				break;
		}
		break;
	case 3: //서쪽을 쐈을때
		for (int k = 0; k < 8; k++) {
			if (j - k >= 0 && map[i][j - k] != 6)
				map[i][j - k] = 9;
			else
				break;
		}
		break;
	}
}

void CheckCamera(int i, int j, int num, int dir) {
	switch (num) {
	case 1:
		GetGround(i, j, dir);
		break;
	case 2:
		GetGround(i, j, dir);
		GetGround(i, j, (dir + 2) % 4);
		break;
	case 3:
		GetGround(i, j, dir);
		GetGround(i, j, (dir - 1) % 4);
		break;
	case 4:
		GetGround(i, j, dir);
		GetGround(i, j, (dir - 1) % 4);
		GetGround(i, j, (dir + 1) % 4);
		break;
	case 5: // 4방향 모두 가져온다.
		for (int k = 0; k < 4; k++)
			GetGround(i, j, k);
		break;
	}
}

void ShotCamera(int CountReturn) {
	if (CountReturn == CameraCount) {
		for (int i = 0; i < CameraCount; i++) {
			CheckCamera(cameraState[i][0], cameraState[i][1], cameraState[i][2], cameraState[i][3]);
		}
		CheckBlind();
		return;
	}
	for (int i = 0; i < 4; i++) { //재귀를 돌려서 확인 시킨다.
		cameraState[CountReturn][3] = i;
		ShotCamera(CountReturn + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			tempMap[i][j] = map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) { //카메라인지 확인 후 데이터를 넣는다.
				cameraState[CameraCount][0] = i; //수직 좌표
				cameraState[CameraCount][1] = j; //수평 좌표
				cameraState[CameraCount][2] = map[i][j]; //어떤 종류인지
				cameraState[CameraCount][3] = 0; //default로 위를 보게한다.
				CameraCount += 1;
			}
		}
	}
	ShotCamera(0);
	cout << minBlind;
}