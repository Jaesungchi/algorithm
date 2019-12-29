#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/13458

int topni[4][8];
int turnCount, temp;
int A, B;

int GetScore() {
	int sum = 0;
	if (topni[0][0] == 1)
		sum += 1;
	if (topni[1][0] == 1)
		sum += 2;
	if (topni[2][0] == 1)
		sum += 4;
	if (topni[3][0] == 1)
		sum += 8;
	return sum;
}

void TurnTopni(int A, int B, int dir) { //dir�� ��͸� ������ �����̸� 1 �������̸� 2��
	if (dir != 2 && A != 0) { //�������� �������� �������� �ִ��� Ȯ���� �Ѿ
		if (topni[A][6] != topni[A - 1][2])
			TurnTopni(A - 1, B == -1 ? 1 : -1, 1);
	}
	if (dir != 1 && A != 3) { //���������� ���� ���� �ִ��� Ȯ���� �Ѿ
		if (topni[A][2] != topni[A + 1][6])
			TurnTopni(A + 1, B == -1 ? 1 : -1, 2);
	}
	int temp = topni[A][0];
	int temp1 = 0;
	if (B == 1) { //���������� ȸ���Ѵٸ�.
		for (int i = 1; i <= 8; i++) {
			temp1 = topni[A][i % 8];
			topni[A][i % 8] = temp;
			temp = temp1;
		}
	}
	else { //�ݴ�������� ȸ���Ѵٸ�.
		for (int i = 7; i >= 0; i--) {
			temp1 = topni[A][i % 8];
			topni[A][i % 8] = temp;
			temp = temp1;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		for (int j = 7; j >= 0; j--) {
			topni[i][j] = temp % 10;
			temp /= 10;
		}
	}
	cin >> turnCount;
	for (int i = 0; i < turnCount; i++) {
		cin >> A >> B;
		TurnTopni(A - 1, B, 0);
	}
	cout << GetScore();
}