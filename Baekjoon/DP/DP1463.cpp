#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1463 1�� �����
// dfs ,bfs�� �ð��ʰ� ��.
// DP�� ���ؼ� ������ �� �ִ� ����

int N, sums[1000001];

int main() {
	cin >> N;
	int A, B, C;
	sums[1] = 0;
	for (int i = 2; i <= N; i++) { // 1�� 0 ���� �����ؼ� N���� ��� ���� �ּҰ�θ� ���غ���.
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