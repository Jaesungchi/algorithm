#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15662 톱니바퀴2
//전에 풀었던 방식이 애초에 갯수를 생각하지 않은 방식이라
//쉽게 풀 수 있었다. 
//문제 자체가 약간 숫자 놀음

int N, M, topni[1000][8], turnTopni, LeftOrRight, turnCount;

void TurnTopni(int number, int LeftOrRight, int Going) {
	if (Going != 0 && number + 1 < N) {
		if (topni[number + 1][6] != topni[number][2])
			TurnTopni(number + 1, LeftOrRight == 1 ? -1 : 1, 1);
	}
	if (Going != 1 && number - 1 >= 0) {
		if (topni[number - 1][2] != topni[number][6])
			TurnTopni(number - 1, LeftOrRight == 1 ? -1 : 1, 0);
	}
	int temp = topni[number][0];
	if (LeftOrRight == 1) //정방향으로 돌때
		for (int i = 1; i <= 8; i++) {
			int temp2 = topni[number][i % 8];
			topni[number][i % 8] = temp;
			temp = temp2;
		}
	else  //반대 방향으로 돌때
		for (int i = 7; i >= 0; i--) {
			int temp2 = topni[number][i % 8];
			topni[number][i % 8] = temp;
			temp = temp2;
		}
}

int CountS() { //위가 1인경우를 다 더한다.
	int sums = 0;
	for (int i = 0; i < N; i++) {
		if (topni[i][0] == 1)
			sums++;
	}
	return sums;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 7; j >= 0; j--) {
			topni[i][j] = M % 10;
			M /= 10;
		}
	}
	cin >> turnCount;
	for (int i = 0; i < turnCount; i++) {
		cin >> turnTopni >> LeftOrRight; //나는 톱니를 0번부터 해서 -1을 해준다
		TurnTopni(turnTopni - 1, LeftOrRight, -1);
	}
	cout << CountS();
}