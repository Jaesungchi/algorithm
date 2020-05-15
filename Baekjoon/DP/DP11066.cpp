#include <iostream>
using namespace std;

//[파일 합치기 난이도★★★](https://www.acmicpc.net/problem/11066)
/*
	Kruth's optimization를 사용했어야하는 문제.
	C[a][b]+ c[b][d] <= C[a][d] + C[b][c] (a<=b<=c<=d) 사각부등식
	C[b][c] <= C[a][d] 단조증가
	위 두조건을 만족하는 C배열에서
	dp[i][j] = min(i<k<j){dp[i][k] + db[k][j]}+C[i][j] 모양이면
	num[i][j-1] <= num[i][j] <= num[i+1][j]를 만족한다고 한다.
	이 식을 이용해서 엄청나게 최적화가 가능하다.
*/

int N;
int novel[501];
int psum[501];
int dp2[501][501];
int num[501][501];

void run() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> novel[i];
		psum[i] = psum[i - 1] + novel[i];
	}
	for (int i = 1; i <= N; i++)
		num[i - 1][i] = i;
	for (int d = 2; d <= N; d++) {
		for (int i = 0; i + d <= N; i++) {
			int j = i + d;
			dp2[i][j] = 987654321;
			for (int k = num[i][j - 1]; k <= num[i + 1][j]; k++) {
				int v = dp2[i][k] + dp2[k][j] + psum[j] - psum[i];
				if (dp2[i][j] > v) {
					dp2[i][j] = v;
					num[i][j] = k;
				}
			}
		}
	}
	cout << dp2[0][N] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		run();
	}
}