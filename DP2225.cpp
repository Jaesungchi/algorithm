#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2225 합분해
//규칙찾기가 힘들었다.

long N,A, DP[201][201];

int main() {
	cin >> N >> A;
	for (int i = 0; i <= N; i++)
		DP[1][i] = 1; //1개 뽑아서 i 가 나올 수는 1개뿐.
	for (int k = 2; k <= A; k++) //전거 자기 보다 낮은 수 다 더하면 됨.
		for (int n = 0; n <= N; n++) {
			for (int l = 0; l <= n; l++)
				DP[k][n] += DP[k - 1][l];
			DP[k][n] %= 1000000000;
		}
	cout << DP[A][N] << "\n";
}