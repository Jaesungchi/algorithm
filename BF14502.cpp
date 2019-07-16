#include <iostream>
using namespace std;

int map[8][8];
int tempMap[8][8];
int N, M; //����N ����M
int maxSafe = -1;

void safeCount() {
	bool CanVirus = false; //�̵��� ������ ���̷����� �ִٸ� true�� �ٲ��� ��ͷ� ��.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempMap[i][j] == 2) { //���̷��� ���
				if (j + 1 < M && tempMap[i][j + 1] == 0) {
					tempMap[i][j + 1] = 2;
					CanVirus = true;
				}
				if (j - 1 >= 0 && tempMap[i][j - 1] == 0) {
					tempMap[i][j - 1] = 2;
					CanVirus = true;
				}
				if (i + 1 < N && tempMap[i + 1][j] == 0) {
					tempMap[i + 1][j] = 2;
					CanVirus = true;
				}
				if (i - 1 >= 0 && tempMap[i - 1][j] == 0) {
					tempMap[i - 1][j] = 2;
					CanVirus = true;
				}
			}
		}
	}
	if (CanVirus) //�̵��� �� ���̷����� �ִٸ� �ѹ��� �̵���Ŵ.
		return safeCount();
	//���⼭ ���� ���̷��� �̵��� ���� (�� ���� ���̷��� �� ������)

	int safeCounts = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempMap[i][j] == 0)
				safeCounts += 1;
		}
	}
	if (maxSafe < safeCounts) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << tempMap[i][j] << " ";
			}
			cout << '\n';
		}
		cout << maxSafe << "  " << safeCounts << "\n";
		maxSafe = safeCounts;
	}
	
}
void SetWall(int counts,int countWall) {
	if (countWall == 3) { //3���� �� ä������ Ȯ�ν�Ų��.
		safeCount();
		return;
	}
	if (counts >= N*M) //��������� �Ѿ���� ����
		return;
	if (map[counts/M][counts%M] != 0) { //���� �ƴϸ�
		SetWall(counts+1, countWall); //���� �ƴ϶�� ��������
		return;
	}
	tempMap[counts / M][counts%M] = 1;
	SetWall(counts + 1, countWall + 1); //���� ���� �ѱ�°��
	tempMap[counts / M][counts%M] = 0;
	SetWall(counts + 1, countWall);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			tempMap[i][j] = map[i][j];
		}
	}
	SetWall(0, 0);
	cout << maxSafe;
	return 0;
}