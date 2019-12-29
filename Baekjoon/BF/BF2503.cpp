#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2503 숫자 야구

int numbers[1000];
int N,boolCheck[101][3],counts = 0;

int CheckStrike(int a1, int a2, int a3, int b1, int b2, int b3) {
	int strike = 0;
	if (a1 == b1)
		strike++;
	if (a2 == b2)
		strike++;
	if (a3 == b3)
		strike++;
	return strike;
}

int CheckBall(int a1, int a2, int a3, int b1, int b2, int b3) {
	int ball = 0;
	if (a1 == b2 || a1 == b3)
		ball++;
	if (a2 == b1 || a2 == b3)
		ball++;
	if (a3 == b1 || a3 == b2)
		ball++;
	return ball;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> boolCheck[i][0] >> boolCheck[i][1] >> boolCheck[i][2];
	for (int i = 123; i <= 987; i++) {
		int a3 = i % 10;
		int a2 = ((i % 100) - a3) / 10;
		int a1 = (i - (a2*10) - a3) / 100;
		if (a3 == 0 || a2 == 0 || a1 == 0 || a1 == a2 || a2 == a3 || a1 == a3)
			continue;
		for (int j = 0; j < N; j++) {
			int b3 = boolCheck[j][0] % 10;
			int b2 = ((boolCheck[j][0] % 100)- b3) / 10;
			int b1 = (boolCheck[j][0] - (b2 * 10) - b3) / 100;
			int strike = 0, ball = 0;
			strike = CheckStrike(a1, a2, a3, b1, b2, b3);
			ball = CheckBall(a1, a2, a3, b1, b2, b3);
			if (strike == boolCheck[j][1] && ball == boolCheck[j][2])
				numbers[i]++;
		}
		if (numbers[i] == N)
			counts++;
	}
	cout << counts << "\n";
}