#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15683 //����

int map[9][9], tempMap[9][9];
int N, M, CameraCount = 0;
int cameraState[8][4]; //0�� ���� 1�� ���� 2�� ���� 3�� �������� ����.
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
	case 0: // ������ ������
		for (int k = 0; k < 8; k++) {
			if (i - k >= 0 && map[i - k][j] != 6)
				map[i - k][j] = 9;
			else
				break;
		}
		break;
	case 1: //������ ������
		for (int k = 0; k < 8; k++) {
			if (j + k < M && map[i][j + k] != 6)
				map[i][j + k] = 9;
			else
				break;
		}
		break;
	case 2: //������ ������
		for (int k = 0; k < 8; k++) {
			if (i + k < N && map[i + k][j] != 6)
				map[i + k][j] = 9;
			else
				break;
		}
		break;
	case 3: //������ ������
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
	case 5: // 4���� ��� �����´�.
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
	for (int i = 0; i < 4; i++) { //��͸� ������ Ȯ�� ��Ų��.
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
			if (map[i][j] > 0 && map[i][j] < 6) { //ī�޶����� Ȯ�� �� �����͸� �ִ´�.
				cameraState[CameraCount][0] = i; //���� ��ǥ
				cameraState[CameraCount][1] = j; //���� ��ǥ
				cameraState[CameraCount][2] = map[i][j]; //� ��������
				cameraState[CameraCount][3] = 0; //default�� ���� �����Ѵ�.
				CameraCount += 1;
			}
		}
	}
	ShotCamera(0);
	cout << minBlind;
}