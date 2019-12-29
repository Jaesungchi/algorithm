#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1912 연속합
//사례를 잘 생각해보자

int N,m_max, datas[100001], DP[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> datas[i];
	DP[0] = datas[0];
	m_max = DP[0];
	for (int i = 1; i < N; i++) {
		if (DP[i - 1] + datas[i] < 0 && DP[i - 1] > 0) //양수였다가 음수가 될떄
			DP[i] = 0;
		else if (DP[i - 1] > 0) //계속 양수 일때
			DP[i] = DP[i - 1] + datas[i];
		else //에초에 음수였을때
			DP[i] = datas[i];
		m_max = m_max > DP[i] ? m_max : DP[i];
	}
	cout << m_max << "\n";
}