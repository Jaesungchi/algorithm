#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11054 ���� �� ������� �κ� ����
//�� ��Ģ ���ϱ�

int N, tempU = 0,tempD = 0, m_max, datas[1001], DP[1001][2]; //DP[x][0]�� ��� ����,[x][1]�� �ϰ� ����

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> datas[i];
	DP[0][0] = 0;
	DP[0][1] = 0;
	m_max = 0;
	for (int i = 1; i <= N; i++) {
		tempU = tempD = 0;
		for (int j = 1; j <= i; j++) {
			if (datas[i] > datas[i - j])//�񱳴�� ���� ũ�� ��±��̸� ���ؼ� �ε����� �����Ѵ�.
				tempU = DP[i - j][0] > DP[tempU][0] ? i - j : tempU ;
			if (datas[i] < datas[i - j])//������ ��±��� �ϰ����� �Ѵ� ���ؼ� �ε����� �����Ѵ�.
				tempD = Max(DP[i - j][1], DP[i - j][0]) > Max(DP[tempD][1],DP[tempD][0]) ? i - j : tempD ;
		}
		DP[i][0] = DP[tempU][0] + 1;
		DP[i][1] = Max(DP[tempD][0],DP[tempD][1]) + 1; //��±��� �ϰ����� ���� �� ���� �� ����.
		m_max = Max(m_max, Max(DP[i][0], DP[i][1]));
	}
	cout << m_max << "\n";
}