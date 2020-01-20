#include <iostream>
#include <algorithm>
using namespace std;

//[컨닝 난이도★★★★★](https://www.acmicpc.net/problem/1014)

int T, N, M; //TestCase , 세로 N 가로 M;
char map[10][11];
int DP[1 << 10][11];//1111111111로 앉을 수 있다.
int dx[4] = { 1,1,-1,-1 }, dy[4] = { 0,-1,0,-1 };

void resetDP() {
	for (int i = 0; i < (1<<10); i++)
		for (int j = 0; j < 11; j++)
			DP[i][j] = -1;
}

//n이 0이면 앉아도됨, 1이면 앉으면 안됨.
int getDP(int n, int m) { //n은 저번줄이 어떻게 앉았는지 m은 다음줄
	if (m == M) return 0;// 모든줄이 끝남
	if (DP[n][m] != -1) return DP[n][m]; //이미 정보가 있다면?
	int lastN = n; // 현재 턴에서 사용 불가능한 자리 표시 위한 변수 
	for (int i = 0; i < N; ++i) { 
		if ((n & (1 << i)) > 0) { 
			lastN |= (1 << (i + 1)); // 이 자리 또한 사용 불가능 
			lastN |= (1 << (i - 1)); // 이 자리 또한 사용 불가능 
		} 
	}
	int result = getDP(0, m + 1); // 아무 학생도 앉히지 않고 다음 줄로 넘어가는 경우 (Default) 
	for (int i = 1; i < (1 << N); ++i) { // 학생을 앉히는 경우 
		if ((i & lastN) > 0) continue; // 나올 수 없는 경우의 수 제외하기
		int count = 0; // 학생 수를 세기 위함 (비트 연산)
		bool isAvail = true;
		for (int j = 0; j < N && isAvail; ++j) {
			if ((i & (1 << j)) > 0) { // 이 자리에 학생이 앉아있는 경우 
				count++;
				if (map[j][m] == 'x') 
					isAvail = false; // 이 자리가 장애물이 있으면 이 또한 나올 수 없는 경우의 수 
			}
		}
		if (!isAvail) continue; // 장애물 체크
		result = max(result, getDP(i, m + 1) + count);
	}
	return DP[n][m] = result;
}

int main() {
	cin >> T;
	for (T; T > 0; T--) {
		resetDP();
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];
		cout << getDP(0, 0) << "\n";
	}
}