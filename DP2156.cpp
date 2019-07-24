#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2156 포도주 시식
//규칙을 찾아내기가 힘들었음. 딱 선례만 맞고 다른건 안맞는데
//다른거 찾는게 힘들었음.. 디버그 만만세

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
		if (dp[i - 1][1] == 1) { //전DP가 1잔째면 그냥 한번더 마신다.
			dp[i][0] = dp[i - 1][0] + datas[i];
			dp[i][1] = 2;
		}
		else { //전전 DP랑 전전전DP + 전data값 비교해서 더 높은 값을 넣는다. 
			dp[i][0] = Max(dp[i - 2][0], dp[i - 3][0] + datas[i - 1]) + datas[i];
			dp[i][1] = dp[i - 2][0] > dp[i - 3][0] + datas[i - 1] ? 1 : 2;
		}
		dp[i][0] = Max(M, dp[i][0]);
		M = dp[i][0];
	}
	cout << dp[N][0];
}