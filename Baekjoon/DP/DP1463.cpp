#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1463 1로 만들기
// dfs ,bfs는 시간초과 함.
// DP에 대해서 이해할 수 있는 문제

int N, sums[1000001];

int main() {
	cin >> N;
	int A, B, C;
	sums[1] = 0;
	for (int i = 2; i <= N; i++) { // 1은 0 부터 시작해서 N까지 모든 수의 최소경로를 구해본다.
		A = B = C = 999999;
		if (i % 3 == 0)
			A = sums[i / 3] + 1;
		if (i % 2 == 0)
			B = sums[i / 2] + 1;
		C = sums[i - 1] + 1;
		sums[i] = A < B ? A < C ? A : C : B < C ? B : C;
	}
	cout << sums[N];
}