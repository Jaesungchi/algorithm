#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11053 가장 긴 증가하는 부분 수열
//비교 할 때 자기보단 작지만 길이가 가장긴 친구 다음 수열로 넘어간다.

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