#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11057 오르막 수

int datas[1001][10];

int main() {
	int N,sums =0;
	cin >> N;
	for (int i = 0; i <= 9; i++)
		datas[1][i] = 1;
	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k >= 0; k--)
				datas[i][j] += datas[i - 1][k] % 10007;
		}
	for (int i = 0; i <= 9; i++)
		sums += datas[N][i] % 10007;
	cout << sums%10007;
}