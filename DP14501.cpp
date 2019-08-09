#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14501 퇴사
//백트래킹 DP로 해결.

int datas[16][2], N, DP[16], m_Max = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> datas[i][0] >> datas[i][1];
	for (int i = N - 1; i >= 0; i--) {
		if (datas[i][0] + i > N) //퇴사날을 넘어가면 패스
			DP[i] = DP[i + 1];
			//일 전부터 현재 DP의 차이와 오늘의 data를 비교한다.
		else if (datas[i][1] > DP[i + 1] - DP[i + datas[i][0]])
			DP[i] = DP[i + datas[i][0]] + datas[i][1];
		else
			DP[i] = DP[i + 1];
		m_Max = m_Max > DP[i] ? m_Max : DP[i];
	}
	cout << m_Max << "\n";
}