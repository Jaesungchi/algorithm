#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/10844 쉬운계단수
//규칙을 찾는데 애먹었다.

long long datas[101][11];

int main() {
	long long N,sums=0;
	cin >> N;
	for (int i = 1; i <= 9; i++)
		datas[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		datas[i][0] = datas[i - 1][1] % 1000000000;
		for (int j = 1; j < 9; j++)
			datas[i][j] = (datas[i - 1][j - 1] + datas[i - 1][j + 1])%1000000000;
		datas[i][9] = datas[i - 1][8] % 1000000000;
	}
	for (int i = 0; i <= 9; i++)
		sums += datas[N][i];
	cout << sums%1000000000;
}