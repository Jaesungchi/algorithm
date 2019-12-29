#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11053 ���� �� �����ϴ� �κ� ����
//�� �� �� �ڱ⺸�� ������ ���̰� ����� ģ�� ���� ������ �Ѿ��.

int N, m_max = 1, temp, datas[1001], DP[1001];

int Max(int x, int y) {
	return DP[x] > DP[y] ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <=N; i++)
		cin >> datas[i];
	for (int i = 1; i <=N; i++) {
		temp = 0;
		for (int j = 1; j <= i; j++) {
			if (datas[i] > datas[i - j])
				temp = Max(temp, i - j);
		}
		DP[i] = DP[temp] + 1;
		m_max = m_max < DP[i] ? DP[i] : m_max;
	}
	cout << m_max;
}