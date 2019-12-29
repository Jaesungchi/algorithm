#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/9465 ��ƼĿ
//�����ϸ鼭 �ϴ� ������ ����.

int datas[100001][2],DP[100001][2];

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int N,M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < M; k++)
				cin >> datas[k][j];
		DP[0][0] = datas[0][0];
		DP[0][1] = datas[0][1];
		for (int j = 1; j < M; j++) { //�������� ���̶� ���ؼ� �������� ���� ���� ���� �� �ݴ���� ���̶� ����
			DP[j][0] = Max(DP[j - 1][1], DP[j - 1][0] - datas[j - 1][0]) + datas[j][0];
			DP[j][1] = Max(DP[j - 1][0], DP[j - 1][1] - datas[j - 1][1]) + datas[j][1];
		}
		cout << Max(DP[M - 1][0], DP[M - 1][1]) << "\n";
	}
}