#include <iostream>
#include <algorithm>
using namespace std;

//[꼬인 전깃줄 난이도★★★](https://www.acmicpc.net/problem/1365)

int N;
int maps[100001];
int DP[100001];

//LIS 를 구한뒤 N - LIS 를하면 되는 문제

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> maps[i];
	DP[1] = maps[1];
	int length = 1;
	for (int i = 2; i <= N; i++) {
		if (DP[length] < maps[i]) {
			DP[++length] = maps[i];
			continue;
		}
		//tmp는 maps[i]를 포함한 LIS를 구함.
		int tmp = lower_bound(DP + 1, DP + length + 1, maps[i]) - DP;
		DP[tmp] = maps[i];
	}
	cout << N - length << "\n";
}