#include <iostream>
using namespace std;

int map[8][8];
int tempMap[8][8];
int N, M; //세로N 가로M
int maxSafe = -1;

void safeCount() {
	bool CanVirus = false; //이동이 가능한 바이러스가 있다면 true로 바껴서 재귀로 들어감.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempMap[i][j] == 2) { //바이러스 라면
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
	if (CanVirus) //이동을 한 바이러스가 있다면 한번더 이동시킴.
		return safeCount();
	//여기서 부터 바이러스 이동이 없음 (이 말은 바이러스 다 퍼졌다)

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
	if (countWall == 3) { //3개가 다 채워지면 확인시킨다.
		safeCount();
		return;
	}
	if (counts >= N*M) //수직사이즈를 넘어갔으면 종료
		return;
	if (map[counts/M][counts%M] != 0) { //빈땅이 아니면
		SetWall(counts+1, countWall); //빈땅이 아니라면 다음으로
		return;
	}
	tempMap[counts / M][counts%M] = 1;
	SetWall(counts + 1, countWall + 1); //벽을 짓고 넘기는경우
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