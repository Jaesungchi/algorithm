#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2579 계단오르기
//너무 어렵게 생각하고 있었다...ㅠ

int N, datas[302], DP[302];

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> datas[i];
	DP[1] = datas[1];
	DP[2] = Max(datas[1] + datas[2], datas[2]);
	for (int i = 3; i <= N; i++) {
		DP[i] = Max(DP[i - 2] + datas[i], DP[i - 3] + datas[i] + datas[i - 1]);
	}
	cout << DP[N] << "\n";
}