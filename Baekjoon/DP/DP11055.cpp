#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11055 ���� ū ���� �κ� ����
//11053���̶� �ʹ� ����ؼ� ���� ǰ

int N, m_max,temp, datas[1001], DP[1001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> datas[i];
	DP[0] = 0;
	DP[1] = datas[1];
	m_max = DP[1];
	for (int i = 2; i <= N; i++) {
		temp = 0;
		for (int j = 1; j < i; j++)
			if (datas[i] > datas[i - j])
				temp = DP[temp] > DP[i - j] ? temp : i - j;
		DP[i] = DP[temp] + datas[i];
		m_max = m_max > DP[i] ? m_max : DP[i];
	}
	cout << m_max;
}