#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11052 ī�屸���ϱ�
//�������� ��ٷӱ⵵ ������ �������� ����.
//solve : 5:37

int N, datas[1002], DP[1002];

int GetMax(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> datas[i];
	DP[1] = datas[1];
	for (int i = 2; i <= N; i++) {
		DP[i] = datas[i];
		for (int j = 0; j <= i; j++)
			DP[i] = GetMax(DP[i], DP[i - j] + DP[j]);
	}
	cout << DP[N];
}