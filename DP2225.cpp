#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2225 �պ���
//��Ģã�Ⱑ �������.

long N,A, DP[201][201];

int main() {
	cin >> N >> A;
	for (int i = 0; i <= N; i++)
		DP[1][i] = 1; //1�� �̾Ƽ� i �� ���� ���� 1����.
	for (int k = 2; k <= A; k++) //���� �ڱ� ���� ���� �� �� ���ϸ� ��.
		for (int n = 0; n <= N; n++) {
			for (int l = 0; l <= n; l++)
				DP[k][n] += DP[k - 1][l];
			DP[k][n] %= 1000000000;
		}
	cout << DP[A][N] << "\n";
}