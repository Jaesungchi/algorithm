#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2156 ������ �ý�
//��Ģ�� ã�Ƴ��Ⱑ �������. �� ���ʸ� �°� �ٸ��� �ȸ´µ�
//�ٸ��� ã�°� �������.. ����� ������

int N,M, datas[10002], dp[10002][2];

int Max(int x ,int y) {
	return x < y ? y : x;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> datas[i];
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = datas[1];
	dp[1][1] = 1;
	M = dp[1][0];
	for (int i = 2; i <= N; i++) {
		if (dp[i - 1][1] == 1) { //��DP�� 1��°�� �׳� �ѹ��� ���Ŵ�.
			dp[i][0] = dp[i - 1][0] + datas[i];
			dp[i][1] = 2;
		}
		else { //���� DP�� ������DP + ��data�� ���ؼ� �� ���� ���� �ִ´�. 
			dp[i][0] = Max(dp[i - 2][0], dp[i - 3][0] + datas[i - 1]) + datas[i];
			dp[i][1] = dp[i - 2][0] > dp[i - 3][0] + datas[i - 1] ? 1 : 2;
		}
		dp[i][0] = Max(M, dp[i][0]);
		M = dp[i][0];
	}
	cout << dp[N][0];
}