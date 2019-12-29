#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11054 가장 긴 바이토닉 부분 수열
//비교 규칙 구하기

int N, tempU = 0,tempD = 0, m_max, datas[1001], DP[1001][2]; //DP[x][0]은 상승 길이,[x][1]은 하강 길이

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
			if (datas[i] > datas[i - j])//비교대상 보다 크면 상승길이만 비교해서 인덱스를 저장한다.
				tempU = DP[i - j][0] > DP[tempU][0] ? i - j : tempU ;
			if (datas[i] < datas[i - j])//작으면 상승길이 하강길이 둘다 비교해서 인덱스를 저장한다.
				tempD = Max(DP[i - j][1], DP[i - j][0]) > Max(DP[tempD][1],DP[tempD][0]) ? i - j : tempD ;
		}
		DP[i][0] = DP[tempU][0] + 1;
		DP[i][1] = Max(DP[tempD][0],DP[tempD][1]) + 1; //상승길이 하강길이 둘중 더 높은 값 저장.
		m_max = Max(m_max, Max(DP[i][0], DP[i][1]));
	}
	cout << m_max << "\n";
}