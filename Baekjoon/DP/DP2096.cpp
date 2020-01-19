#include <iostream>
using namespace std;

//[내려가기 난이도★★](https://www.acmicpc.net/problem/2096)

int N,leftDP,cenDP,rightDP;
int DP[3];
int lowDP[3];
int highDP[3];

int MIN(int a, int b) {
	if (a <= b) return a;
	return b;
}

int MAX(int a, int b) {
	if (a >= b) return a;
	return b;
}

int main() {
	//C++ 기본 세팅 시작
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//기본 세팅 끝
	//input 시작
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++)
			cin >> DP[j];
		//lowDP 계산
		leftDP = lowDP[0];
		cenDP = lowDP[1];
		rightDP = lowDP[2];
		lowDP[0] = MIN(leftDP, cenDP) + DP[0];
		lowDP[1] = MIN(MIN(leftDP,rightDP),cenDP) + DP[1];
		lowDP[2] = MIN(cenDP, rightDP) + DP[2];
		//highDP 계산
		leftDP = highDP[0];
		cenDP = highDP[1];
		rightDP = highDP[2];
		highDP[0] = MAX(leftDP, cenDP) + DP[0];
		highDP[1] = MAX(MAX(leftDP,cenDP),rightDP) + DP[1];
		highDP[2] = MAX(cenDP, rightDP) + DP[2];
	}
	//input 끝
	int mins = MIN(MIN(lowDP[0], lowDP[1]), lowDP[2]);
	int maxs = MAX(MAX(highDP[0], highDP[1]), highDP[2]);
	cout << maxs << " " << mins << "\n";

}