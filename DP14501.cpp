#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14501 ���
//��Ʈ��ŷ DP�� �ذ�.

int datas[16][2], N, DP[16], m_Max = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> datas[i][0] >> datas[i][1];
	for (int i = N - 1; i >= 0; i--) {
		if (datas[i][0] + i > N) //��糯�� �Ѿ�� �н�
			DP[i] = DP[i + 1];
			//�� ������ ���� DP�� ���̿� ������ data�� ���Ѵ�.
		else if (datas[i][1] > DP[i + 1] - DP[i + datas[i][0]])
			DP[i] = DP[i + datas[i][0]] + datas[i][1];
		else
			DP[i] = DP[i + 1];
		m_Max = m_Max > DP[i] ? m_Max : DP[i];
	}
	cout << m_Max << "\n";
}